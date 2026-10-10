class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1,
                               vector<int>& nums2,
                               int k1, int k2) {
        int n = nums1.size();
        long long k = 1LL * k1 + k2;

        vector<int> diff(n);
        long long total = 0;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            total += diff[i];
        }

        // If we can remove every difference
        if (k >= total)
            return 0;

        sort(diff.begin(), diff.end(), greater<int>());

        // Add a zero at the end for easier processing
        diff.push_back(0);

        for (int i = 0; i < n; i++) {
            long long count = i + 1;
            long long height = diff[i] - diff[i + 1];
            long long cost = count * height;

            if (k >= cost) {
                // Reduce the first i+1 differences to diff[i+1]
                k -= cost;
            } else {
                // Reduce the largest differences in one batch
                long long reduction = k / count;
                long long remainder = k % count;

                long long level = diff[i] - reduction;
                long long ans = 0;

                // Values already reduced to the common level
                for (int j = 0; j <= i; j++) {
                    long long x = min((long long)diff[j], level);
                    ans += x * x;
                }

                // Some values receive one additional reduction
                for (int j = 0; j <= i; j++) {
                    long long x = min((long long)diff[j], level);
                    if (x == level && remainder > 0) {
                        ans += (level - 1) * (level - 1) - level * level;
                        remainder--;
                    }
                }

                for (int j = i + 1; j < n; j++) {
                    ans += 1LL * diff[j] * diff[j];
                }

                return ans;
            }
        }

        return 0;
    }
};