class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();

        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        // initialize upper bound and left bound as 0
        for (int i=0; i<n+1; i++) 
            dp[i][0] = 0;
        for (int j=0; j<m+1; j++)
            dp[0][j] = 0;

        for (int i=1; i<n+1; i++) {
            for (int j=1; j<m+1; j++) {
                // dp[i][j] means when compared text1.substring(0,i) and text2.substring(0,j) there's common subseq with length dp[i][j]
                if (text1[i-1] == text2[j-1]) // because i and j start from 1 (we added 0 bounds)
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        return dp[n][m];
    }
};