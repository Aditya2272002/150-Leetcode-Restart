class Solution {
public:

    bool helper(string s, int n, string t, int m){
        int i=0,j=0;
        while(i<n && j<m){
            if(t[j] == s[i]){
                i++;
            }
            j++;
        }
        if(i==n)return true;
        else return false;
    }

    bool isSubsequence(string s, string t) {
        int n = s.length();
        int m = t.length();
        if(n==0) return true;
        if(m==0) return false;
        return helper(s,n,t,m);    
    }
};
