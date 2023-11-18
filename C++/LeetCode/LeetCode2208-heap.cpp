#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<numeric>

/*
    make_heap(_RAIter,_RAIter,_Compare) 在容器范围内，就地建堆，保证最大值/最小值在所给容器的的front位置，其他值的位置不确定
    pop_heap(_RAIter,_RAIter,_Compare) 将堆顶(容器的front位置)元素移动到所给范围的最后(容器的back位置)，并且将新的最大值置于所给范围的最前面(容器的front位置)
    push_heap(_RAIter,_RAIter,_Compare) 当已建堆的容器范围内有新的元素插入末尾后，应当调用push_heap将该元素插入堆中(即当前容器中在建堆之后可能删除或者插入了心得元素，将没有被算入堆中的元素重新放入堆中，并重构堆顶)
    _Compare有两种参数，一种是greater（生成小顶堆），一种是less（生成大顶堆）
    例如：pop_heap(nums.begin(), nums.end(),greater<int>())  --  使用内建函数对象
*/

int main()
{
    vector<int> nums;
    nums.push_back(5);
    nums.push_back(19);
    nums.push_back(8);
    nums.push_back(1);

    int size = nums.size();    
    // accumulate需要#include<numeric>
    float total = accumulate(nums.begin(), nums.end(), 0.0) , countNums = 0;
    int count = 0;
    vector<float> newNums(nums.begin(), nums.end());

    // make_heap()是生成一个堆，大顶堆或小顶堆，默认为大顶堆
    make_heap(newNums.begin(), newNums.end());
    
    while (countNums < total / 2)
    {
        // pop_heap()是在堆的基础上，弹出堆顶元素，它会将堆顶元素（即为数组第一个位置）和数组最后一个位置对调
        // 即将堆顶元素弹出，将他的位置和容器的最后一个位置对调，这时容器中的最后一个位置便不属于堆
        pop_heap(newNums.begin(), newNums.end());
        float temp = newNums.back() / 2;
        newNums.back() = temp;
        countNums += temp;
        
        // push_heap()是向堆中插入一个元素（该元素即为当前容器中最后一个元素），并且使堆的规则依然成立
        push_heap(newNums.begin(), newNums.end());
        count ++;
    }
    
    cout << count << endl;
    

    system("pause");
    return 0;
}