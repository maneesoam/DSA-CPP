class Solution {
public:
    int minimumChanges(string s, int k) {

        int n = s.size();

        const int INF = 1e9;

        vector<vector<int>> cost(n, vector<int>(n, INF));

        // PART 1: Precompute cost of every substring

        for (int l = 0; l < n; l++) {

            for (int r = l + 1; r < n; r++) {

                int len = r - l + 1;

                // Try every valid divisor
                for (int d = 1; d < len; d++) {

                    if (len % d != 0)
                        continue;

                    int changes = 0;

                    // Check all groups
                    for (int offset = 0; offset < d; offset++) {

                        int left = l + offset;
                        int right = r - (d - 1 - offset);

                        // Compare symmetric elements
                        while (left < right) {

                            if (s[left] != s[right]) {
                                changes++;
                            }

                            left += d;
                            right -= d;
                        }
                    }

                    cost[l][r] = min(cost[l][r], changes);
                }
            }
        }

        // PART 2: Dynamic Programming

        vector<vector<int>> dp(
            k + 1,
            vector<int>(n + 1, INF)
        );

        dp[0][0] = 0;

        for (int parts = 1; parts <= k; parts++) {

            for (int i = 2 * parts; i <= n; i++) {

                for (int j = 2 * (parts - 1); j <= i - 2; j++) {

                    dp[parts][i] = min(
                        dp[parts][i],
                        dp[parts - 1][j] + cost[j][i - 1]
                    );
                }
            }
        }

        return dp[k][n];
    }
};