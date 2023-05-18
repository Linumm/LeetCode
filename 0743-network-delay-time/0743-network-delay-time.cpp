class Solution {
public:
    int _MAX = 100000; // Max limit of input weight sum
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Adjacent matrix with weight value
        vector<vector<pair<int,int>>> adj(n);// pair: {dst, weight}
        vector<int> distance(n, _MAX); // distance from k
        distance[k-1] = 0;
        
        vector<bool> visited(n, false);
        for (int i=0; i<times.size(); i++) {
            adj[times[i][0]-1].push_back(make_pair(times[i][1]-1, times[i][2]));
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> heap;
        //heap pair : {distance, vertex_id}
        heap.emplace(make_pair(0, k-1));
        
        while (!heap.empty()) {
            auto current = heap.top();
            heap.pop();
            if (!visited[current.second]) {
                for (int i=0; i<adj[current.second].size(); i++) {
                    int src = current.second;
                    int dst = adj[current.second][i].first;
                    int weight = adj[current.second][i].second;
                    if (distance[dst] > distance[src] + weight) {
                        distance[dst] = distance[src] + weight;
                        heap.emplace(make_pair(distance[dst], dst));
                    }
                }
                visited[current.second] = true;
            }
        }

        // Now all distance value reseted
        sort(distance.rbegin(), distance.rend());

        if (distance[0] == _MAX) {
            return -1;
        }
        

        
        return distance[0];
    }
};