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
    bool solve(TreeNode* root, int k, unordered_map<int, int> &mpp){
        if(!root) return false;
        if(mpp.find(k - root -> val) != mpp.end()) return true;
        mpp[root -> val] = 1;
        return solve(root -> left, k, mpp) || solve(root -> right, k, mpp);
    }
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int, int> mpp;
        return solve(root, k, mpp);
    }
};