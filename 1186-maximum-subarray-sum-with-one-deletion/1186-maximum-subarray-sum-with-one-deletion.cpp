class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        int noDel = arr[0];   // Kadane without deletion
        int oneDel = 0;       // Kadane with one deletion
        int ans = arr[0];

        for (int i = 1; i < n; i++) {
            oneDel = max(noDel, oneDel + arr[i]);
            noDel = max(arr[i], noDel + arr[i]);

            ans = max(ans, max(noDel, oneDel));
        }
        return ans;
    }
};
