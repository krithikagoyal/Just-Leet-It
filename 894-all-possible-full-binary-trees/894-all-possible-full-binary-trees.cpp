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
    vector<TreeNode*> allPossibleFBT(int n) {
        if (n == 1) {
            return {new TreeNode(0)};
        } 
        vector<TreeNode*> ans;
        for (int i = 1; i <= n - 2; i++) {
            auto leftTrees = allPossibleFBT(i);
            auto rightTrees = allPossibleFBT(n - i - 1);
            if (leftTrees.size() == 0) leftTrees.push_back(NULL);
            if (rightTrees.size() == 0) rightTrees.push_back(NULL);
            for (auto leftTree : leftTrees) {
                for (auto rightTree : rightTrees) {
                    TreeNode* node = new TreeNode(0);
                    node->left = leftTree;
                    node->right = rightTree;
                    if (leftTree && rightTree) {
                        ans.push_back(node);
                        // cout << ans.size() << endl;
                        // cout << i << " " << n << endl;
                    }
                }
            }
        }
        return ans;
    }
};