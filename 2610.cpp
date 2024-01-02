#include<bits/stdc++.h>
using namespace std;
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int>mp;
        int maxi = INT_MIN;
    // Find the maximum frequency
    for (int i = 0; i < nums.size(); i++) {
        mp[nums[i]]++;
        maxi = max(maxi, mp[nums[i]]);
    }

        vector<vector<int>>ans;
        while(maxi>0){
        vector<int>temp;
        for(auto& i:mp){//imp note as &i affect the original map  
            if (i.second > 0) {
                temp.push_back(i.first);
                i.second--;
            }
            }
         ans.push_back(temp);
        maxi--;
        }
        return ans;
    }
int main(){

return 0;
}