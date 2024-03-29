class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int count = 1;
        int maxCount = 0;
        int ans = nums[0]; 
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]){
                count++;
            }else {
                count = 1;
            }

            if(maxCount<count){
                maxCount = count;
                ans = nums[i];
            }
        }
        return ans;
    }
};
