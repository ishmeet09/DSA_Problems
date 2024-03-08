#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxFrequencyElements(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        for (auto &i : nums)
        {
            mp[i]++;
        }
        int maxi = -1;
        int count = 0;
        for (auto i : mp)
        {
            maxi = max(maxi, i.second);
        }

        for (auto i : mp)
        {
            if (i.second == maxi)
            {

                count = count + maxi;
            }
        }
        return count;
    }
};
int main()
{

    return 0;
}