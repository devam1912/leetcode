class Solution {
public:

    bool canDistribute(int n, vector<int>& quantities, int maxProducts) {

        long long storesNeeded = 0;

        for (int quantity : quantities) {

            storesNeeded += (quantity + maxProducts - 1) / maxProducts;

            if (storesNeeded > n)
                return false;
        }

        return true;
    }

    int minimizedMaximum(int n, vector<int>& quantities) {

        int low = 1;
        int high = *max_element(quantities.begin(), quantities.end());

        int ans = high;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (canDistribute(n, quantities, mid)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};