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
private:
    vector<int> nodes;
    TreeNode* makeBST(int l, int r){
        if(l > r) return nullptr;   

        int m = (l+r)/2;
        TreeNode* node = new TreeNode(nodes[m]);

        node->left = makeBST(l, m-1);
        node->right = makeBST(m+1, r);
        return node;
    }
    void dfs(TreeNode* root){
        if(!root) return;

        dfs(root->left);
        nodes.push_back(root->val);
        dfs(root->right);
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        dfs(root);
        return makeBST(0, (int)nodes.size()-1);
    }
};