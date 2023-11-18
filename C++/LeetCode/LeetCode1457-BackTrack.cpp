#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<queue>

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 我的做法  --  超时
int JudgePalindrome(string str)
{
    int count[10] = {0};
    for (int i = 0; i < str.size(); i++)
    {
        switch (str[i])
        {
        case '1':
            count[0]++;
            break;
        case '2':
            count[1]++;
            break;
        case '3':
            count[2]++;
            break;
        case '4':
            count[3]++;
            break;
        case '5':
            count[4]++;
            break;
        case '6':
            count[5]++;
            break;
        case '7':
            count[6]++;
            break;
        case '8':
            count[7]++;
            break;
        default:
            count[8]++;
            break;
        }
    }
    for (int i = 0; i < 9; i++)
    {
        if(count[i] % 2 == 1)
        count[9]++;
    }
    if(count[9] <= 1 ) return 1;
    else return 0;
}

int GetPalindrome(vector<int> &v)
{
    if(v.size() == 1) return 1;
    int result = 0;
    string temp;
    int j;
    for (int i = v.size() - 1; i >= 0; i--)
    {
        if(v[i] != 0)
        {
            if( (i+1)*2 > v.size() || ( v[2*(i+1)-1] == 0 && v[2*(i+1)] == 0 ))
            {
                temp = "";
                j = i + 1;
                while (j >= 1)
                {
                    if(v[j-1] != 0)
                    {
                        temp += to_string(v[j-1]);
                    }
                    j = j / 2;
                }
                result += JudgePalindrome(temp);
            }
        }
    }
    return result;
}

// 前序遍历
void FrontFind(TreeNode* root, vector<int> &v)
{
    v.push_back(root->val);
    if(root->left == NULL && root->right == NULL)
        return;
    if(root->left != NULL) 
        FrontFind(root->left, v);
    if(root->right != NULL) 
        FrontFind(root->right, v);
}

void GetLength(TreeNode* root, int &result)
{
    result++;
    if(root->left == NULL && root->right == NULL)
        return;
    if(root->left != NULL) 
        GetLength(root->left, result);
    if(root->right != NULL) 
        GetLength(root->right, result);
}

// 层序遍历完全二叉树  --  利用队列
void LevelFind(TreeNode* root, int &count, vector<int> &v)
{
    queue<TreeNode*> l;
    l.push(root);
    for(int i = 0; i < count; )
    {
        TreeNode* temp = l.front();
        if(temp->val != 0) i++;
        if(temp->left == NULL)
        {
            TreeNode* left = new TreeNode(0);
            temp -> left = left;
        }
        l.push(temp->left);
        if(temp->right == NULL)
        {
            TreeNode* right = new TreeNode(0);
            temp -> right = right;
        }
        l.push(temp->right);
        v.push_back(temp->val);
        l.pop();
    }
}

void PrintVector(const vector<int> &v)
{
    for(vector<int>::const_iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

// 大佬做法
class Solution {
public:
    int check(int *cnt) 
    {
        int odd = 0;
        for(int i = 0; i <= 9; i++) 
        {
            if(cnt[i]&1)  // &按位与  --  判断奇偶
            {
                odd++;
            }
        }
        // 如果总数为偶数，只要出现1个奇数，就一定会出现第2个奇数
        // 所以最终判定奇数个数小于等于1即可
        if(odd <= 1) 
        {
            return 1;
        }
        return 0;
    }

    int dfs(TreeNode *root, int *cnt) 
    {
        if(root == nullptr) 
        {
            return 0;
        }

        cnt[root->val] ++;
        // 如果左右孩子均为空，则到达根节点，执行返回
        if(root->left == nullptr && root->right == nullptr) 
        {
            int anw = check(cnt);
            cnt[root->val]--;
            return anw;
        }
        // 每次加入最后一个数字后检测，检测完之后扔掉

        int anw = 0;
        if(root->left != nullptr) 
        {
            anw += dfs(root->left, cnt);
        }
        if(root->right != nullptr) 
        {
            anw += dfs(root->right, cnt);
        }
        cnt[root->val] --;
        return anw;
    }

    int pseudoPalindromicPaths (TreeNode* root) 
    {
        int cnt[10] = {0};
        return dfs(root, cnt);
    }
};

int main()
{
    TreeNode* third1 = new TreeNode(3);
    TreeNode* third2 = new TreeNode(1);
    TreeNode* third3 = new TreeNode(1);
    TreeNode* second1 = new TreeNode(3, third1, third2);
    TreeNode* second2 = new TreeNode(1, NULL, third3);
    TreeNode* first = new TreeNode(2, second1, second2);

    vector<int> v;
    int count = 0;
    GetLength(first, count);
    LevelFind(first, count, v);
    PrintVector(v);
    cout << GetPalindrome(v) << endl;
    system("pause");
    return 0;
}