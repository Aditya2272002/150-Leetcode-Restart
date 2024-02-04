class Solution1 {
public:

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        if(n==0){
            return;
        }

        m = m+n;
        int i=0,j=0;

        while(i<m && j<n){
            if(nums1[i] > nums2[j]){
                int k = m-1;
                for(;k>i;k--){
                    nums1[k]  = nums1[k-1];
                }
                nums1[k] = nums2[j];
                i++;
                j++;
            }else{
                if(m-i == n-j){
                    nums1[i] = nums2[j];
                    j++;
                }
                i++;
            }
        }

    }
};



class Solution2 {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1;
        int j = n-1;
        int k = m+n-1;


        while(j>=0){
            if(i>=0 && nums1[i] > nums2[j]){
                nums1[k] = nums1[i];
                k--;
                i--;
            }else{
                nums1[k] = nums2[j];
                k--,j--;
            }
        }

    }
};
