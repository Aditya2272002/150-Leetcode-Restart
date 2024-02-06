class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int,int> mp;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(mp.find(nums[i])!= mp.end()){
                mp[nums[i]]++;
            }else{
                mp[nums[i]] = 1;
            }
        }

        int k = 0;
        for(auto i=mp.begin();i!=mp.end();i++){
            nums[k] = i->first;
            k++;
        }
        return k;
    }
};



class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int j=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=nums[j]){
                j++;
                nums[j] = nums[i];
            }
        }
        return j+1;
    }
};
