class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int dp0 = cost[0], dp1 = cost[1], curr;
        for(int i= 2; i<n; i++){
            curr=cost[i]+min(dp0,dp1);
            dp0 = dp1;
            dp1 = curr;
        }
        return min(dp0,dp1);
    }
};