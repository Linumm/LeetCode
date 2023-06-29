class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        int ans = 1;
        vector<int> dp(n, 1);
        unordered_map<int,int> um;

        for (int i=0; i<n; i++) { // O n
            int tmp = 1;
            if (um.find(arr[i]-difference) != um.end()) { // if arr[i]-difference is not in um
                tmp = 1+um[arr[i]-difference];
            }
            um[arr[i]] = tmp;
            ans = max(ans, um[arr[i]]);
        }

        return ans;
    }
};
/* Time-out
int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        int ans = 1;
        vector<int> dp(n, 1);

        for (int i=0; i<n; i++) { // O n^2
            for (int j=0; j<i; j++) {
                if (arr[i]-arr[j] == difference) {
                    dp[i] = max(dp[i], 1+dp[j]);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
*/