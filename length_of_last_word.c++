class Solution {
public:


    int helper(string s){
        int n = s.length();
        int temp = 0;
        int isSpace = 0;
        for(int i=0;i<n;i++){
            if(s[i]==' '){
                isSpace = 1;
            }

            if(isSpace==0 && s[i]!=' '){
                temp += 1;
            }

            if(isSpace==1 && s[i]!=' '){
                temp = 1;
                isSpace = 0;
            }
        }
        return temp;
    }

    int lengthOfLastWord(string s) {
        return helper(s);
    }
};
