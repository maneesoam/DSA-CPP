class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {

        int n = items.size();

        vector<int> dp(budget + 1, 0);

        int mn = INT_MAX;

        for (auto &item : items) {

            int factor = item[0];
            int price = item[1];

            mn = min(mn, price);

            int cnt = 0;

            // Count free items
            for (auto &x : items) {
                if (x[0] % factor == 0) {
                    cnt++;
                }
            }

            // 0/1 Knapsack
            for (int j = budget; j >= price; j--) {

                dp[j] = max(dp[j],
                            dp[j - price] + cnt);
            }
        }

        int ans = 0;

        // Buy additional cheapest items
        for (int i = 0; i <= budget; i++) {

            ans = max(ans,
                      dp[i] + (budget - i) / mn);
        }

        return ans;
    }
};