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


// O{N} time O{N} space Solution

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n,1);
        vector<int> right(n,1);

        int temp = 1;
        for(int i=0;i<n;i++){
            left[i] = arr[i] * temp;
            temp = left[i];
        }

        temp = 1;
        for(int i=n-1;i>=0;i--){
            right[i] = arr[i] * temp;
            temp = right[i];
        }

        arr[n-1] = left[n-2];
        arr[0] = right[1];
        for(int i=1;i<n-1;i++){
            arr[i] = left[i-1] * right[i+1];
        }
        return arr;

    }
};

