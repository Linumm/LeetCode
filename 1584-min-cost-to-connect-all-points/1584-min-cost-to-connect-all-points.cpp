class Solution {
public:
    int Find(vector<int>& disjoint_set, int id)
    {
        if (disjoint_set[id] < 0)
            return id;
        else
            return Find(disjoint_set, disjoint_set[id]);
    }
    int minCostConnectPoints(vector<vector<int>>& points)
    {
        int ps_size = points.size();
        int min_cost = 0;

        // Make disjoint_set's parent part
        vector<int> disjoint_set(ps_size, -1);
        // Make pair vector of <weight, <start_point, destination_point>>
        vector<pair<int, pair<int,int>>> edge_with_vertex;

        // Calculate all edge and push back to vector
        for (int i=0; i<ps_size; i++) {
            for (int j=i+1; j<ps_size; j++) {
                edge_with_vertex.push_back({abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]), {i, j}});
            }
        }

        // To get heap-like vector
        sort(edge_with_vertex.rbegin(), edge_with_vertex.rend());
        while (!edge_with_vertex.empty()) {
            pair<int,pair<int,int>> tmp = edge_with_vertex.back();
            int weight = tmp.first;
            int i = Find(disjoint_set, tmp.second.first);
            int j = Find(disjoint_set, tmp.second.second);
            edge_with_vertex.pop_back();
            
            // Without rank
            if (Find(disjoint_set, i) != Find(disjoint_set, j)) { // 이 부분 나중에 rank 제대로 구현해서 바꿔보기
                min_cost += weight;
                disjoint_set[i] += disjoint_set[j]; // Parent's rank is negative
                disjoint_set[j] = i; // Child point the parent's index, and its rank is represented by positive int
                
                if (disjoint_set[i] == -ps_size)
                    break;
            }
        }

        return min_cost;
    }
};