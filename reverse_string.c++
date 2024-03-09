class Solution {
public:

    string subString(string s, int start, int end){
        string ans = "";
        while(start<=end){
            ans += s[start];
            start++;
        }
        cout<< ans<<" ";
        return ans;
    }
    
    string helper(string s){
        int flag = 1;
        string ans = "";
        int n = s.length();

        int i=n-1, j=n-1;
        while(i>=0 && j>=0){
            while(i>=0 && s[i]!=' '){
                i--;
            }
            ans += flag?subString(s, i+1, j): ' ' +subString(s, i+1, j);
            flag = 0;
            while(i>=0 && s[i]==' '){
                i--;
            }
            j = i;
        }
        return ans;
    }

    string reverseWords(string s) {
        return helper(s);
    }
};
