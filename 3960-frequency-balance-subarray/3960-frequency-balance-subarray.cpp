class Solution {
public:
    int getLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;

        for (int i = 0; i < n; i++) {
            unordered_map<int, int> freq;      // value -> freq
            unordered_map<int, int> cntFreq;   // freq -> count of values

            for (int j = i; j < n; j++) {
                int x = nums[j];

                int oldFreq = freq[x];
                if (oldFreq > 0) {
                    if (--cntFreq[oldFreq] == 0)
                        cntFreq.erase(oldFreq);
                }

                int newFreq = ++freq[x];
                cntFreq[newFreq]++;

                int distinct = freq.size();

                bool ok = false;

                if (distinct == 1) {
                    ok = true;
                } 
                else if (cntFreq.size() == 2) {
                    auto it = cntFreq.begin();

                    int f1 = it->first;
                    ++it;
                    int f2 = it->first;

                    int a = min(f1, f2);
                    int b = max(f1, f2);

                    if (b == 2 * a)
                        ok = true;
                }

                if (ok)
                    ans = max(ans, j - i + 1);
            }
        }

        return ans;
    }
};