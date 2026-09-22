class Solution {
    int n, k;
    
    struct Node {
        int prod;
        int cnt[5];
    };
    
    vector<Node> seg;

    Node mergeNode(const Node &a, const Node &b) {
        Node res{};
        res.prod = (a.prod * b.prod) % k;

        for (int r = 0; r < k; r++) {
            res.cnt[r] = a.cnt[r];
        }

        for (int r = 0; r < k; r++) {
            int nr = (a.prod * r) % k;
            res.cnt[nr] += b.cnt[r];
        }

        return res;
    }

    void build(int p, int l, int r, vector<int>& nums) {
        if (l == r) {
            seg[p].prod = nums[l] % k;
            seg[p].cnt[seg[p].prod] = 1;
            return;
        }

        int mid = (l + r) / 2;

        build(p * 2, l, mid, nums);
        build(p * 2 + 1, mid + 1, r, nums);

        seg[p] = mergeNode(seg[p * 2], seg[p * 2 + 1]);
    }

    void update(int p, int l, int r, int pos, int val) {
        if (l == r) {
            seg[p] = Node{};
            seg[p].prod = val % k;
            seg[p].cnt[seg[p].prod] = 1;
            return;
        }

        int mid = (l + r) / 2;

        if (pos <= mid)
            update(p * 2, l, mid, pos, val);
        else
            update(p * 2 + 1, mid + 1, r, pos, val);

        seg[p] = mergeNode(seg[p * 2], seg[p * 2 + 1]);
    }

    Node query(int p, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr)
            return seg[p];

        int mid = (l + r) / 2;

        if (qr <= mid)
            return query(p * 2, l, mid, ql, qr);

        if (ql > mid)
            return query(p * 2 + 1, mid + 1, r, ql, qr);

        Node left = query(p * 2, l, mid, ql, qr);
        Node right = query(p * 2 + 1, mid + 1, r, ql, qr);

        return mergeNode(left, right);
    }

public:
    vector<int> resultArray(
        vector<int>& nums,
        int K,
        vector<vector<int>>& queries
    ) {
        n = nums.size();
        k = K;

        seg.resize(4 * n);

        build(1, 0, n - 1, nums);

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto &q : queries) {
            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            // Update persists
            nums[index] = value;
            update(1, 0, n - 1, index, value);

            // Get nums[start ... n-1]
            Node res = query(1, 0, n - 1, start, n - 1);

            ans.push_back(res.cnt[x]);
        }

        return ans;
    }
};