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
int ans=0;
pair<int,int> solve(TreeNode*root){
    if(root==NULL){
        return {0,0};
    }
    pair<int,int>left=solve(root->left);
    pair<int,int>right=solve(root->right);

   int sum=root->val+left.first+right.first;
    int cnt=1+left.second+right.second;
    if((sum/cnt==root->val))ans++;
    return {sum,cnt};
}
    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return ans;
    }
};