class Solution {
public:

    bool helper(string s){
      string temp;
      int n = s.length();
      for(int i=0;i<n;i++){
        int t = int(s[i]);
        if((t>64 && t<91) || (t>47 && t<58) || (t>96 && t<123)){
            temp += tolower(s[i]);
        }
      }
      int i=0,j=temp.length()-1;
      while(i<j){
        if(temp[i]!=temp[j]){
            return false;
        }
        i++, j--;
      }
      return true;
    }

    bool isPalindrome(string s) {
        return helper(s);
    }
};
