class Solution {
public:

    long long counter(long long mid, vector<int>& time)
    {
        long long count = 0;

        for(int i = 0; i < time.size(); i++)
        {
            count += (mid / time[i]);
        }

        return count;
    }

    long long minimumTime(vector<int>& time, int totalTrips) {

        long long left = 1;

        long long right =
        1LL * (*min_element(time.begin(), time.end())) * totalTrips;

        while(left < right)
        {
            long long mid = left + (right - left) / 2;

            long long count = counter(mid, time);

            if(count < totalTrips)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }

        return left;
    }
};