class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
		if( n<= 1) return 0;
		vector<int> buy(n, 0),cd(n, 0),sell(n, 0);
		cd[0] = -prices[0],buy[0] = 0,sell[0] = INT_MIN;
        
		for (int i = 1; i < n; i++) {
			buy[i]  = max(buy[i - 1], sell[i - 1]);
			cd[i]   = max(cd[i - 1], buy[i - 1] - prices[i]);
			sell[i] = cd[i - 1] + prices[i];
		}
		return max(buy[n-1], sell[n-1]);
    }
};
