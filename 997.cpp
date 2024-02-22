#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int,int>mp;
        if(n==1)
            return 1;
        for(auto v:trust){
            int a = v[0];
            int b = v[1];
            mp[b]++;
            mp[a]--;   
        }
        
        for(auto it:mp){
            if(it.second==n-1)
                return it.first;
        }
          return -1;
    }
  
};
int main(){

return 0;
}