class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> answer;
        if (n == 1) {
            answer.push_back(0);
            return answer;
        }
        vector<vector<int>> pre(n);
        for (auto edge: edges) {
            pre[edge[0]].push_back(edge[1]);
            pre[edge[1]].push_back(edge[0]);
        }
        int random_start = edges[0][0]; // starts with random vertex
        int leaf1 = getMostFar(pre, random_start).back(); // get the farthest vertex random_start
        int leaf2 = getMostFar(pre, leaf1).back(); // get the farthest vertex from leaf1

        // Now the route len between leaf1 and leaf2 is radius of this tree
        // get the median of route from leaf1 to leaf2
        vector<int> tmp = targetRoute(pre, leaf1, leaf2); 
        int tmp_size = tmp.size();
        if (tmp_size % 2 == 0) {
            answer.push_back(tmp[tmp_size/2]);
            answer.push_back(tmp[tmp_size/2 - 1]);
        }
        else {
            answer.push_back(tmp[tmp_size/2]);
        }
        return answer;
    }
    vector<int> getMostFar(vector<vector<int>> pre, int start)
    {
        // By BFS
        vector<bool> visited(pre.size(), false);
        queue<int> q;
        vector<int> visit_order;

        q.push(start);
        while (!q.empty()) {
            int current = q.front();
            visit_order.push_back(current);
            q.pop();

            if (!visited[current]) {
                visited[current] = true;
                for (int i=0; i<pre[current].size(); i++) {
                    if(!visited[pre[current][i]])
                        q.push(pre[current][i]);
                }
            }
        }
        return visit_order;
    }

    vector<int> targetRoute(vector<vector<int>> pre, int start, int target)
    {
        vector<bool> visited(pre.size(), false);
        stack<int> stk;
        vector<int> parent(pre.size());
        vector<int> route;

        stk.push(start);
        while (!stk.empty()) {
            int current = stk.top();
            stk.pop();

            if (current == target) {
                while (current != start) {
                    route.push_back(current);
                    current = parent[current];
                }
                route.push_back(start);
                return route;
            }
            if (!visited[current]) {
                visited[current] = true;
                for (auto dst: pre[current]) {
                    if (!visited[dst])
                        parent[dst] = current;
                        stk.push(dst);
                }
            }
        }
        return route;
    }

};