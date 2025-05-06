#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <numeric>

long long minimum(vector<int>& a) {
//    long long sum = accumulate(a.begin(), a.end(), 0);
    long long sum = 0;
    for(int i = 0; i < a.size(); i++) {
        sum += a[i];
    }

    int left = 0, right = 0;
    long long ret = LONG_LONG_MAX;
    long long curSum = 0;
    while (right < a.size()){
        curSum += a[right];
        long long curMinus = curSum - (sum - curSum);
        ret = min(ret, curMinus < 0 ? -curMinus : curMinus);
        while (curMinus > 0) {
            curSum -= a[left];
            left++;
            curMinus = curSum - (sum - curSum);
            ret = min(ret, curMinus < 0 ? -curMinus : curMinus);
        }
        right++;
    }

    return ret;
}

int main() {
    vector<int> a{1, 2, 3, 4, 5};
    cout << minimum(a) << endl;
    return 0;
}