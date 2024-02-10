#include<iostream>
using namespace std;
/*Very imp ques 
we get to know about how to count palindromic substring 
instead of finding substrings and then check if its palindrome or not
we use two ptr approach to get substr
in this odd and even length substrs are found
we increment the count till we get either non equal chars or i or j get out of string bound
*/
int solve(string s,int i,int j){
        int count=0;
        while(i>=0&&j<s.length()&&s[i]==s[j]){
            count++;
            i--;
            j++;
            
        }
        return count;
    }
    int countSubstrings(string s) {
        int count=0;
        for(int i=0;i<s.length();i++){
            //odd ans,checking substrs of odd length
            count = count + solve(s,i,i);
            //even ans ,checking substrs of even length
            count =count +solve(s,i,i+1);
        }
        return count;
    }
int main(){

return 0;
}