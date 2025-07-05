class Solution {
public:
    int findLucky(vector<int>& arr) {
         unordered_map<int, int> freq;

    // Count the frequency of each number
    for (int num : arr) {
        freq[num]++;
    }

    int largestLucky = -1;
    // Check if frequency equals the value
    for (auto& [num, count] : freq) {
        if (num == count) {
            largestLucky = max(largestLucky, num);
        }
    }

    return largestLucky;
    }
};