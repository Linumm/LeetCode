class Solution {
public:
    int edgeScore(vector<int>& edges) {
        if (edges.size() == 0)
            return 0;
            
        int n = edges.size();
        vector<unsigned long> edge_point(n,0);

        for (int i=0; i<edges.size(); i++) {
            edge_point[edges[i]] += i;
        }
        unsigned long highest = 0;;
        int highest_edge;
        for (int i=0; i<n; i++) {
            if (edge_point[i] > highest) {
                highest = edge_point[i];
                highest_edge = i;
            }
        }

        return highest_edge;
    }
};