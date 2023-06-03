class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) 
    {
        int n = edges.size();
        vector<int> dist_1(n, -1);
        vector<int> dist_2(n, -1);
        vector<bool> visited(n, false);

        bfs(node1, edges, visited, dist_1);
        fill(visited.begin(), visited.end(), false);
        bfs(node2, edges, visited, dist_2);

        int min_diff = INT_MAX;
        int min_idx = -1;
        for (int i=0; i<n; i++) {
            if (dist_1[i] != -1 && dist_2[i] != -1) {
                int dist_diff = max(dist_1[i], dist_2[i]); // Why choose max? : to compare distance of other nodes
                if (dist_diff < min_diff) {
                    min_idx = i;
                    min_diff = dist_diff;
                }
            }
        }
        return min_idx;
        
    }
    void bfs(int start, vector<int>& edges, vector<bool>& visited, vector<int>& dist)
    {
        queue<int> q;
        q.push(start);
        int distance = -1;

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            if (!visited[current]) {
                distance++;
                dist[current] = distance;
                visited[current] = true;
                int dst = edges[current];

                if (dst != -1 && !visited[dst]) {
                    q.push(dst);
                }
            }
        }
    }
};