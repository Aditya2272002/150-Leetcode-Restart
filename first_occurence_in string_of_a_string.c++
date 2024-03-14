class Solution {
public:

    int helper(string s1, string s2){
        int n = s1.length();
        int m = s2.length();
        
        int ans = INT_MAX;

        for(int i=0;i<n;i++){
            if(s1[i]==s2[0]){
                int k=0;
                while(k<m && k<n && s1[i+k]==s2[k]){
                    k++;
                }
                if(k>=m){
                    ans = min(ans, i);
                }
            }
        }
        return ans==INT_MAX? -1: ans;
    }


    int strStr(string s1, string s2) {
        return helper(s1,s2);
    }
};
