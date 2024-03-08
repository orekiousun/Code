#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<queue>
#include<functional>

/*
    如何得到一个数据流中的中位数？
    如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。
    如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。

    建立一个 小顶堆 A 和 大顶堆 B ，各保存列表的一半元素，且规定：
    A 保存较大的一半，长度为 N/2 （N为偶数时），或(N + 1) / 2 （N为奇数时），A 的堆顶为较大的一半的最小值
    B 保存较小的一半，长度为 N/2 （N为偶数时），或(N - 1) / 2 （N为奇数时），B 的堆顶为较小的一半的最大值

    设元素总数为 N = m + n，其中 m 和 n 分别为 A 和 B 中的元素个数。

    addNum(num)：
        1.当 m = n 时，此时新加进来的数应该加入 A，先把此数加入 B，然后将 B 的堆顶加入 A 中
        2.当 m != n 时，此时新加进来的数应该加入 B，先把此数加入 A，然后将 A 的堆顶加入 B 中
    
    findMin()：
        1.当 m = n 时，返回 A 的堆顶和 B 的堆顶的和的平均值
        2.当 m != n 时，返回 A 的堆顶 
*/

class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int>> A;   // 小顶堆
    priority_queue<int, vector<int>, less<int>> B;      // 大顶堆
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        if(A.size() == B.size()) {
            B.push(num);
            int temp = B.top();
            A.push(temp);
            B.pop();
        }
        else {
            A.push(num);
            int temp = A.top();
            B.push(temp);
            A.pop();
        }
    }
    
    double findMedian() {
        if(A.size() == B.size()) {
            return (double)(A.top() + B.top()) / 2;
        }
        else {
            return A.top();
        }
    }
};

int main(int argc, char const *argv[]) {
    MedianFinder* operation = new MedianFinder();
    operation->addNum(1);
    cout << operation->findMedian() << endl;
    operation->addNum(2);
    cout << operation->findMedian() << endl;
    operation->addNum(3);
    cout << operation->findMedian() << endl;
    return 0;
}
