#include<iostream>
using namespace std;
#include<vector>

/*
    求旋转数组的里面的最小数
    从递增数组里找到没有递增的点，返回第一个下降点即可
*/

int minArray(vector<int>& numbers) {
    for (int i = 1; i < numbers.size(); i++) {
        if(numbers[i - 1] > numbers[i])
            return numbers[i];
    }
    return numbers[0];
}

int main(int argc, char const *argv[]) {
    vector<int> nums{3, 4, 5, 1, 2};
    cout << minArray(nums) << endl;
    return 0;
}
