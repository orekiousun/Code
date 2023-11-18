#include<iostream>
using namespace std;
#include<vector>

#define RED true
#define BLACK false

class RBTreeNode
{
public:
    int val;
    RBTreeNode* parent;
    RBTreeNode* left;
    RBTreeNode* right;
    bool color;
    RBTreeNode(int val)
    {
        this->val = val;
    }
};

class RBTree
{
public:
    // 根节点
    RBTreeNode* root;
    // 哨兵结点
    RBTreeNode* nil;
    RBTree()
    {
        nil = new RBTreeNode(-1);
        nil->color = BLACK;
        root = nil;
        root->color = BLACK;
`       root->left = nil;
        root->right = nil;
        root->parent = nil;
    }
    RBTree(RBTreeNode *root)
    {
        this->root = root;
        root->color = BLACK;
        this->nil = new RBTreeNode(-1);
        nil->color = BLACK;
        // 将根节点的父亲和左右孩子设置为哨兵
        root->parent = nil;
        root->left = nil;
        root->right = nil;
    }
};

// 左旋（逆时针旋转）
void leftRotate(RBTree* tree, RBTreeNode* x)
{
    RBTreeNode* y = x->right;
    x->right = y->left;
    if(y->left != NULL)
    {
        y->left->parent = x;
    }
    y->parent = x->parent;
    if(x->parent == tree->nil)
    {
        tree->root = y;
    }    
    else if(x = x->parent->left)
    {
        x->parent->left = y;
    }
    else
    {
        x->parent->right = y;
    } 
    y->left = x;
    x->parent = y;
}

// 右旋（顺时针旋转）
void rightRotate(RBTree* tree, RBTreeNode* x)
{
    RBTreeNode* y = x->left;
    x->left = y->right;
    if(y->right != NULL)
    {
        y->right->parent = x;
    }
    y->parent = x->parent;
    if(x->parent == tree->nil)
    {
        tree->root = y;
    }
    else if(x = x->parent->left)
    {
        x->parent->left = y;
    }
    else
    {
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
}

// 插入后修复
void insertRBTreeFixedUp(RBTree* tree, RBTreeNode* x)
{
    while (x != NULL && x != tree->root && x->parent->color == RED)
    {
        // 父亲是祖父的左儿子
        if(x->parent = x->parent->parent->left)
        {
            RBTreeNode* uncle = x->parent->parent->right;
            /*
                情况一：父亲和叔叔均为红色
                （1）将父亲和叔叔改成黑色，以满足红黑规则4
                （2）父亲和叔叔变成黑色了，黑色高度变化，需要将祖父变成红色，以满足红黑规则5
                （3）从祖父开始，继续调整
            */
            if(uncle->color == RED)
            {
                uncle->color == BLACK;
                x->parent->color == BLACK;
                uncle->parent->color = RED;
                x = uncle->parent;
            }
            else
            {
                /*
                    情况三：父亲为祖父的左儿子，叔叔为黑色，自己是父亲的右儿子
                    （1）父亲成为新的x，对父亲进行左旋操作，构造情况二的初始状态
                    （2）按照情况二，对新的x（原父亲）进行处理
                */
                if(x == x->parent->right)
                {
                    x = x->parent;
                    leftRotate(tree, x);
                }
                /*
                    情况二：父亲为祖父的左儿子，叔叔为黑色，自己是父亲的左儿子
                    （1）父亲变成黑色，祖父变成红色（右子树的黑色高度变低）
                    （2）对祖父进行右旋，让父节点成为新的祖父，以恢复右子树的黑色高度
                    （3）不满足循环条件，退出循环
                */
                x->parent->color = BLACK;
                uncle->parent->color = RED;
                rightRotate(tree, uncle->parent);
            }
        }
        // 父亲是祖父的右儿子 -- 镜像操作
        else if(x->parent = x->parent->parent->right)
        {
            RBTreeNode* uncle = x->parent->parent->left;
            if(uncle->color == RED)
            {
                uncle->color = BLACK;
                x->parent->color = BLACK;
                uncle->parent->color = RED;
                x = uncle->parent;
            }
            else
            {
                if(x == x->parent->left)
                {
                    x = x->parent;
                    rightRotate(tree, x);
                }
                x->parent->color = BLACK;
                uncle->parent->color = RED;
                leftRotate(tree, uncle->parent);
            }
        }
    }
    tree->root->color = BLACK;
}

// 插入
void insertRBTree(RBTree* tree, RBTreeNode* newNum)
{
    RBTreeNode* x = tree->root;
    RBTreeNode* y = tree->nil;
    while (x != tree->nil)
    {   
        y = x;
        if(newNum->val < x->val)
            x = x->left;
        else
            x = x->right;
    }
    newNum->parent = y;
    if(y == tree->nil)
        tree->root = newNum;
    else if(newNum->val < y->val)
        y->left = newNum;
    else
        y->right = newNum;
    newNum->left = tree->nil;
    newNum->right = tree->nil;
    newNum->color = RED;
    insertRBTreeFixedUp(tree, newNum);
}

void transplantRBTree(RBTree* tree, RBTreeNode* u, RBTreeNode* v)
{
    // 将u的位置用v替换，而u如何让不在乎
    if(u->parent == tree->nil)   // 说明u为根节点
    {
        tree->root = v;
    }
    else if(u == u->parent->left)
    {
        u->parent->left = v;
    }
    else
    {
        u->parent->right = v;
    }
    v->parent = u->parent;
}

RBTreeNode* getRBTreeMin(RBTree* tree)
{
    RBTreeNode* root = tree->root;
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

void deleteRBTreeFixedUp(RBTree* tree, RBTreeNode* x)
{
    while (x != tree->root && x->color == BLACK)
    {
        if(x == x->parent->left)
        {
            RBTreeNode* brother = x->parent->right;
            // 情况1：兄弟为红色（此时父亲一定为黑色）
            if (brother->color == RED)
            {
                x->parent->color = RED;
                brother->color = BLACK;
                leftRotate(tree, x->parent);
                brother = x->parent->right;   // 重新设置brother，不用进入下一次循环，继续执行接下来的判断
                // 未降低高度，将进入情况234继续进行调整
            }
            // 情况2：兄弟为黑色，左右侄子也是黑色
            if(brother->left->color == BLACK && brother->right->color == BLACK)
            {
                brother->color = RED;
                x = x->parent;
                // 降低右子树黑高，重新执行循环继续调整
            }
            else
            {
                // 情况3：兄弟为黑色，右侄子为黑色
                if(brother->right->color == BLACK)
                {
                    brother->left->color = BLACK;
                    brother->color = RED;
                    rightRotate(tree, brother);
                    // 未降低黑高，将进入情况4继续调整
                    brother = x->parent->right;
                }
                // 情况4：兄弟为黑色，右侄子为红色
                brother->color = x->parent->color;
                x->parent->color = BLACK;
                brother->right->color = BLACK;
                leftRotate(tree, x->parent);
                x = tree->root;
                // 增加左子树黑高，直接退出循环
            }
        }
        else if(x == x->parent->right)
        {
            RBTreeNode* brother = x->parent->left;
            // 情况1：兄弟为红色（此时父亲一定为黑色）
            if (brother->color == RED)
            {
                x->parent->color = RED;
                brother->color = BLACK;
                rightRotate(tree, x->parent);
                brother = x->parent->left;   // 重新设置brother，不用进入下一次循环，继续执行接下来的判断
                // 未降低高度，将进入情况234继续进行调整
            }
            // 情况2：兄弟为黑色，左右侄子也是黑色
            if(brother->left->color == BLACK && brother->right->color == BLACK)
            {
                brother->color = RED;
                x = x->parent;
                // 降低左子树黑高，重新执行循环继续调整
            }
            else
            {
                // 情况3：兄弟为黑色，左侄子为黑色
                if(brother->left->color == BLACK)
                {
                    brother->right->color = BLACK;
                    brother->color = RED;
                    leftRotate(tree, brother);
                    // 未降低黑高，将进入情况4继续调整
                    brother = x->parent->left;
                }
                // 情况4：兄弟为黑色，左侄子为红色
                brother->color = x->parent->color;
                x->parent->color = BLACK;
                brother->left->color = BLACK;
                rightRotate(tree, x->parent);
                x = tree->root;
                // 增加左子树黑高，直接退出循环
            }
        }
    }
    x->color = BLACK;   // 根节点一定为黑色
}

// 删除
void deleteRBTreeNode(RBTree* tree, RBTreeNode* delNode)
{
    bool originalColor = delNode->color;
    RBTreeNode* x;
    if(delNode->left == tree->nil)
    {
        x = delNode->right;
        transplantRBTree(tree, delNode, delNode->right);
    }
    else if(delNode->right == tree->nil)
    {
        x = delNode->left;
        transplantRBTree(tree, delNode, delNode->left);
    }
    else
    {
        RBTreeNode* y = getRBTreeMin(delNode->right);
        originalColor = y->color;
        x = y->right;
        if (y->parent = delNode)
        {
            x->parent = y;
        }
        else 
        {
            transplantRBTree(tree, y, y->right);
            y->right = delNode->right;
            y->right->parent = y;
        }

        transplantRBTree(tree, delNode, y);
        y->left = delNode->left;
        y->left->parent = y;
        y->color = delNode->color;
    }
    if(originalColor == BLACK)   // 如果移除掉的结点是一个黑结点，则红黑树平衡被破坏，需要重构
    {
        deleteRBTreeFixedUp(tree, x);
        // 无论如何，一定是x的一侧黑高少1
    }
}

int main()
{
    RBTreeNode* root = new RBTreeNode(7);
    RBTree* rbTree = new RBTree(root);
    system("pause");
    return 0;
}