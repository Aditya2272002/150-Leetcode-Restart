class Solution {
public:
    int hIndex(vector<int>& arr) {
        int n = arr.size();
        if(n==1 && arr[0]==0) return 0;
        if(n==1 && arr[0]>=1) return 1;
        vector<int> temp(n+1,0);
        for(int i=0;i<n;i++){
            if(arr[i]>n)
                temp[n] += 1;
            else
                temp[arr[i]] += 1;
        }
        int maxH = 0;
        for(int i=n;i>0;i--){
            maxH += temp[i];
            if(maxH>=i)
                return i;
        }
        return 0;
    }
};



/*

h-index:-

h-index=4 means that there are atleast 4 research paper that has atleast 4 citation


*/
