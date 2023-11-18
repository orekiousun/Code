#include<iostream>
using namespace std;
#include<vector>

/*
    输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。如果是则返回 true，否则返回 false。
    假设输入的数组的任意两个数字都互不相同。
        5
       / \
      2   6
     / \
    1   3

    思路：采用分治的方法，后序遍历最后一个节点一定为根节点
*/

bool verifyPostorder(vector<int>& postorder, int begin, int end) {
    if (end - begin <= 1) return true;
    int root = postorder[end];
    int pos = -1;
    for (int i = begin; i < end; i++) {
        if (postorder[i] > root && pos == -1)
            pos = i;
        if(pos != -1 && postorder[i] < root) 
            return false;
    }
    if (pos == -1) return verifyPostorder(postorder, begin, end - 1);
    return verifyPostorder(postorder, begin, pos - 1) && verifyPostorder(postorder, pos, end - 1);
}

bool verifyPostorder(vector<int>& postorder) {
    return verifyPostorder(postorder, 0, postorder.size() - 1);
}

int main(int argc, char const *argv[]) {
    vector<int> v1{5, 2, -17, -11, 25, 76, 62, 98, 92, 61};
    cout << verifyPostorder(v1) << endl;
    return 0;
}