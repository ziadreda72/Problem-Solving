class Solution {
public:
    int ans = 0;
    
    int longestZigZag(TreeNode* root) {
        dfs(root , 0 , 0);
        return ans;
    }
    
    void dfs(TreeNode *node , bool goL , int dep) {
        if (node == nullptr)
            return;
        ans = max(ans , dep);
        if (goL) {
            dfs(node->left , 0 , dep + 1);
            dfs(node->right , 1 , 1);
        }else {
            dfs(node->right , 1 , dep + 1);
            dfs(node->left , 0 , 1);
        }
    }
};
