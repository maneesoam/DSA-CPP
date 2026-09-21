class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0);

        // dp[r] = number of subarrays ending at previous position
        // whose product % k = r
        vector<long long> dp(k, 0);

        for (int num : nums) {
            vector<long long> ndp(k, 0);

            // Start a new subarray with num
            ndp[num % k]++;

            // Extend previous subarrays
            for (int r = 0; r < k; r++) {
                if (dp[r]) {
                    int newR = (r * (num % k)) % k;
                    ndp[newR] += dp[r];
                }
            }

            // Every remaining subarray corresponds to one operation
            for (int r = 0; r < k; r++) {
                ans[r] += ndp[r];
            }

            dp = ndp;
        }

        return ans;
    }
};