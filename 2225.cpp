#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        set<int>st;
        map<int,int>lose;//not unoredered because we want it in increasing order
        for(int i =0;i<matches.size();i++){
            int winner = matches[i][0];
            int losser = matches[i][1];
            st.insert(winner);
            st.insert(losser);
            lose[losser]++;
        }

        vector<int>v1;
        vector<int>v2;
        for(auto i:st){
            if(lose.find(i)==lose.end()){
                v1.push_back(i);
            }
        }
        for(auto i:lose){
            if(i.second==1){
                v2.push_back(i.first);
            }
        }
        vector<vector<int>>ans;
        ans.push_back(v1);
        ans.push_back(v2);
        
        return ans;
    }
};
int main(){

return 0;
}