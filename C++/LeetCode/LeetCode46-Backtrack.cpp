#include<iostream>
using namespace std;
#include<vector>
#include<set>

class Tree
{
public:
    int val;
    vector<Tree*> son;
    Tree(int val)
    {
        this->val = val;
    }
};

bool isExist(vector<int> &v, int number)
{
    for (int i = 0; i < v.size(); i++)
    {
        if(v[i] == number) return true;
    }
    return false;
}

void genTree(Tree* root, vector<int> &nums, vector<int> &v, vector<vector<int>> &result)
{
    // 标记val值的结点已经被访问过
    v.push_back(root->val);

    for (int i = 0; i < nums.size(); i++)
    {
        if(!isExist(v, nums[i]))
        {
            Tree *temp = new Tree(nums[i]);
            root->son.push_back(temp);
        }
    }
    
    for(int i = 0; i < root->son.size(); i++)
    {
        genTree(root->son[i], nums, v, result);
    }

    if(root->son.size() == 0)
    {
        result.push_back(v);
    }

    v.pop_back();
}

void printVector(const vector<vector<int>> result)
{
    for (vector<vector<int>>::const_iterator it1 = result.begin(); it1 != result.end(); it1++)
    {
        cout << "{";
        for (vector<int>::const_iterator it2 = (*it1).begin(); it2 != (*it1).end(); it2++)
        {
            cout << *it2 << " ";
        }
        cout << "}";
    }
    cout << endl;
}

int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);

    vector<vector<int>> result;
    for (int i = 0; i < nums.size(); i++)
    {
        vector<int> v;
        Tree *root = new Tree(nums[i]); 
        genTree(root, nums, v, result);
    }
    
    printVector(result);

    system("pause");
    return 0;
}