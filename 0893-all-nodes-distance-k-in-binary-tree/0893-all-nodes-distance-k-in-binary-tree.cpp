/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*,TreeNode*> mp;
    void solve(TreeNode* root)
    {
        if(!root) return;
        if(root->left){
            mp[root->left]=root;
        }
        solve(root->left);
        if(root->right){
            mp[root->right]=root;
        }
        solve(root->right);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        solve(root);
        queue<TreeNode*> q;
        q.push(target);
        int level=0;
        unordered_set<TreeNode*> vis;
        vis.insert(target);
        while(!q.empty())
        {
            int size=q.size();
            if(level==k){
                break;
            }
            while(size--)
            {
                TreeNode* node=q.front();
                q.pop();
                if(node->left&&vis.count(node->left)==0){
                    q.push(node->left);
                    vis.insert(node->left);
                }
                if(node->right&&vis.count(node->right)==0){
                    q.push(node->right);
                    vis.insert(node->right);
                }
                if(mp.find(node)!=mp.end()&&vis.count(mp[node])==0){
                    q.push(mp[node]);
                    vis.insert(mp[node]);
                }
            }
            level++;
        }
        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};