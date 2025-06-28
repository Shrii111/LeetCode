class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
    vector<pair<int, int>> withIndex;
    for (int i = 0; i < nums.size(); i++) {
        withIndex.push_back({nums[i], i});
    }

    // Sort in descending order of value
    sort(withIndex.begin(), withIndex.end(), [](auto& a, auto& b) {
        return a.first > b.first;
    });

    // Pick top-k largest values (keep their original indices)
    vector<int> indices;
    for (int i = 0; i < k; i++) {
        indices.push_back(withIndex[i].second);
    }

    // Sort indices to maintain original order
    sort(indices.begin(), indices.end());

    // Build the result using original order
    vector<int> result;
    for (int i : indices) {
        result.push_back(nums[i]);
    }

    return result;

    }
};