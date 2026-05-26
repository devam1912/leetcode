class Solution {
public:
    int characterReplacement(string s, int k) {

        int n = s.size();
        int left = 0;
        int right = 0;
        int maxCount = 0;
        int length = 0;
        vector<int> freq(26, 0);
        while (right < n) 
        {
            freq[s[right] - 'A']++;
            maxCount = max(maxCount, freq[s[right] - 'A']);
            while ((right - left + 1) - maxCount > k) {
                freq[s[left] - 'A']--;
                left++;
            }
            length = max(length, right - left + 1);
            right++;
        }
        return length;
    }
};