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
    vector<int> rightSideView(TreeNode* root) {
        if(root == nullptr) return {};
        vector<int> ans;
        queue<TreeNode*> q;
        int lastVal = root -> val;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if(temp == nullptr){
                ans.push_back(lastVal);
                if(!q.empty()) q.push(NULL);
            }
            else{
                lastVal = temp -> val;
                if(temp -> left) q.push(temp -> left);
                if(temp -> right) q.push(temp -> right);
            }
        }
        return ans;
    }
};