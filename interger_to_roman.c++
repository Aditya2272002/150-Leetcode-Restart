

/*
We have to consider the number like 4,9,40,90,400,900 as they have unique representation , we calculate it as smallest divisible of it.
*/


class Solution {
public:

    string helper(int num){
        vector<int> nums = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
        vector<string> value = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
        int n = nums.size();

        string ans = "";
        int t = n-1;
        while(num!=0){
            while(num>=nums[t]){
                num -= nums[t];
                ans += value[t];
                cout<<t<<" ";
            }
            t--;
        }
        return ans;
    }

    string intToRoman(int num) {
        return helper(num);
    }
};
