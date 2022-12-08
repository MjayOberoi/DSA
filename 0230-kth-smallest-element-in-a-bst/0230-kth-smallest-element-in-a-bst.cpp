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
    int ans,f;
    void check(TreeNode* root){
        if(!root)
            return;     
        if(f>0)
            check(root->left);
        if(f>0){
            ans=root->val;
            cout << ans<<",";
        }
        f-=1;
        if(f>0)
            check(root->right);
        return;
    }
    int kthSmallest(TreeNode* root, int k) {
        f=k;
        check(root);
        return ans;  
    }
};