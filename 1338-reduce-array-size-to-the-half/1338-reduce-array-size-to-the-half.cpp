class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();

        unordered_map<int,int> freq;
        for (int x : arr) {
            freq[x]++;
        }

        vector<int> temp;
        for (auto &[num, times] : freq) {
            temp.push_back(times);
        }

        sort(temp.begin(), temp.end());

        int removed = 0;
        int ans = 0;

        for (int i = temp.size() - 1; i >= 0; i--) {
            removed += temp[i];
            ans++;
            if (removed >= n / 2) {
                return ans;
            }
        }
        return ans;
    }
};