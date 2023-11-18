#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>


// 先使跟结点和与根节点交换的结点的左右孩子满足堆
// 让根节点的值在堆中逐级下降
void maxHeapIFY(vector<int>& nums, int rootIndex, int size)   
{
    int leftKidIndex = 2 * rootIndex + 1;
    int rightKidIndex = leftKidIndex + 1;
    int maxIndex = rootIndex;

    if(leftKidIndex < size && nums[maxIndex] < nums[leftKidIndex])
    {
        maxIndex = leftKidIndex;
    }
    if(rightKidIndex < size && nums[maxIndex] < nums[rightKidIndex] )
    {
        maxIndex = rightKidIndex;
    }
    if(maxIndex != rootIndex)
    {
        int temp = nums[maxIndex];
        nums[maxIndex] = nums[rootIndex];
        nums[rootIndex] = temp;
        if(maxIndex < size) 
            maxHeapIFY(nums, maxIndex, size);
    }
}

void buildMaxHeap(vector<int>& nums, int size)   // 创建堆
{
    for(int i = size / 2 - 1; i >= 0; i--)
    {
        maxHeapIFY(nums, i, size);
    }
}

void heapSort(vector<int>& nums)   // 堆排序
{
    int size = nums.size();
    buildMaxHeap(nums, size);
    for(int i = size - 1; i > 0; i--)
    {
        int temp = nums[0];
        nums[0] = nums[i];
        nums[i] = temp;
        size--;
        maxHeapIFY(nums, 0, size);
    }
}

// 优先队列
int heapExtractMax(vector<int>& heap)   // 剔除最大值
{
    int size = heap.size();
    if(size < 1) 
    {
        cout << "extract failed" << endl; 
        return -1;
    }
    int max = heap[0];
    heap[0] = heap[size - 1];
    heap.pop_back();
    maxHeapIFY(heap, 0, --size);
    return max;
}

void heapIncreaseKey(vector<int>& heap,int pos,int newValue)
{
    int size = heap.size();
    if(pos >= heap.size())
    {
        cout << "pos overflow" << endl;
        return;
    } 
    else if(newValue < heap[pos])
    {
        cout << "can't decrease the value" << endl;
        return;
    }
    heap[pos] = newValue;
    while (pos > 0 && heap[(pos + 1) / 2 - 1] < heap[pos])
    {
        int temp = heap[(pos + 1) / 2 - 1];
        heap[(pos + 1) / 2 - 1] = heap[pos];
        heap[pos] = temp;
        pos = (pos + 1) / 2 - 1;
    }
}
void maxHeapInsert(vector<int>& heap, int insertNumber)
{
    int size = heap.size();
    heap.push_back(insertNumber - 1);
    heapIncreaseKey(heap, size, insertNumber);
}

void printVector(const vector<int>& v)
{
    for (vector<int>::const_iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;   
}



int main()
{
    vector<int> nums{1,2,3,4,5,6,7,8,9};
    vector<int> nums2 = nums;
    make_heap(nums2.begin(), nums2.end());
    int size = nums.size();
    int rootIndex = 0;

    cout << "original heap: " << endl;
    printVector(nums);
    
    cout << "make heap: " << endl;
    buildMaxHeap(nums, size);
    printVector(nums);

    cout << "heap sort: " << endl;
    heapSort(nums);
    printVector(nums);

    cout << "make-heap stl: " << endl;
    printVector(nums2);

    cout << "heap extract max: " << endl;
    cout << "heap max is: " << heapExtractMax(nums2) << endl;
    cout << "new heap is: ";
    printVector(nums2); 

    cout << "heap increase key: " << endl;
    heapIncreaseKey(nums2, 3, 10);
    printVector(nums2);

    cout << "max heap insert: " << endl;
    maxHeapInsert(nums2, 4);
    printVector(nums2);

    system("pause");
    return 0;
}