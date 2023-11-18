#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

class MyCompare
{
public:
// 传引用节省空间
    bool operator()(vector<int> &v1, vector<int> &v2)
    {
        if(v1[0] == v2[0])
            return v1[1] > v2[1];
        else
            return v1[0] < v2[0];
    }
};


void printVector(const vector<vector<int>> v)
{
    for (vector<vector<int>>::const_iterator it = v.begin(); it != v.end(); it++)
    {
        cout << "[" << (*it).at(0) << "," << (*it)[1] << "]" << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);

    vector<int> v2;
    v2.push_back(1);
    v2.push_back(4);

    vector<int> v3;
    v3.push_back(3);
    v3.push_back(4);

    vector<vector<int>> v;
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);

    sort(v.begin(), v.end(), MyCompare());

    printVector(v);
    int result = v.size();
    int rmax = v[0][1];

    for (int i = 1; i < v.size(); i++)
    {
        if(v[i][1] > rmax)
        {
            rmax = v[i][1];
        }
        else
        {
            result--;
        }
    }
    
    cout << result << endl;

    system("pause");
    return 0;
}