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
    void dfs(TreeNode* root, int d, int &maxD){
        if(!root) return;
        maxD = max(maxD, d);
        if(root -> left) dfs(root -> left, d + 1, maxD);
        if(root -> right) dfs(root -> right, d + 1, maxD);
    }
    int maxDepth(TreeNode* root) {
        int maxD = 0;
        dfs(root, 1, maxD);
        return maxD;
    }
};