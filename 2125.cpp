#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countLasers(string s){
        int count = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                count++;
            }
        }
        return count;
    }
    int numberOfBeams(vector<string>& bank) {
        int ans = 0;
        int prevCount=0;
        for(auto& str: bank){
            int currentCount = countLasers(str);
            if(currentCount==0){
                continue;
            } 
            ans += currentCount * prevCount;
            prevCount = currentCount;

        }
        return ans;
    }
};
int main(){

return 0;
}