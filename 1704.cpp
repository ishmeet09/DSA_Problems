#include<iostream>
using namespace std;
class Solution {
public:
    bool halvesAreAlike(string s) {
        int count1=0;
        int count2=0;
        for(int i=0;i<s.size()/2;i++){
            char x=s[i];
            if (x == 'a' || x == 'e' || x == 'i' || x == 'o'
            || x == 'u' || x == 'A' || x == 'E' || x == 'I'
            || x == 'O' || x == 'U'){
                count1++;
            }
        }
        for(int i=s.size()/2;i<s.size();i++){
            char x=s[i];
            if (x == 'a' || x == 'e' || x == 'i' || x == 'o'
            || x == 'u' || x == 'A' || x == 'E' || x == 'I'
            || x == 'O' || x == 'U'){
                count2++;
            }
        }
        return count1==count2;
    }
};
int main(){

return 0;
}