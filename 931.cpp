#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int mini=INT_MAX;
    //build down
        for(int i=1;i<matrix.size();i++){
          
            for(int j = 0;j<matrix[0].size();j++){
                if(j==0){
                    matrix[i][j] += min(matrix[i-1][j],matrix[i-1][j+1]) ;
                }
                else if(j==n-1){
                    matrix[i][j] += min(matrix[i-1][j],matrix[i-1][j-1]) ;
                }
                else{
                    matrix[i][j] +=min( matrix[i-1][j+1],min(matrix[i-1][j],matrix[i-1][j-1])) ;
                }
            }

        }
        for(int j=0;j<matrix.size();j++){
            mini = min(mini,matrix[n-1][j]);
        }
        return mini;
    }

};
int main(){

return 0;
}