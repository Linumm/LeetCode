/*
class Solution { //DFS
public:
    int max_len = -1;
    void dfs(int current, vector<int>& edges, vector<bool>& visited, vector<int>& path, int len)
    {
        visited[current] = true;
        path[current] = len;
        int dst = edges[current];
        
        if (dst != -1) {
            if (!visited[dst])
                dfs(dst, edges,visited, path, len+1);
            else if (path[dst] != 0) { // if visited before, then when?
                max_len = max(max_len, (len + 1 - path[dst]));
            }
        }
        path[current] = 0;
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<bool> visited(n, false);
        vector<int> path(n, 0);
        
        for (int i=0; i<n; i++) {
            if (!visited[i])
                dfs(i, edges, visited, path, 1);
        }

        return max_len;
    }
};
*/


class Solution { //Kosaraju 
public:
    int longestCycle(vector<int>& edges) 
    {
        int n = edges.size();
        vector<bool> visited(n, false);
        vector<vector<int>> transposed_adj(n);
        stack<int> node_stk;

        for (int i=0; i<n; i++) {
            if (!visited[i])
                fillStack(i, edges, visited, node_stk);
            if (edges[i] != -1)
                transposed_adj[edges[i]].push_back(i);
        }
        
        fill(visited.begin(), visited.end(), false);
        int max_len = 1;
        while (!node_stk.empty()) {
            int current = node_stk.top();
            node_stk.pop();

            if (!visited[current]) {
                int tmp = dfs(current, transposed_adj, visited);
                if (tmp > max_len)
                    max_len = tmp;
                
            }
        }
        if (max_len == 1) return -1;
        else return max_len;
    }
    void fillStack(int current, vector<int>& edges, vector<bool>& visited, stack<int>& stk)
    {
        visited[current] = true;
        if (edges[current] != -1 && !visited[edges[current]]) {
            fillStack(edges[current], edges, visited, stk);
        }
        stk.push(current);
    }
    int dfs(int current, vector<vector<int>>& adj, vector<bool>& visited)
    {
        visited[current] = true;
        for (auto dst: adj[current]) {
            if (!visited[dst])
                return 1 + dfs(dst, adj, visited);
        }
        return 1;
    }
};
