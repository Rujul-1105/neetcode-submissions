class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int n = prices.size();

        int i = 0;
        int j = 0;

        while (j < n) {
            if (prices[j] > prices[i]) {
                ans = max(ans, prices[j] - prices[i]);
            } else {
                i = j; // 
            }
            j++;
        }

        return ans;
        
    }
};
