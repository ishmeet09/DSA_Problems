#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    class node{
        public:
        char ch;
        int freq;
        node(char c,int f){
            ch=c;
            freq=f;
        }

    };
    class compare{ 
        public:
        bool operator()(node a, node b){
            return a.freq <b.freq;
        }
    };
    string frequencySort(string s) {
        unordered_map<int,int>freq;
        for(int i=0;i<s.size();i++){
            freq[s[i]]++;
        }
        priority_queue<node,vector<node>,compare>pq;
        for(auto i : freq){
            node n1 = node(i.first,i.second);
            pq.push(n1);
        }
        string ans="";
        while(!pq.empty()){
            node temp = pq.top();
            char chara = temp.ch;
            int fre = temp.freq;
            pq.pop();
            while(fre--){
                ans += chara;
            }
        }
        return ans;
    }
};
int main(){

return 0;
}