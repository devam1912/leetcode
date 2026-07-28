class Solution {
public:
    string smallestPalindrome(string s) {
        unordered_map<char, int> mp;

        for (char c : s)
            mp[c]++;

        string left = "";
        string mid = "";

        for (char c = 'a'; c <= 'z'; c++) {
            if (mp[c] % 2 == 1)
                mid += c;          
            left.append(mp[c] / 2, c);
        }

        string right = left;
        reverse(right.begin(), right.end());

        return left + mid + right;
    }
};