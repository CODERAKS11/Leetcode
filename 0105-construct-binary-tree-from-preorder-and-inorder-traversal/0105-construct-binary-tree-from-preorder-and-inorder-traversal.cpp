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
    TreeNode* build(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, map<int, int> &inMap){
        if(inStart > inEnd || preStart > preEnd) return nullptr;
        TreeNode* node = new TreeNode(preorder[preStart]);
        int inRoot = inMap[node -> val];
        int leftCount = inRoot - inStart;

        node -> left = build(preorder, preStart + 1, preStart + leftCount, inorder, inStart, inRoot - 1, inMap);
        node -> right = build(preorder, preStart + leftCount + 1, preEnd, inorder, inRoot + 1, inEnd, inMap);
        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> inMap;

        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }

        return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inMap);
    }
};