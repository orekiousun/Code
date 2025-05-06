#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

#define max 0x7ffffffffffffff

long long minimum(vector<int>& a) {
    int size = a.size();
    long long sum = 0;
    for (auto item : a) {
        sum += item;
    }
    int half = sum / 2;
    int left = 0, right = 0;
    long long add = 0, ans = max;
    while (left < size) {
        if(add < half) {
            add += a[right];
            right = (right + 1) % size;
            ans = min(ans, ((sum - add * 2) > 0 ? (sum - add * 2) : (add * 2 - sum)));
        }
        else if(add > half) {
            add -= a[left];
            left++;
            ans = min(ans, ((sum - add * 2) > 0 ? (sum - add * 2) : (add * 2 - sum)));
        }
        else return (sum - add * 2) > 0 ? (sum - add * 2) : (add * 2 - sum);
    }
    return ans;
}

int main(int argc, const char** argv) {
    vector<int> a{7, 5, 3, 6, 4, 2, 1};
    cout << minimum(a) << endl;
    return 0;
}