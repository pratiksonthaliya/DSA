/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
private:
    TreeNode* lca(TreeNode* root, TreeNode* a, TreeNode* b){
        if(!root || root->val == b->val || root->val == b->val) return root;

        if(root->val > b->val) return lca(root->left, a, b);
        else if(root->val < a->val) return lca(root->right, a, b);

        return root;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val > q->val) swap(p, q);
        return lca(root, p, q);
    }
};