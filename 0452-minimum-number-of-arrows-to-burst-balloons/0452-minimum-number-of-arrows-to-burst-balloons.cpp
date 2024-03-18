class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        
        // Sort the vector first to easily check overlapped area.
        sort(points.begin(), points.end());

        int min_arrow = points.size() + 1;
        int start = points[0][0];
        int end = points[0][1];

        for (auto v: points) {
            if (end >= v[0]) { // if there's overlapped area
                start = v[1];
                if (end > v[1])
                    end = v[1];
                
                min_arrow--;
            }
            else { // separated, so new area must be set
                start = v[0];
                end = v[1];
            }
        }

        return min_arrow;
    }
};