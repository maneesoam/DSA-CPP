class Solution {
public:
    bool isRotation(vector<int>& a, vector<int>& b) {
        int k = a.size();
        vector<int> lps(k, 0);

        for (int i = 1, len = 0; i < k;) {
            if (b[i] == b[len]) {
                lps[i++] = ++len;
            } else if (len) {
                len = lps[len - 1];
            } else {
                lps[i++] = 0;
            }
        }

        for (int i = 0, j = 0; i < 2 * k - 1;) {
            int x = a[i % k];

            if (x == b[j]) {
                i++;
                j++;
                if (j == k) return true;
            } else if (j) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }

        return false;
    }

    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        int ans = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k != 0) continue;

            bool ok = true;

            for (int i = 0; i < n; i += k) {
                vector<int> a(nums.begin() + i, nums.begin() + i + k);
                vector<int> b(sorted.begin() + i, sorted.begin() + i + k);

                if (!isRotation(a, b)) {
                    ok = false;
                    break;
                }
            }

            if (ok) ans += k;
        }

        return ans;
    }
};