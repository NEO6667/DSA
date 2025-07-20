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
    TreeNode* createParentMapping(TreeNode* root, int start, map<TreeNode*, TreeNode*>& mpp){
        TreeNode* res = NULL;
        queue<TreeNode*> q;
        q.push(root);
        mpp[root] = NULL;
        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();
            if(front->val == start) res = front;

            if(front->left){
                mpp[front->left] = front;
                q.push(front->left);
            }

            if(front->right){
                mpp[front->right] = front;
                q.push(front->right);
            }
        }
        return res;
    }
    int burnTree(TreeNode* root, map<TreeNode*, TreeNode*> mpp){
        map<TreeNode*,bool> visited;
        queue<TreeNode*> q;
        q.push(root);
        visited[root] = 1;
        int ans = 0;
        while(!q.empty()){
            bool flag = 0;
            int size = q.size();
            for(int i=0; i<size; i++){
                TreeNode* front = q.front();
                q.pop();
                if(front->left && !visited[front->left]){
                    flag = 1;
                    q.push(front->left);
                    visited[front->left] = 1;
                }
                if(front->right && !visited[front->right]){
                    flag = 1;
                    q.push(front->right);
                    visited[front->right] = 1;
                }
                if(mpp[front] && !visited[mpp[front]]){
                    flag = 1;
                    q.push(mpp[front]);
                    visited[mpp[front]] = 1;
                }
            }
            if(flag == 1) ans++;
        }
        return ans;
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*, TreeNode*> nodeToParent;
        TreeNode* tarNode = createParentMapping(root, start, nodeToParent);
        int ans = burnTree(tarNode, nodeToParent);
        return ans;
    }
};