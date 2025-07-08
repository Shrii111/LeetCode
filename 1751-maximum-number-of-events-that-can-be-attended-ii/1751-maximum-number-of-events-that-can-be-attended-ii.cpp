class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
         int n = events.size();
        
        // Sort events by end day
        sort(events.begin(), events.end(), [](auto &a, auto &b){
            return a[1] < b[1];
        });

        // Extract end times for binary search
        vector<int> endTimes;
        for (auto &e : events) endTimes.push_back(e[1]);

        // DP[i][j] = max value by attending j events from first i events
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

        for (int i = 1; i <= n; ++i) {
            int start = events[i - 1][0];
            int end = events[i - 1][1];
            int val = events[i - 1][2];

            // Find last event that ends before this event starts
            int prev = upper_bound(endTimes.begin(), endTimes.end(), start - 1) - endTimes.begin();
            
            for (int j = 1; j <= k; ++j) {
                // Either skip or take this event
                dp[i][j] = max(dp[i - 1][j], dp[prev][j - 1] + val);
            }
        }

        return dp[n][k];
    }
};