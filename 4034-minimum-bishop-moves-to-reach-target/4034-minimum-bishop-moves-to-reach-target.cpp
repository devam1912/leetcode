class Solution {
public:
    int minBishopMoves(vector<int>& source, vector<int>& target) {
        int sr = source[0], sc = source[1];
        int tr = target[0], tc = target[1];

        // Different colors then bishop will never reach
        if ((sr + sc) % 2 != (tr + tc) % 2)
            return -1;

        // Same diagonal -> 1 move 
        if (abs(sr - tr) == abs(sc - tc))
            return 1;

        // Same color but different diagonal -> 2 moves
        return 2;
    }
};