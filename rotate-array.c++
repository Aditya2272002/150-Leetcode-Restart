class Solution {
public:

    void rotateByOne(vector<int>& nums){
        int n = nums.size();
        int temp = nums[n-1];
        for(int i=n-1;i>0;i--){
            nums[i] = nums[i-1];
        }
        nums[0] = temp;
    }

    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(k==0 || n==1 || n==0){
            return;
        }
        for(int i=0;i<k;i++){
            rotateByOne(nums);
        }
    }
};



//Note:- if K is greater than N then we have to take k=k%n, as we will get same array when we rotate the array as the size of of the array.
class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        int n = nums.size();
        if(n==0 || n==1 || k==0) return;
        if(k>n) k = k%n;
        cout<<k;
        int temp[k];
        int t=0;
        for(int i=n-k;i<n;i++){
            temp[t++] = nums[i];
        }

        for(int i=n-k-1;i>=0;i--){
            nums[i+k] = nums[i];
        }
        for(int i=0;i<k;i++){
            nums[i] = temp[i];
        }

    }
};




