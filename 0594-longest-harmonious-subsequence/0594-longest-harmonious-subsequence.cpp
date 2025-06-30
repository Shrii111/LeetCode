class Solution {
public:
    int findLHS(vector<int>& nums) {
         unordered_map<int, int> count;
    for (int num : nums) {
        count[num]++;
    }

    int maxLength = 0;
    for (auto& [key, value] : count) {
        if (count.find(key + 1) != count.end()) {
            maxLength = max(maxLength, value + count[key + 1]);
        }
    }

    return maxLength;
    }
};