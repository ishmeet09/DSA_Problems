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
 struct Node
{
    int data;
    Node* left, * right;

    Node(int x){
        data=x;
        left=NULL;
        right=NULL;
    }
}; 
//do inorder and check if it lies in the range and add to ans 
void solve(TreeNode* root, int low, int high,int& ans){
        if(!root){
            return;
        }
        solve(root->left,low,high,ans);
        if(root->val<=high&&root->val>=low){
            ans+=root->val;
        }
        solve(root->right,low,high,ans);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        int ans=0;
        solve(root,low,high,ans);
        return ans;
    }



/*
m2 store nodes and do v[i]->left = NULL and v[i]-> right = v[i+1] 
*/
//m3
void inorder(Node* root, Node* &prev){
    if(!root)
        return;

    inorder(root->left, prev);
    
    prev->left = 0;
    prev->right = root;
    prev = root;
    
    inorder(root->right, prev);
}

Node* flatten(Node* root){
    Node* dummy = new Node(-1);
    Node* prev = dummy;

    inorder(root, prev);
    
    prev->left = prev->right = 0;
    root = dummy->right;

    return root;
}

// TC : O(N)
// SC : O(H)