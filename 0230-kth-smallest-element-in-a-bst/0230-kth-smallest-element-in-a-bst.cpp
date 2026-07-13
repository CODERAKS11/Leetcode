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
    bool inorder(TreeNode* root, int k, int &count, int &ans){
        if(!root) return false;
        inorder(root -> left, k, count, ans);
        count++;
        if(count == k){
            ans = root -> val;
            return true;
        }
        inorder(root -> right, k, count, ans);
        return false;
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans = -1;
        int count = 0;
        inorder(root, k, count, ans);
        return ans;
    }
};