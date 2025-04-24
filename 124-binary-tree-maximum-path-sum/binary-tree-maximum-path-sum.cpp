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

    pair<int,int> rec(TreeNode *root){
        if(root==NULL){
            return {INT_MIN,INT_MIN};
        }
        pair<int,int> left=rec(root->left);
        pair<int,int> right=rec(root->right);
        int a=root->val;
        if(left.second>0){
            a+=left.second;
        }
        if(right.second>0){
            a+=right.second;
        }
        int b=max(left.second,right.second);
        int ans=root->val;
        if(b>0){
            ans+=b;
        }
        return {max({left.first,right.first,a}),ans};
    }

    long int ans = INT_MIN;
    int solve(TreeNode* root){
        if(!root) return 0;

        long int l = solve(root->left);
        long int r = solve(root->right);

        // long int res = max({l + r, l, r, 0l});
        // if(res < 0){
        //     res = 0;
        // }
        ans = max({ans, l + r + root->val});

        return max(max(l, r) + root->val, 0l);
    }

    int maxPathSum(TreeNode* root) {
        // pair<int,int> ans =rec(root);
        solve(root);
        return ans;
    }
};