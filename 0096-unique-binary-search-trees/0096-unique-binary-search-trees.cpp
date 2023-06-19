class Solution {
public:
    int numTrees(int n) {
        int dp[n+1];
        dp[0] = 1;
        dp[1] = 1;
        for (int i=2; i<n+1; i++) {
            int tmp = 0;
            for (int j=0; j<i; j++) { // Only care the number of left subtree nodes and right subtree nodes
                tmp += (dp[j] * dp[i-1-j]);
            }
            dp[i] = tmp;
        }
        
        return dp[n];
    }
};