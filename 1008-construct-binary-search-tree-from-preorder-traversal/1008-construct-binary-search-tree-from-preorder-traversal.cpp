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
    
    TreeNode* build(vector<int>& preorder, int &s, int bound){
        if(s == preorder.size() || preorder[s] > bound) return nullptr;
        TreeNode* root = new TreeNode(preorder[s]);
        s++;
        root -> left = build(preorder, s, root -> val);
        root -> right = build(preorder, s, bound);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int s = 0;
        return build(preorder, s, INT_MAX);
    }
};