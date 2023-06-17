class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int current_sum = 0;
        int max_sum = INT_MIN;
        for (int i: nums) {
            current_sum = max(i, current_sum + i);
            max_sum = max(max_sum, current_sum);
        }
        return max_sum;
    }
};
/* Memoization
int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> sum(n, 0);
        sum[0] = nums[0];

        for (int i=1; i<n; i++) {
            if (sum[i-1] <= 0)
                sum[i] = nums[i];
            else
                sum[i] = sum[i-1] + nums[i];
        }
        sort(sum.begin(), sum.end());
        return sum.back();
    }
*/