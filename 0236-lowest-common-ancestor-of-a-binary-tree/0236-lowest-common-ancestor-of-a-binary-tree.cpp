/**
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
    bool findp(TreeNode* root, vector<TreeNode*>& x, TreeNode* y){
    if(root==NULL){return false;}
    x.push_back(root);
    if(root->val==y->val){return true;}
    if(findp(root->left, x, y) || findp(root->right, x, y)){return true;}
    x.pop_back();
    return false;
}
//Function to return the lowest common ancestor in a Binary Tree.
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
   //Your code here 
   TreeNode* no1=root;
   TreeNode* no2=root;
   vector<TreeNode*>v1, v2;
   findp(no1, v1, p);
   findp(no2, v2, q);
   //cout<<v1.size()<<" "<<v2.size()<<endl;
   vector<int>a1, a2;
  for(int i=0; i<v1.size(); i++){
      a1.push_back(v1[i]->val);
  }
  for(int i=0; i<v2.size(); i++){
      a2.push_back(v2[i]->val);
  }
//   for(int i=0; i<v1.size(); i++){
//       cout<<a1[i]<<" ";
//   }cout<<endl;
//   for(int i=0; i<v2.size(); i++){
//       cout<<a2[i]<<" ";
//   }cout<<endl;
  int cnt, maxi=max(v1.size(), v2.size()), mini=min(v1.size(), v2.size());
  if(v1[mini-1]->val==v2[mini-1]->val){return v1[mini-1];}
  for(int i=0; i<maxi; i++){
      if(a1[i]!=a2[i]){cnt=i; break;}
  }
  //cout<<cnt<<endl;
   TreeNode* ans=v1[cnt-1];
//   for(int i=0; i<v1.size(); i++){
//       cnt--;
//       if(cnt==0){ans=(*it);}
//   }
   return ans;
}
};