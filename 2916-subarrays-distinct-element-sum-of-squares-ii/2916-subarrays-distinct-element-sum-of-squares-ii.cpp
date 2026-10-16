class Solution {
public:
    int sumCounts(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        int n = nums.size();
        vector<long long> sum(4 * n), sq(4 * n), lazy(4 * n);
        unordered_map<int, int> last;
        long long ans = 0;

        function<void(int,int,int)> push = [&](int node, int l, int r) {
            if (!lazy[node]) return;
            int mid = (l + r) / 2;
            for (int child : {node * 2, node * 2 + 1}) {
                int len = (child == node * 2) ? mid - l + 1 : r - mid;
                long long d = lazy[node];
                sq[child] = (sq[child] + 2 * d * sum[child] + d * d % MOD * len) % MOD;
                sum[child] = (sum[child] + d * len) % MOD;
                lazy[child] += d;
            }
            lazy[node] = 0;
        };

        function<void(int,int,int,int,int)> update =
        [&](int node, int l, int r, int ql, int qr) {
            if (ql > r || qr < l) return;
            if (ql <= l && r <= qr) {
                long long d = 1, len = r - l + 1;
                sq[node] = (sq[node] + 2 * sum[node] + len) % MOD;
                sum[node] = (sum[node] + len) % MOD;
                lazy[node]++;
                return;
            }
            push(node, l, r);
            int mid = (l + r) / 2;
            update(node * 2, l, mid, ql, qr);
            update(node * 2 + 1, mid + 1, r, ql, qr);
            sum[node] = (sum[node * 2] + sum[node * 2 + 1]) % MOD;
            sq[node] = (sq[node * 2] + sq[node * 2 + 1]) % MOD;
        };

        for (int i = 0; i < n; i++) {
            int p = last.count(nums[i]) ? last[nums[i]] : -1;
            update(1, 0, n - 1, p + 1, i);
            last[nums[i]] = i;
            ans = (ans + sq[1]) % MOD;
        }
        return ans;
    }
};