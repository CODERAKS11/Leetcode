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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> ans;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while(!q.empty()){
            int size = q.size();
            vector<int> temp;
            int lvl;
            for(int i = 0; i < size; i++){
                TreeNode* node = q.front().first;
                lvl = q.front().second;
                temp.push_back(node -> val);
                q.pop();
                if(node -> left) q.push({node -> left, lvl + 1});
                if(node -> right) q.push({node -> right, lvl + 1});
            }
            if(lvl % 2 != 0) reverse(temp.begin(), temp.end());
            ans.push_back(temp);
        }
        return ans;
    }
};