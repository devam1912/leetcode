
public class Solution {
    public long MinimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long common = Math.Min(need1, need2);

        long total = common * Math.Min((long)costBoth, (long)cost1 + cost2);

        if (need1 > need2) {
            total += (long)(need1 - need2) * Math.Min(cost1, costBoth);
        } else {
            total += (long)(need2 - need1) * Math.Min(cost2, costBoth);
        }

        return total;
    }
}
