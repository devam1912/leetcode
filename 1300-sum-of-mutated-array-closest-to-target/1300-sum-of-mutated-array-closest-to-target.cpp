class Solution {
public:
    int validator(vector<int>& arr, int num)
    {
        int sum = 0;
        for (int x : arr)
        {
            sum += min(num, x);
        }
        return sum;
    }

    int findBestValue(vector<int>& arr, int target) {
        int low = 0;
        int high = *max_element(arr.begin(), arr.end());

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int val = validator(arr, mid);

            if (val > target)
                high = mid - 1;
            else
                low = mid + 1;
        }

        int s1 = validator(arr, high);
        int s2 = validator(arr, high + 1);

        if (abs(s1 - target) <= abs(s2 - target))
            return high;
        else
            return high + 1;
    }
};