class Solution {
public:
    vector<int> ans;
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        //Topological sort (transpose graph first)
        // If there's a cycle, then every nodes in the cycle is not safe node (or terminal)
        int n = graph.size();
        vector<vector<int>> adj_trp(n);
        vector<int> idg(n, 0);
        for (int i=0; i<n; i++) {
            for (auto dst: graph[i]) {
                adj_trp[dst].push_back(i);
                idg[i]++;
            }
        }

        queue<int> q;
        for (int i=0; i<n; i++) {
            if (idg[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int current = q.front();
            q.pop();
            ans.push_back(current);

            for (auto dst: adj_trp[current]) {
                idg[dst]--;
                if (idg[dst] == 0) q.push(dst);
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};
// safe node-> every possible paths should be connected with another safe node or terminal node.