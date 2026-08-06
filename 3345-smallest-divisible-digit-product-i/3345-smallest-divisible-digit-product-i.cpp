class Solution {
public:
    int smallestNumber(int n, int t) {
        for(int i=n;i<INT_MAX;i++)
        {
            int temp = i;
            int mul = 1;
            while(temp>0)
            {
                int rem = temp%10;
                mul*=rem;
                temp/=10;
            }
            if(mul%t==0) return i;
        }
        return 0;
    }
};