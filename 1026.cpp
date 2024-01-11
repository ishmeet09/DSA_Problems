#include<bits/stdc++.h>
using namespace std;

 
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
class Solution {
public:
    int solve(TreeNode* root,int maxi,int mini){
        if(!root){
            return maxi-mini;
        }
        maxi=max(root->val,maxi);
        mini=min(root->val,mini);
        return max(solve(root->left,maxi,mini),solve(root->right,maxi,mini));
    }
    int maxAncestorDiff(TreeNode* root) {
        return solve(root,INT_MIN,INT_MAX);
    }
};
int main(){

return 0;
}