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
    int ans;

    void solve(TreeNode* root, unordered_map<int,int>& mp) {
        // base case
        if(!root){
            return;
        }
        if (!root->left&&!root->right) {
            mp[root->val]++;
            int count = 0;
            for (auto i : mp) {
                if (i.second % 2 == 1) {
                    count++;
                }
            }
            if (count <= 1) {
                ans++;
            }
            mp[root->val]--;
            return;
        }

        mp[root->val]++;
        solve(root->left, mp);
        solve(root->right, mp);
        mp[root->val]--;  
    }

    int pseudoPalindromicPaths(TreeNode* root) {
        unordered_map<int, int> mp;
        solve(root, mp);
        return ans;
    }
};

int main(){

return 0;
}