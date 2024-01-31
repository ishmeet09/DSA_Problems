#include<bits/stdc++.h>
using namespace std;
//gives tle
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int>ans;
        for(int i = 0 ;i<temperatures.size()-1;i++){
            int curr = temperatures[i];
            int cnt = 1;
            bool flag = false;
            for(int j = i+1 ;j<temperatures.size();j++){
                
                if(temperatures[j]>curr){
                    ans.push_back(cnt);
                    flag = true;
                    break;
                }
                else{
                    cnt++;
                }
                
            }
            if(!flag){
                ans.push_back(0);
            }
        }
        ans.push_back(0);
        return ans;
    }
};

//stack
vector<int> dailyTemperatures(vector<int>& t) {
    int n = t.size();
    vector<int> ans(n,0);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && t[i] > t[st.top()])
        {
            ans[st.top()] = i - st.top();
            st.pop();
        }
        st.push(i);
    }
    return ans;
int main(){

return 0;
}