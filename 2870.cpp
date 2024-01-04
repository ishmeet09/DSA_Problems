#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minOperations(vector<int>& nums) {
      unordered_map<int,int>mp;
      for(int i=0;i<nums.size();i++){
          mp[nums[i]]++;
      }
      int ans=0;
      for(auto i:mp){
          int element = i.first;
          int freq = i.second;
          if(freq==1){
              return -1;
          }
        if(freq%3==0){
            ans+=freq/3;
        }
        else{
            ans+=freq/3+1;
        }
      }  
      return ans;
    }
};
int main(){

return 0;
}