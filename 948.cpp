#include<bits/stdc++.h>
using namespace std;
    //if we are decreasing power and getting score,just giveaway the least power
        //if we are increasing power and giving away score,make sure you get the max power for future
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int n = tokens.size();
        int score = 0;
        int max_score = 0;
        int left = 0;
        int right = n - 1;
        
        while (left <= right) {
            if (power >= tokens[left]) {
                power -= tokens[left];
                score += 1;
                left += 1;
                max_score = max(max_score, score);
            } else if (score > 0) {
                power += tokens[right];
                score -= 1;
                right -= 1;
            } else {
                break;
            }
        }
        
        return max_score;
    }
};
int main(){

return 0;
}