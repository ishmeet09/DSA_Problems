#include<bits/stdc++.h>
using namespace std;
//lower bound used to find get bigger element
//imp pattern->standard procedure 
//use include exclude pattern same as before while creating subsequence but only include next incase its bigger
//if some adjusted is needed ,do it in dp array only not in logic(prev=-1)
class Solution {
public:
    int solve(vector<int>&arr,int prev,int curr){
        if(curr>=arr.size()){
            return 0;
        }
        //indcude exclude pattern
        int include=0;
        if(prev==-1 || arr[curr]>arr[prev]){//either first element or curr element is greater than last included
            include = 1+solve(arr,curr,curr+1);
        }
        int exclude = solve(arr,prev,curr+1);
        int ans =max(include,exclude);
        return ans;
    }
    int lengthOfLIS(vector<int>& nums) {
        int prev=-1;
        int curr=0;
        return solve(nums,prev,curr);
    }
};
//top down->remember to change pd[curr][prev]to dp[curr][prev+1]
    int solve(vector<int>&arr,int prev,int curr,  vector<vector<int>>&dp){
        if(curr>=arr.size()){
            return 0;
        }
        //indcude exclude pattern
        int include=0;
        if(dp[curr][prev+1]!=-1){
            return dp[curr][prev+1];
        }
        if(prev==-1 || arr[curr]>arr[prev]){//either first element or curr element is greater than last included
            include = 1+solve(arr,curr,curr+1,dp);
        }
        int exclude = solve(arr,prev,curr+1,dp);
        dp[curr][prev+1] =max(include,exclude);
        return dp[curr][prev+1];
    }
    int lengthOfLIS(vector<int>& nums) {
        int prev=-1;
        int curr=0;
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(nums,prev,curr,dp);
    }
//tabulation
    int solveTab(vector<int>& arr){
        int n=arr.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        //base case related to 0->arr already initlized with 0
        for(int curr =n-1;curr>=0;curr--){
            for(int prev=curr-1;prev>=-1;prev--){
                     //indcude exclude pattern
            int include=0;
           
            if(prev==-1 || arr[curr]>arr[prev]){
            include = 1+dp[curr+1][curr+1];
            }
            int exclude = dp[curr+1][prev+1];
            dp[curr][prev+1] =max(include,exclude);
         
            }
        }   
        return dp[0][0];   
    }
       // Space optimization
    int spaceOpt(vector<int>&nums){
        int n = nums.size();
        vector<int>currRow(n+1,0);
        vector<int>nextRow(n+1,0);
        // Step 2 : Observe base case of top down -> already handled in initialization
        // Step 3 : Reverse the flow of top down
        for(int curr = n - 1;curr>=0;curr--){
            for(int prev = curr-1;prev>=-1;prev--){
                // include
                int include = 0;
                if(prev == -1 || nums[curr] > nums[prev]){
                    include = 1 + nextRow[curr+1];
                }
                // exclude
                int exclude = 0 + nextRow[prev+1];
                currRow[prev+1] = max(include,exclude);
            }
            // Shift
            nextRow = currRow;
        }
        return nextRow[0];
    }
    // Optimal solution
    int solveOptimal(vector<int>&arr){
        if(arr.size() == 0){
            return 0;
        }
        vector<int>ans;
        ans.push_back(arr[0]);
        for(int i = 1;i<arr.size();i++){
            if(arr[i] > ans.back()){
                // include
                ans.push_back(arr[i]);
            }
            else{
                // overwrite
                // find index of just bigger element
                int index = lower_bound(ans.begin(),ans.end(),arr[i]) - ans.begin();
                ans[index] = arr[i];
            }
        }
        return ans.size();
    }
    int lengthOfLIS(vector<int>& nums) {
        int curr = 0;
        int prev = -1;
        // Recursive code
        // int ans = solveRec(nums,curr,prev);

        // Top Down approach
        // Step 1 : Create dp array
        // vector<vector<int>>dp(nums.size(),vector<int>(nums.size()+1,-1));
        // int ans = solveTopDown(nums,curr,prev,dp);

        // Bottom up approach
        // int ans = solveTab(nums);

        // Space optimization
        // int ans = spaceOpt(nums);

        // Optimal solution
        int ans = solveOptimal(nums);
        return ans;
    } 
int main(){

return 0;
}