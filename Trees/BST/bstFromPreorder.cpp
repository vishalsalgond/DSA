//https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/submissions/


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
    int index = 0;
    TreeNode* bstFromPreorder(vector<int>& preorder, int parent_value = INT_MAX) {
        if(index == preorder.size() || preorder[index] > parent_value) {
            return NULL;
        }

        int current_value = preorder[index++];
        TreeNode *current_node = new TreeNode(current_value);

        current_node -> left = bstFromPreorder(preorder, current_value);
        current_node -> right = bstFromPreorder(preorder, parent_value);

        return current_node; 

    }
};
