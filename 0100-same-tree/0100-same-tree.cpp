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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // if any of the two root node is not null and other is null it is simply not same 
        if(p == NULL && q == NULL) return true;
        if((p == NULL && q != NULL) || (p != NULL && q == NULL)) return false;
        
        // recurcise check for every subtree
        bool left = isSameTree(p->left,q->left);
        bool right = isSameTree(p->right,q->right);
        
        // checking node values here
        bool diff;
        if(p->val == q->val){
            diff = true;
        }else diff = false;
        
        if(left && right && diff) return true;
        else return false;
    }
};