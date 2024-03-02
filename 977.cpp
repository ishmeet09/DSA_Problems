#include<bits/stdc++.h>
using namespace std;
//showing runtime error
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int i=0;
        int j=0;
        while(nums[j]<0){
            j++;
        }
        while(j<nums.size()&&i<nums.size()){
            if(i<nums.size()&&abs(nums[j])<abs(nums[i])){
                swap(nums[j],nums[i]);
                i++;
            }
            i++;
            j++;
        }
        for(auto& i:nums){
            i=i*i;
        }
        return nums;
    }
};
//2nd approach
vector<int> sortedSquares(vector<int>& nums) {
    vector<int> result(nums.size());
    int left = 0, right = nums.size() - 1;
    int index = nums.size() - 1;

    while (left <= right) {
        int leftSquare = nums[left] * nums[left];
        int rightSquare = nums[right] * nums[right];
        
        if (leftSquare > rightSquare) {
            result[index--] = leftSquare;
            left++;
        } else {
            result[index--] = rightSquare;
            right--;
        }
    }

    return result;
}

int main(){

return 0;
}