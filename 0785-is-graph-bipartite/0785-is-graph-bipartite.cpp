class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> color(n, false);
        for (int i=0; i<n; i++) {
            if (!bfs(i, graph, color))
                return false;
        }
        return true;
    }
    bool bfs(int current, const vector<vector<int>>& graph, vector<bool>& color)
    {
        queue<int> q;
        q.push(current);
        while (!q.empty()) {
            int current = q.front();
            q.pop();

            for (int dst: graph[current]) {
                if (!color[dst]) {
                    color[dst] = !color[current]; // Difference with normal bfs 
                    q.push(dst);
                }
                else if (color[dst] == color[current])
                    return false;
            }
        }
        return true;
    }
};