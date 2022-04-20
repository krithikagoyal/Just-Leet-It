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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (root == NULL) {
            return ans;
        }
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        TreeNode* prev = NULL;
        while (q.size()) {
            TreeNode* val = q.front();
            q.pop();
            if (val == NULL) {
                ans.push_back(prev->val);
                if (q.size())
                    q.push(NULL);
                continue;
            }
            if (val->left) {
                q.push(val->left);
            }
            if (val->right) {
                q.push(val->right);
            }
            prev = val;
        }
        return ans;
    }
};