class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int hold = -prices[0];  // Start by buying first stock
        int cash = 0;           // Start with no profit
        
        for (int i = 1; i < prices.size(); i++) {
            int prevHold = hold;  // Save old state before updating
            
            hold = max(hold, cash - prices[i]);
            // Option 1: Keep holding (do nothing)
            // Option 2: Buy today (cash - prices[i])
            // Pick whichever gives more profit
            
            cash = max(cash, prevHold + prices[i] - fee);
            // Option 1: Stay idle (do nothing)
            // Option 2: Sell today (hold profit + sale price - fee)
            // Pick whichever gives more profit
        }
        
        return cash;
    }
};