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
        return solve(root).first;
        
    }
    pair<bool,int> solve(TreeNode* root){
        if(root==NULL){
            pair<bool,int> p=make_pair(true,0);
            return p;
        }

        pair<int,int> left=solve(root->left);
        pair<int,int> right=solve(root->right);

        bool leftAns=left.first;
        bool rightAns=right.first;

        int diff = abs(left.second - right.second) <= 1;
        pair<bool,int> ans;
        ans.second = max(left.second , right.second) + 1;
        if(leftAns && rightAns && diff){
            ans.first=true;
        }
        else{
            ans.first=false;
        }
        return ans;
    }
};