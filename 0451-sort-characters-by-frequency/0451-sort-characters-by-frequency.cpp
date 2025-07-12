class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>freq;
        for(char ch:s)
        freq[ch]++;
        priority_queue<pair<int,char>>maxheap;
        for(auto it: freq)
        maxheap.push({it.second,it.first});
        string result = "";
        while(!maxheap.empty()){
            auto[count,ch]=maxheap.top();
            maxheap.pop();
            result+=string(count,ch);
        }
        return result;
    }
};