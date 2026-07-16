class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int s=cost.size();
        vector<int>dp(s+1,-1);
        f(0,dp,cost,s);
        
        return min(dp[0],dp[1]);

    }
    int f(int n,vector<int>& dp,vector<int>& cost,int s){
        if(n>=s){
            return 0;
        }
        if(dp[n]!=-1) return dp[n];
        return dp[n]=cost[n]+min(f(n+1,dp,cost,s),f(n+2,dp,cost,s));
    }
};
