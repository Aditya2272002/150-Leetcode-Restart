/*
Reference: https://youtu.be/k8F7nzySY60?si=m8mCi21vuXLywfX_


Consider how many jumps reuiqred from any index i to reach to next element in the same row. It will be 2*(r-1-curIndex) when we go from bottom to up i.e. in south direction and 2*i when we go from up to bottom i.e. in north direction.
Also we have to change the direction when we have moved max in any direction.
Suppose we are at index '2' then for getting 'g' (index=2) we got south by 2*(5-2-1)=4, i.e. string[2+4] = 'g'
Now for getting 'k' from 'g' (index=6) we have to change direction and go north by 2*(2)=4 i.i string[6+4] = 'k'


string = 'abcdefghijklmop'
 
   0  1 2 3 4  5 6 7 8 9 10
0  a        i
1  b      h    j 
2  c    g        k        p
3  d  f            l    o
4  e                 m



In case of index==0 we only have to move down i.e. south. So add south ONLY.
In case of index==r-1 we only have to move up i.e. north. So add north ONLy.

In case of rows==1 the string is the answer.

*/



class Solution {
public:

    string helper(string s, int r){
        int n = s.length();

        if(r==1) return s;

        string ans = "";
        for(int i=0;i<r;i++){
            int tempIndex = i;
            int south = 2*(r-1-i);
            int north = 2*(i);
            
            bool goSouth = true;
            while(tempIndex<n){
                ans += s[tempIndex];

                if(i==0){
                    tempIndex += south;
                }else if(i==r-1){
                    tempIndex += north;
                }else{
                    if(goSouth){
                        tempIndex += south;
                    }
                    else{
                        tempIndex += north;
                    }
                    goSouth = !goSouth;
                }
            }
        }
        return ans;
    }


    string convert(string s, int numRows) {
        return helper(s, numRows);
    }
};
