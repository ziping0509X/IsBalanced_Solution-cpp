//剑指OFFER
//输入一棵二叉树，判断该二叉树是否是平衡二叉树。

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

int treedeepth(TreeNode* pRoot){
    if(pRoot==NULL)
        return 0;

    int nleft=treedeepth(pRoot->left);
    int nright=treedeepth(pRoot->right);

    if(nleft>nright)
        return nleft+1;

    if(nright>nleft)
        return nright+1;

}

class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if(pRoot==NULL)
            return true;

        int nleft=treedeepth(pRoot->left);
        int nright=treedeepth(pRoot->right);

        int diff=nleft-nright;
        if(diff>1||diff<-1){
            return false;
        }

        return IsBalanced_Solution(pRoot->left)&&IsBalanced_Solution(pRoot->right);

    }
};

//调试成功