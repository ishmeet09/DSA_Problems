#include<bits/stdc++.h>
using namespace std;
/*M1
given an array of strings
go to each string and sort it 
now those anagrams will look same
so group the same strings together(use map)
In map crete a key value pair where key is the sorted string and values are original strings
TC-O(N*KlogK)
*/
vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>>mp;
        for(auto str: strs){
            string s=str;
            sort(s.begin(),s.end());
            //here s has sorted string but original is also there in str
            mp[s].push_back(str);
            //this is the properties of map that for same sorted value it will update the already
            //created before
        }
        vector<vector<string>>ans;
        for(auto it=mp.begin();it!=mp.end();it++){
        //in this type of loop it-> first give key and it->second give value
        ans.push_back(it->second);
        }
        return ans;

    }
/*M2 instead of sort use the method used in ques 9
crete hash for every string and group the elements with same hash together
map will be of hash key and vector of strings as value
stl also has array std::array<int ,256>hash ={0}
TC-O(NK)
SC-O(NK)
*/
std::array<int, 256> hash_maker(string s){
    std::array<int, 256>hash = {0};
    for(int i = 0; i < s.size(); i++){
        hash[s[i]]++;
    }
    return hash;
}

vector<vector<string>> groupAnagrams(vector<string>& strs){
    
    map<std::array<int, 256>, vector<string>>mp;

    for(auto str:strs){
        mp[hash_maker(str)].push_back(str);
    }

    vector<vector<string>>ans;
    for(auto it = mp.begin(); it != mp.end(); it++){
        ans.push_back(it->second);
    }
    return ans;
}


int main(){
// Input: strs = ["eat","tea","tan","ate","nat","bat"]
// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
return 0;
}