//https://leetcode.com/problems/serialize-and-deserialize-bst


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    string serialized;
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        serialize_helper(root);
        return serialized;
    }

    void serialize_helper(TreeNode* root) {
        if(!root) {
            serialized += "X,";
            return;
        }
        serialized += to_string(root -> val) + ",";
        serialize_helper(root -> left);
        serialize_helper(root -> right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

        queue <string> Q;
        int i = 0, n = data.length();
    
        while(i < n) {
            string curr;
            while(i < n && data[i] != ',') {
                curr += data[i];
                i++;
            }
            i++;
            if(curr.length() > 0) {
                Q.push(curr);
            }
        }

        return deserialize_helper(Q);
        
    }

    TreeNode* deserialize_helper(queue <string> &Q) {

      
        string curr = Q.front();
        Q.pop();
        
        if(curr == "X") 
            return NULL;
        
        TreeNode *node = new TreeNode(stoi(curr));

        node -> left = deserialize_helper(Q);
        node -> right = deserialize_helper(Q);

        return node;
        
        

    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
