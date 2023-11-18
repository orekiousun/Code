#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

/*
    堆
    1.make_heap(_RAIter,_RAIter,_Compare) 
        在容器范围内，就地建堆，保证最大值/最小值在所给容器的的front位置，其他值的位置不确定
    2.pop_heap(_RAIter,_RAIter,_Compare) 
        将堆顶(容器的front位置)元素移动到所给范围的最后(容器的back位置)，并且将新的最大值置于所给范围的最前面(容器的front位置)
    3.push_heap(_RAIter,_RAIter,_Compare) 
        当已建堆的容器范围内有新的元素插入末尾后，应当调用push_heap将该元素插入堆中(只会将最后一个元素(即back位置)放入堆中)
    _Compare有两种参数，一种是greater（生成小顶堆），一种是less（生成大顶堆）
    例如：pop_heap(nums.begin(), nums.end(),greater<int>())  --  使用内建函数对象
*/

void printVector(vector<int> &v)
{
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;   
}
int main() 
{
    vector<int> nums = {4, 5, 1, 3, 2};
    // make_heap
    make_heap(nums.begin(), nums.end());
    cout << "initial max value : " << nums.front() << endl;
    printVector(nums);

    // pop_heap
    pop_heap(nums.begin(), nums.end());
    cout << "after pop, the max vsalue : " << nums.front() << endl;
    // 从输出结果发现将原来的最大值5放到了最后一个位置，并将新的最大值放到了最前
    printVector(nums);

    // 再次将4放到最后之后，5又会被当作堆的最大值被放到最前
    pop_heap(nums.begin(), nums.end());
    printVector(nums);

    // push_heap
    nums.push_back(8);
    nums.push_back(6);
    nums.push_back(7);   // 说明只会将back位置放入堆中
    push_heap(nums.begin(), nums.end());
    cout << "after push, the max value : " << nums.front() << endl;
    printVector(nums);

    // 重新构建堆之后，发现最大值8被放入了最前的位置
    make_heap(nums.begin(), nums.end());
    printVector(nums);

    system("pause");
    return 0;
}