class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        return f(0,dp,n,nums);


    }
    int f(int i,vector<int>& dp,int n,vector<int>& nums){
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1) return dp[i];
        return dp[i]=max(nums[i]+f(i+2,dp,n,nums),f(i+1,dp,n,nums));
    }
};
