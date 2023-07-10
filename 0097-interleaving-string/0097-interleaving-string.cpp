class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) 
    {
        if (s1.length() + s2.length() != s3.length())
            return false;

        int m = s1.length(), n = s2.length();
        bool dp[m+1][n+1];

        for (int i=0; i<=m; i++) {
            for (int j=0; j<=n; j++) {
                int k = i + j;
                if (i==0 && j==0) 
                    dp[i][j] = true;
                else if (i==0) 
                    dp[i][j] = (dp[i][j-1] && s2[j-1] == s3[k-1]);
                else if (j==0) 
                    dp[i][j] = (dp[i-1][j] && s1[i-1] == s3[k-1]);
                else
                    dp[i][j] = (dp[i-1][j] && s1[i-1] == s3[k-1]) || (dp[i][j-1] && s2[j-1] == s3[k-1]);
            }
        }
        /*
        - fix dp[0][0] = 1
        - i, j idx -> check i-1, j-1 character
        - else에서는, i-1이나 j-1 둘 중 맞는 곳에서 이어가야하므로 OR
        - 너무 어렵다.. Recursion이 바로 떠오르는 해답인데 어째서 TLE가 뜨는지 의문
        */
        return dp[m][n];
    }
};

// abbc, db, adbbcb


/* TLE
public:
    bool check(vector<vector<int>>& dp, string& s1, string& s2, string& s3, int i, int j, int k)
    {
        if (i==s1.length() && j == s2.length() && k == s3.length()) // after checked every character of three
            return true;
        if (k==s3.length()) return false;

        if (dp[i][j] != 0) return dp[i][j];
        if (s1[i] == s3[k] && check(dp, s1, s2, s3, i+1, j, k+1)) { // this part is core, recursion in condition
            dp[i][j] = 1;
            return true;
        }
        if (s2[j] == s3[k] && check(dp, s1, s2, s3, i, j+1, k+1)) {
            dp[i][j] = 1;
            return true;
        }
        return false;
    }
    bool isInterleave(string s1, string s2, string s3) 
    {
        if (s1.length() + s2.length() != s3.length()) return false;
        int m = s1.length(), n = s2.length();
        int i = 0, j = 0, k = 0; // index for each string
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        return check(dp, s1, s2, s3, i, j, k);
    }
};

*/