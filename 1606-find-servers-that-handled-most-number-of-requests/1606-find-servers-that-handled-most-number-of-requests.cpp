class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival,
                               vector<int>& load) {

        vector<int> count(k, 0);

        // Available servers
        set<int> available;

        for (int i = 0; i < k; i++) {
            available.insert(i);
        }

        // {finish time, server ID}
        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > busy;

        for (int i = 0; i < arrival.size(); i++) {

            // Release servers that have finished
            while (!busy.empty() &&
                   busy.top().first <= arrival[i]) {

                int server = busy.top().second;

                busy.pop();

                available.insert(server);
            }

            // All servers are busy
            if (available.empty()) {
                continue;
            }

            // Preferred server
            int target = i % k;

            // Find target or next available server
            auto it = available.lower_bound(target);

            // Circular wrapping
            if (it == available.end()) {
                it = available.begin();
            }

            int server = *it;

            // Assign request
            available.erase(it);

            count[server]++;

            // Calculate finishing time
            long long finishTime = arrival[i] + load[i];

            busy.push({finishTime, server});
        }

        // Find maximum requests handled
        int maxi = *max_element(count.begin(), count.end());

        vector<int> ans;

        for (int i = 0; i < k; i++) {
            if (count[i] == maxi) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};