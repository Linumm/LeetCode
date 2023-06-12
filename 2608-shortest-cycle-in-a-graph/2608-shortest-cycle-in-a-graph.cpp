class Solution {
public:
    int min_len;
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        min_len = INT_MAX;
        for (auto edge: edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        for (int i=0; i<n; i++) { // why "n" case?
            vector<int> dist(n, INT_MAX);
            vector<int> parent(n, -1);
            dist[i] = 0;
            queue<int> q;

            q.push(i);
            while (!q.empty()) {
                int current = q.front();
                q.pop();
                for (int dst: adj[current]) {
                    if (dist[dst] == INT_MAX) {
                        dist[dst] = dist[current] + 1;
                        parent[dst] = current;
                        q.push(dst);
                    }
                    else if (parent[dst] != current && parent[current] != dst) {
                        min_len = min(min_len, dist[current] + dist[dst] + 1); // because of this.
                    }
                }
            }
        }
        /*
        Imagine as a tree, but the computation above cannot get middle-cycle len, so take every "n" case.
        */

        if (min_len == INT_MAX) return -1;
        return min_len;
    }
};
/*
class Solution { // Union Find Try- failure : Because it cannot calculate smaller cycle size
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<int> forest(n);
        vector<int> rank(n, 0);
        for (int i=0; i<n; i++) {
            forest[i] = i;
        }
        int min_len = INT_MAX;
        for (auto& edge: edges) {
            int x = edge[0];
            int y = edge[1];
            int x_root = findRoot(forest, x);
            int y_root = findRoot(forest, y);

            if (x_root == y_root) {
                int cycle_len = rank[x_root] + 1;
                min_len = min(min_len, cycle_len);
                continue;
            }
            else {
                if (rank[x_root] >= rank[y_root]) {
                    forest[y_root] = x_root;
                    rank[x_root]++;
                }
                else {
                    forest[x_root] = y_root;
                    rank[y_root]++;
                }
            }
        }
        if (min_len == INT_MAX) return -1;
        else return min_len;
    }
    int findRoot(const vector<int>& v, int x)
    {
        int tmp = x;
        while (tmp != v[tmp]) {
            tmp = v[tmp];
        }
        return tmp;
    }
};
*/