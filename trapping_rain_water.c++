class Solution {
public:

    int helper(vector<int>&heights){
        int n = heights.size();

        vector<int> leftMax(n,0);
        vector<int> rightMax(n,0);

        leftMax[0] = heights[0];
        for(int i=1;i<n;i++){
            leftMax[i] = max(heights[i], leftMax[i-1]);
        }

        rightMax[n-1] = heights[n-1];
        for(int j=n-2;j>=0;j--){
            rightMax[j] = max(rightMax[j+1], heights[j]);
        }

        int totalWater = 0;
        for(int i=0;i<n;i++){
            totalWater = totalWater + (min(rightMax[i],leftMax[i])-heights[i]);
        }
        return totalWater;
    }

    int trap(vector<int>& height) {
        int n = height.size();
        if(n<3) return 0;
        return helper(height);
    }
};
