class Solution {
public:


    string f(string str1, string str2, int n1 , int n2){
        string ans = "";
        if(str1[0]!=str2[0]) return ans;
        int i=0,j=0;
        while(i<n1 && j<n2){
            if(str1[i]==str2[j]){
                ans += str1[i];
            }else{
                break;
            }
            i++,j++;
        }
        return ans;
    }

    string helper(vector<string>&arr){
        int n = arr.size();
        string ans = f(arr[0], arr[1], arr[0].length(), arr[1].length());
     
        for(int i=2;i<arr.size();i++){
            ans = f(ans, arr[i], ans.length(), arr[i].length());
        }
        return ans;
    }

    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if(n==1) return strs[0];

        return helper(strs);
    }
};
