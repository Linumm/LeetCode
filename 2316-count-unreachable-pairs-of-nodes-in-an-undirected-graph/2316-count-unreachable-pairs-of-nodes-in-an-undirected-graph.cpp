class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        long long ans = 0;
        long long remained_num = n;
        vector<bool> visited(n, false);
        vector<vector<int>> adj(n);

        for (int i=0; i<edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        for (int i=0; i<n; i++) {
            if (!visited[i]) {
                long long components_num = dfs(i, adj, visited);
                ans += components_num * (remained_num - components_num); // Final count (I failed to calculate it by vector)
                remained_num -= components_num;
            }
        }

        return ans;
    }
    int dfs(int current, const vector<vector<int>>& adj, vector<bool>& visited)
    {
        visited[current] = true;
        int count = 1;
        for (auto dst: adj[current]) {
            if (!visited[dst]) {
                count += dfs(dst, adj, visited); // if it returns here, then not every case for dst
            }
        }
        return count;
    }
};