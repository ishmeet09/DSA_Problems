#include<iostream>
using namespace std;
class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        string ans="";
        int zeros=0;
        int ones=0;
        for(auto i:s){
            if(i=='0'){
                zeros++;
            }
            else{
                ones++;
            }
        }
        while(ones!=1){
            ans.push_back('1');
            ones--;
        }
        while(zeros){
            ans.push_back('0');
            zeros--;

        }
        ans.push_back('1');
        return ans;

    }
};
int main(){

return 0;
}