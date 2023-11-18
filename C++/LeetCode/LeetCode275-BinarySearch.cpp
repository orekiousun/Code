#include<iostream>
using namespace std;
#include<vector>


int find(vector<int>& citations, int begin, int end)
{
    int mid = (begin + end) / 2;
    int result = citations.size() - mid;

    if(mid - 1 < 0 && citations[mid] >= result)
        return result;
    else if(citations[mid] >= result && citations[mid -1 ] <= result)
        return result;
    else if(mid + 1 == citations.size())
        return 0;

    if(citations[mid] <= result)
    {
        result = find(citations, mid + 1, end);
    }
    else if(citations[mid] >= result)
    {
        result = find(citations, begin, mid);
    }

    return result;
}

// 官方方法 -- 不用递归
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (citations[mid] >= n - mid) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return n - left;
    }
};


int main()
{
    vector<int> citations; 
    citations.push_back(0); 


    citations.push_back(0);  

    cout << find(citations, 0, citations.size() - 1) << endl; 

    system("pause");
    return 0;
}