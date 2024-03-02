class Solution {
public:
    
    vector<int> helper(vector<int> &arr){
        int n = arr.size();
        vector<int> ans(n,0);
        int i = 0;
        //Finding the index upto which the negative number are there.
        while(i<n && arr[i]<0){
            i++;
        }
        
        //Reversing the negative numbers part of array
        int p=0,q=i-1;
        while(p<q){
            int temp = arr[p];
            arr[p] = arr[q];
            arr[q] = temp;
            p++,q--;
        }

        //Making the nagative numbers positive
        for(int k=0;k<i;k++){
            arr[k] = arr[k] * (-1);
        }

        //Merging two sorted array when it is combination of positive and negative
        if(i<n){
            int x=0, y=i, current=0;
            while(x<i && y<n){
                if(arr[x]> arr[y]){
                    ans[current] = arr[y];
                    y++;
                }else{
                    ans[current] = arr[x];
                    x++;
                }
                current++;
            }

            //Adding remaining elements
            while(x<i){
                ans[current] = arr[x];
                x++, current++;
            }

            while(y<n){
                ans[current] = arr[y];
                y++, current++;
            }

            
            //For complete Negative elements
            for(int t=0;t<n;t++){
                ans[t] = ans[t]*ans[t];
            }
            return ans;
        }

        for(int t=0;t<n;t++){
            ans[t] = arr[t]*arr[t];
        }

        return ans;
    }

    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            vector<int> t(1, nums[0]*nums[0]);
            return t;
        }   
        return helper(nums);
    }
};
