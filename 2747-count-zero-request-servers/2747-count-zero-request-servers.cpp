class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs,
                             int x, vector<int>& queries) {

        int m = logs.size();
        int k = queries.size();

        // Sort logs according to time
        sort(logs.begin(), logs.end(),
             [](auto &a, auto &b) {
                 return a[1] < b[1];
             });

        // Store queries with their original indices
        vector<pair<int, int>> q;

        for (int i = 0; i < k; i++) {
            q.push_back({queries[i], i});
        }

        sort(q.begin(), q.end());

        vector<int> ans(k, 0);
        vector<int> freq(n + 1, 0);

        int left = 0;
        int right = 0;
        int active = 0;

        for (auto &query : q) {

            int time = query.first;
            int index = query.second;

            int start = time - x;

            // Add logs entering the window
            while (right < m && logs[right][1] <= time) {

                int server = logs[right][0];

                if (freq[server] == 0) {
                    active++;
                }

                freq[server]++;
                right++;
            }

            // Remove logs leaving the window
            while (left < right && logs[left][1] < start) {

                int server = logs[left][0];

                freq[server]--;

                if (freq[server] == 0) {
                    active--;
                }

                left++;
            }

            // Servers with zero requests
            ans[index] = n - active;
        }

        return ans;
    }
};