class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> result;

        int m = nums1.size();
        int n = nums2.size();

        if (m == 0 || n == 0 || k == 0) return result;

        // Min-heap: {sum, index1, index2}
        using T = tuple<int, int, int>;
        priority_queue<T, vector<T>, greater<T>> minHeap;

        // Push only first row: nums1[i] + nums2[0]
        for (int i = 0; i < m && i < k; i++) {
            minHeap.emplace(nums1[i] + nums2[0], i, 0);
        }

        while (k-- > 0 && !minHeap.empty()) {
            auto [sum, i, j] = minHeap.top();
            minHeap.pop();

            result.push_back({nums1[i], nums2[j]});

            if (j + 1 < n) {
                minHeap.emplace(nums1[i] + nums2[j + 1], i, j + 1);
            }
        }

        return result;
    }
};
