class Solution {
public:

    bool f(int i, int n, vector<int>&nums,vector<int>& dp){
        if(i>=n-1) return dp[i] = true;

        if(dp[i]!=-1){
            return dp[i];
        }

        int maxJump = i + nums[i];
        for(int j=i+1;j<=maxJump;j++){
            if(f(j,n,nums,dp))
                return dp[i] = true;
        }
        return dp[i] = false;
    }

    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return true;
        vector<int> dp(n,-1);
        return f(0,n,nums,dp);
    }
};
