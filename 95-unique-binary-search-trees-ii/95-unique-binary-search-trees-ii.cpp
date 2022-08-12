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
    vector<TreeNode*> generateTreesUtil(int n, int startVal) {
        vector<TreeNode*> ans;
        for (int i = 0; i <= n - 1; i++) {
            auto leftTrees = generateTreesUtil(i, startVal);
            auto rightTrees = generateTreesUtil(n - i - 1, startVal + 1 + i);
            if (leftTrees.size() == 0) leftTrees.push_back(NULL);
            if (rightTrees.size() == 0) rightTrees.push_back(NULL);
            for (auto leftTree : leftTrees) {
                for (auto rightTree : rightTrees) {
                    TreeNode* node = new TreeNode(startVal + i);
                    node->left = leftTree;
                    node->right = rightTree;
                    ans.push_back(node);
                }
            }
        }
        return ans;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        return generateTreesUtil(n, 1);
    }
};