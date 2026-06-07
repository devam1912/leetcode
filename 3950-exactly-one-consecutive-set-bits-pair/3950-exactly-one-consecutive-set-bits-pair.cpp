class Solution {
public:
    bool consecutiveSetBits(int n) {
       //to get the number of pairs of 1 
        int x = n & (n >> 1);

        int cnt = 0;
        //counts how many 1 in x
        while (x) {
            cnt += x & 1;
            x >>= 1;
        }

        return cnt == 1;
    }
};