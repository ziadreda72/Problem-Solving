class Solution {
public:    
    int ans = 0;
    
    int maxAncestorDiff(TreeNode* root) {
        auto temp = dfs(root);
        return ans;
    }
    
    pair < int , int > dfs(TreeNode* node) {
        pair < int , int > ret = {node->val , node->val};
        if (node->left != nullptr) {
            auto [mn , mx] = dfs(node->left);
            ans = max(ans , max(abs(mn - node->val) , abs(mx - node->val)));
            ret.first = min(ret.first , mn);
            ret.second = max(ret.second , mx);
        }
        if (node->right != nullptr) {
            auto [mn , mx] = dfs(node->right);
            ans = max(ans , max(abs(mn - node->val) , abs(mx - node->val)));
            ret.first = min(ret.first , mn);
            ret.second = max(ret.second , mx);
        }
        return ret;
    }
};
