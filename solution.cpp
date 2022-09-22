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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        if(root == NULL) {
            return ans;
        }
        vector<int> t;
        helper(ans, t, root, targetSum);
        return ans;
    }
    void helper(vector<vector<int>>& ans, vector<int> temp, TreeNode* root, int sum) {
        if(root  == NULL) {
            return;
        }
        if(root->left == NULL && root->right == NULL) {
            if(sum == root->val) {
                cout<<root->val<<" ";
                temp.push_back(root->val);
                ans.push_back(temp);
            }
        }
        else {
            sum -= root->val;
            temp.push_back(root->val);
            helper(ans, temp, root->left, sum);
            helper(ans, temp, root->right, sum);
        }
    } 
};
