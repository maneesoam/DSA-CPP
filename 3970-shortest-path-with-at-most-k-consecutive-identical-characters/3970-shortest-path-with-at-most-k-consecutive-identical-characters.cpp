class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges,
                     string labels, int k) {

        // Step 1: Create adjacency list
        vector<vector<pair<int, int>>> adj(n);

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({v, w});
        }

        // Step 2: Initialize distance array
        const long long INF = LLONG_MAX;

        vector<vector<long long>> dist(
            n, vector<long long>(k + 1, INF)
        );

        // {distance, node, consecutive count}
        priority_queue<
            tuple<long long, int, int>,
            vector<tuple<long long, int, int>>,
            greater<tuple<long long, int, int>>
        > pq;

        // Starting node
        dist[0][1] = 0;
        pq.push({0, 0, 1});

        // Step 3: Dijkstra's Algorithm
        while (!pq.empty()) {

            auto [d, u, cnt] = pq.top();
            pq.pop();

            // Ignore outdated states
            if (d != dist[u][cnt])
                continue;

            // Explore neighbouring nodes
            for (auto &[v, w] : adj[u]) {

                int newCount;

                if (labels[u] == labels[v]) {
                    newCount = cnt + 1;
                }
                else {
                    newCount = 1;
                }

                // Check constraint
                if (newCount > k)
                    continue;

                long long newDist = d + w;

                // Update shortest distance
                if (newDist < dist[v][newCount]) {

                    dist[v][newCount] = newDist;

                    pq.push({
                        newDist,
                        v,
                        newCount
                    });
                }
            }
        }

        // Step 4: Find minimum cost to destination
        long long ans = INF;

        for (int cnt = 1; cnt <= k; cnt++) {
            ans = min(ans, dist[n - 1][cnt]);
        }

        // Step 5: Return answer
        if (ans == INF)
            return -1;

        return (int)ans;
    }
};