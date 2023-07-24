/*
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

    static const int N = 505;

    vector < int > g[N];
    vector < int > d;

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        build(root);
        queue < int > q;
        d.assign(N , (int) 1e9);
        q.push(target->val);
        d[target->val] = 0;
        vector < int > ret;
        while(!q.empty()){
            int u = q.front();
            if(d[u] == k) ret.push_back(u);
            q.pop();
            for(auto v : g[u]){
                if(d[u] + 1 < d[v]){
                    d[v] = d[u] + 1;
                    q.push(v);
                }
            }
        }
        return ret;
    }

    void build(TreeNode* root){
        if(root->left != NULL){
            g[root->val].push_back(root->left->val);
            g[root->left->val].push_back(root->val);
            build(root->left);
        }
        if(root->right != NULL){
            g[root->val].push_back(root->right->val);
            g[root->right->val].push_back(root->val);
            build(root->right);
        }
    }
};
