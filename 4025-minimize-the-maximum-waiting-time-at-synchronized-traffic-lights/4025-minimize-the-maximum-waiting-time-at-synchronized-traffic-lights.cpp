class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {

        int maxGreen = *max_element(lights.begin(), lights.end());

        int ans = 0;

        for (int time : arrivalTime) {

            int r = time % period;

            int wait;

            if (r < maxGreen)
                wait = 0;
            else
                wait = period - r;

            ans = max(ans, wait);
        }

        return ans;
    }
};