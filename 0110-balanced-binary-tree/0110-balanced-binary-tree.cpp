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
    pair<int,bool> fastBalanced(TreeNode* root){
        pair<int,bool> ans = make_pair(0,true);
        // base case
        if(root == NULL) return ans;
        
        // get height and balanced or not bool from left and then rom right
        pair<int, bool> left = fastBalanced(root->left);
        pair<int, bool> right = fastBalanced(root->right);
        
        // check whether the subtree is balanced by heights
        bool diff = abs(left.first - right.first) <= 1;
        
        // if all conditions true return true and max height else return false
        if(left.second && right.second && diff){
            ans.second = true;
        }else{
            ans.second = false;
        }
        ans.first = max(left.first,right.first)+1;
        return ans;
        
    }
    bool isBalanced(TreeNode* root) {
        pair<int,bool> ans = fastBalanced(root);
        return ans.second;
    }
};