class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        long long left = 1; 
        long long right = *max_element(piles.begin(), piles.end());
        long long ans = 0;

        while (left <= right)
        {
            long long mid = left + (right - left) / 2; 
            long long count = 0;

            for (int p : piles) {
                count += p / mid;
                if (p % mid != 0) count++;
            }

            if (count > h) {
                left = mid + 1;
            } else {
                ans = mid;
                right = mid - 1;
            }
        }

        return ans;
    }
};
