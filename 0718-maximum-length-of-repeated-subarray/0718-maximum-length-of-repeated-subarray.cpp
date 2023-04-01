class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int max_len = 0;
        vector<vector<int>> len(m+1, vector<int>(n+1));

        for (int i=m-1; i>=0; i--) {
            for (int j=n-1; j>=0; j--) {
                if (nums1[i] == nums2[j]) len[i][j] = 1 + len[i+1][j+1];
                else len[i][j] = 0;
                max_len = max(max_len, len[i][j]);
            }
        }

        return max_len;
    }
};
//Tabulation.