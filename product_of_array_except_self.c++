// O{n2} solution, TLE
class Solution {
public:
    vector<int> f(vector<int> &arr, int n){
        vector<int> ans(n,1);
        for(int i=0;i<n;i++){
            int temp = 1;
            int j = 0;
            while(j<n){
                if(j!=i){
                    temp = arr[j] * temp;
                }
                j++;
            }
            ans[i] = temp;
        }
        return ans;
    }
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        return f(nums, n);
    }
};


// O{N} Solution
