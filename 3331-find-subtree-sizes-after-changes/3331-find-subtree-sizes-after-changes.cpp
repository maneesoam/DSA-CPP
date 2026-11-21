class Solution {
public:

    vector<int> newParent;

    void dfs1(int node, vector<vector<int>>& adj,
              string& s, vector<int>& last) {

        int c = s[node] - 'a';
        int old = last[c];

        if(old != -1) {
            newParent[node] = old;
        }

        last[c] = node;

        for(int child : adj[node]) {
            dfs1(child, adj, s, last);
        }

        last[c] = old;
    }

    int dfs2(int node, vector<vector<int>>& adj,
             vector<int>& ans) {

        int size = 1;

        for(int child : adj[node]) {
            size += dfs2(child, adj, ans);
        }

        ans[node] = size;
        return size;
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {

        int n = parent.size();

        vector<vector<int>> adj(n);

        for(int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        newParent = parent;

        vector<int> last(26, -1);

        dfs1(0, adj, s, last);

        vector<vector<int>> newTree(n);

        for(int i = 1; i < n; i++) {
            newTree[newParent[i]].push_back(i);
        }

        vector<int> ans(n, 0);

        dfs2(0, newTree, ans);

        return ans;
    }
};