//https://leetcode.com/problems/binary-tree-inorder-traversal/


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
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int> ans;

        if(!root) return ans;

        stack<TreeNode*> stk;

        while(root || !stk.empty()) {
            
            //go to left as much as possible
            while(root) {
                stk.push(root);
                root = root -> left;
            }

            //remove top node and goto right now
            root = stk.top();
            stk.pop();
            ans.push_back(root -> val);
            root = root -> right;
        }

        return ans;
    }
};
