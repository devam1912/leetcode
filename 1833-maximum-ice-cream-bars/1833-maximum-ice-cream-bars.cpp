class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        vector<int> freq(100001, 0);

        for (int cost : costs)
            freq[cost]++;

        int count = 0;

        for (int cost = 1; cost <= 100000; cost++) {
            if (!freq[cost]) continue;

            //coins / cost = maximum bars affordable at this price
            //freq[cost] = bars available at this price
            //Take the minimum of both

            int canBuy = min(freq[cost], coins / cost);

            count += canBuy;
            coins -= canBuy * cost;

            if (coins < cost) break;
        }

        return count;
    }
};