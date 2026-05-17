class Solution {
public:

    long long checker(long long i, int k, long long r)
    {
        long long ans = 1;

        for(int j = 0; j < k; j++)
        {
            if(ans > r / i) return r + 1;

            ans *= i;
        }

        return ans;
    }

    int countKthRoots(int l, int r, int k) {

        // special case
        if(k == 1) return r - l + 1;

        int count = 0;

        if(l == 0) count++;

        for(long long i = 1; ; i++)
        {
            long long num = checker(i, k, r);

            if(num > r) break;

            if(num >= l) count++;
        }

        return count;
    }
};