#include<iostream>
using namespace std;
class Solution {
public:
   int minimumLength(string s) {
        int i = 0;
        int j = s.size() - 1;
        
        while (i < j && s[i]==s[j]) {
            char c = s[i];
        
            while (i<j && s[i] == c ) {
                i++;
            }
            //special case when i becomes equal between loop
            while (i<=j && s[j] == c ) {
                j--;
            }

        }
        return j-i+1;
    }
};
int main(){

return 0;
}