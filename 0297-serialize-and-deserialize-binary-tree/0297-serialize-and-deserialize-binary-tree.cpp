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
    void dfs(TreeNode* root,string &s)
    {
        if(root==NULL){
            s.push_back('*');
            return;
        }
        s.append(to_string(root->val)+",");
        dfs(root->left,s);
        dfs(root->right,s);
    }
    string serialize(TreeNode* root) {
        string s="";
        dfs(root,s);
        cout<<s;
        return s;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string &data) {
        if(data.size()==0){
            return NULL;
        }
        if(data[0]=='*'){
            data=data.substr(1);
            return NULL;
        }
        int i=0;
        string ans="";
        while(data[i]!=',')
        {
            ans+=data[i++];
        }
        TreeNode *curr=new TreeNode(stoi(ans));
        data=data.substr(i+1);
        curr->left=deserialize(data);
        curr->right=deserialize(data);
        return curr;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));