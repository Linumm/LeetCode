class Solution {
public:
    int num_node;
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        num_node = n;
        vector<int> ans(n, 0);
        vector<int> count(n, 1);

        vector<vector<int>> adj(n);

        for (int i=0; i<edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        // Two DFS
        /* 
        Point : in parent-child shape tree, parse to parent-side subtree and child-side subtree,
        then, ans[child] = ans[parent] + the number of parent-side subtree node.
        -> here, count is the number of tree   
        */
        dfs(0, -1, adj, ans, count);
        dfs2(0, -1, adj, ans, count);
        return ans;
    }
    void dfs(int current, int parent, const vector<vector<int>>& adj, vector<int>& ans, vector<int>& count)
    {
        for (int child: adj[current]) {
            if (child != parent) {
                dfs(child, current, adj, ans, count);
                count[current] += count[child];
                ans[current] += ans[child] + count[child];
            }
        }
    }
    void dfs2(int current, int parent, const vector<vector<int>>& adj, vector<int>& ans, vector<int>& count)
    {
        for (int child: adj[current]) {
            if (child != parent) {
                ans[child] = ans[current] - count[child] + (num_node - count[child]);
                dfs2(child, current, adj, ans, count);
            }
        }
    }
    
};

/* My greedy trial (Time limit exceeded)
class Solution {
public:
    int num_node;
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        num_node = n;
        vector<vector<int>> dist(n, vector<int>(n,0));
        vector<vector<int>> adj(n);
        for (int i=0; i<edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> visited(n,false);
        getAllDistFromSrc(0, 0, adj, visited, dist);

        vector<int> ans(n,0);
        for (int i=0; i<n; i++) {
            int sum = 0;
            for (int j=0; j<n; j++) {
                sum += dist[i][j];
            }
            ans[i] = sum;
        }

        return ans;
    }
    void getAllDistFromSrc(int parent, int current, const vector<vector<int>>& adj, vector<bool>& visited, vector<vector<int>>& dist)
    {
        visited[current] = true;
        if (parent != current) {
            dist[parent][current] = 1;
            dist[current][parent] = 1;
        }
        for (int i=0; i<num_node; i++) {
            if (i != parent && i != current) {
                dist[i][current] = dist[i][parent] + 1;
                dist[current][i] = dist[i][current];
            } 
        }
        for (int dst: adj[current]) {
            if (!visited[dst]) {
                getAllDistFromSrc(current, dst, adj, visited, dist);
            }
        }
    }
};
*/