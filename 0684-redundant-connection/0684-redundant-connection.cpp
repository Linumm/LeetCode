class Solution { // Union-set
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> redundant_edges;
        redundant_edges.push_back({});
        vector<vector<int>> union_set(n, vector<int>(2));
        // {root, rank}
        for (int i=0; i<n; i++) {
            union_set[i][0] = i;
            union_set[i][1] = 0;
        }

        for (auto edge: edges) {
            int src = edge[0];
            int dst = edge[1];
            int src_root = FindRoot(union_set, src);
            int dst_root = FindRoot(union_set, dst);
            if (src_root == dst_root) {
                redundant_edges.push_back(edge);
                continue;
            }
            else { // if two are in different set, link
                if (union_set[src_root][1] >= union_set[dst_root][1]) {// if src rank is higher
                    union_set[dst_root][0] = src; // link
                    union_set[src][1]++; // rank++
                }
                else {
                    union_set[src_root][0] = dst;
                    union_set[dst][1]++;
                }
            }
        }
        return redundant_edges.back();
    }
    int FindRoot(vector<vector<int>> union_set, int target)
    {
        int tmp = target;
        while (union_set[tmp][0] != tmp) {
            tmp = union_set[tmp][0];
        }
        return tmp;
    }
};