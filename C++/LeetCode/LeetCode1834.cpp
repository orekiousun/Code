#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

class Mycompare
{
public:
    bool operator()(vector<int> v1, vector<int> v2)
    {
        return v1[0] < v2[0];
    }
};

int main()
{
    vector<vector<int>> tasks;
    vector<int> t1;
    t1.push_back(1);
    t1.push_back(2);

    vector<int> t2;
    t2.push_back(2);
    t2.push_back(4);

    vector<int> t3;
    t3.push_back(3);
    t3.push_back(2);

    vector<int> t4;
    t4.push_back(4);
    t4.push_back(1);

    tasks.push_back(t1);
    tasks.push_back(t2);
    tasks.push_back(t3);
    tasks.push_back(t4);

    vector<int> result;
    int startTime = 1000000000;
    for (int i = 0; i < tasks.size(); i++)
    {
        tasks[i].push_back(i);
        if(tasks[i][0] < startTime)
        {
            startTime = tasks[i][0];
        }
    }
    sort(tasks.begin(), tasks.end(), Mycompare());

    int size = tasks.size();
    while (result.size() < size)
    {
        // 记录最小执行时间和需要执行的迭代器  
        int minProcessTime = 1000000000;   // 13
        vector<vector<int>>::iterator minIterator;
        vector<vector<int>>::iterator it = tasks.begin();
        while (it != tasks.end() && (*it)[0] <= startTime)
        {
            if((*it)[1] < minProcessTime)
            {
                minProcessTime = (*it)[1];
                minIterator = it; 
            }
            else if ((*it)[1] == minProcessTime && (*it)[2] < (*minIterator)[2])
            {
                minProcessTime = (*it)[1];
                minIterator = it; 
            }
            it++;
        }

        // 存入结果中并删除
        if(minProcessTime == 1000000000)
        {
            startTime = (*it)[0];
            while ((*it)[0] == startTime)
            {
                if((*it)[1] < minProcessTime)
                {
                    minIterator = it;
                    minProcessTime = (*it)[1];
                }
                else if ((*it)[1] == minProcessTime && (*it)[2] < (*minIterator)[2])
                {
                    minProcessTime = (*it)[1];
                    minIterator = it; 
                }
                it++;
            }
        }
        else
        {
            startTime += minProcessTime;
        }
        result.push_back((*minIterator)[2]);
        tasks.erase(minIterator);
    }
    
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
    

    system("pause");
    return 0;
}

// 以上解法超时

class Solution {
private:
    using PII = pair<int, int>;
    using LL = long long;

public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        vector<int> indices(n);
        iota(indices.begin(), indices.end(), 0);   // 将迭代器范围内所有值赋值为0
        sort(indices.begin(), indices.end(), [&](int i, int j) {
            return tasks[i][0] < tasks[j][0];
        });

        vector<int> ans;
        // 优先队列
        priority_queue<PII, vector<PII>, greater<PII>> q;
        // 时间戳
        LL timestamp = 0;
        // 数组上遍历的指针
        int ptr = 0;
        
        for (int i = 0; i < n; ++i) {
            // 如果没有可以执行的任务，直接快进
            if (q.empty()) {
                timestamp = max(timestamp, (LL)tasks[indices[ptr]][0]);
            }
            // 将所有小于等于时间戳的任务放入优先队列
            while (ptr < n && tasks[indices[ptr]][0] <= timestamp) {
                q.emplace(tasks[indices[ptr]][1], indices[ptr]);
                ++ptr;
            }
            // 选择处理时间最小的任务
            auto&& [process, index] = q.top();
            timestamp += process;
            ans.push_back(index);
            q.pop();
        }
        
        return ans;
    }
};
