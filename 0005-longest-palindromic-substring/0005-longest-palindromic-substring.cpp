class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() <= 1)
            return s;

        int n = s.length();
        int max_start = 0;
        int end = 1; // length of substr
        vector<vector<bool>> dp(n, vector<bool>(n,false));
        
        for (int i=0; i<n; i++) // length 1
            dp[i][i] = true;
        
        for (int i=0; i<n-1; i++) { // length 2
            if (s[i] == s[i+1]) {
                dp[i][i+1] = true;
                max_start = i;
                end = 2;
            }
        }

        for (int i=2; i<n; i++) { // length >= 3
            for (int j=0; j<n-i; j++) {
                // it's about checking dp[j][j+i]
                if (s[j] == s[j+i] && dp[j+1][j+i-1]) {
                    dp[j][j+i] = true;
                    max_start = j;
                    end = i+1;
                }
            }
        }
        
        return s.substr(max_start, end);
    }
};