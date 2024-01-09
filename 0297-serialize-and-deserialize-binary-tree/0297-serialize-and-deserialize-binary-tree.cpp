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

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        return serialize_helper(root);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        vector<string> tokens;

        while (getline(ss, data, ',')) {
            tokens.push_back(data);
        }

        int index = 0;
        return deserialize_helper(tokens, index);
    }
private:
    string serialize_helper(TreeNode* root) {
        if(root == nullptr) return "#";
        return to_string(root -> val) 
               + ","
               + serialize_helper(root -> left)
               + ","
               + serialize_helper(root -> right);
    }
    TreeNode* deserialize_helper(vector<string>& tokens, int& index) {
        if (index >= tokens.size() || tokens[index] == "#") {
            ++index;
            return nullptr;
        }

        TreeNode* root = new TreeNode(stoi(tokens[index++]));
        root->left = deserialize_helper(tokens, index);
        root->right = deserialize_helper(tokens, index);

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));