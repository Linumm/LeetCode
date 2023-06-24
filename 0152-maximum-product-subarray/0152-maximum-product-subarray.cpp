class Solution {
public:
    int maxProduct(vector<int>& nums) { // Two-pointer 
        int n= nums.size();
        int ans = nums[0], left = 1, right = 1;

        for (int i=0; i<n; i++) {
            left = left * nums[i];
            right = right * nums[n-1-i];

            int curr_max = max(left, right);
            ans = max(ans, curr_max);
            if (left == 0) left = 1;
            if (right == 0) right = 1;
        }

        return ans;
    }
};

/* Memory exceeded
int maxProduct(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int n = nums.size();
        int max_pdct = INT_MIN;
        
        // Initialize table
        vector<vector<int>> dp(n, (vector<int>(n,1)));
        for (int i=0; i<n; i++) {
            dp[i][i] = nums[i];
            max_pdct = max(max_pdct, nums[i]);
        }

        for (int i=0; i<n; i++) {
            int row_max = INT_MIN;
            for (int j=i+1; j<n; j++) {
                dp[i][j] = dp[i][j-1] * nums[j];
                row_max = max(row_max, dp[i][j]);
            }
            max_pdct = max(max_pdct, row_max);
        }
        return max_pdct;
    }
*/