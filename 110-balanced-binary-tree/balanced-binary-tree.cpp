/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
         return (checkheight(root)!=-1);
    } 
    int checkheight(TreeNode* root){
        if(root==nullptr) return 0;
        int le=checkheight(root->left);
        if(le==-1) return -1;
        int re=checkheight(root->right);
        if(re==-1) return -1;
        if(abs(le-re)>1) return -1;
        return 1+max(le,re);
    }
};