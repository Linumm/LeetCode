class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = 0, curr_sum = 0;
        int min_len = INT_MAX;

        for (right = 0; right < n; right++) {
            curr_sum += nums[right];

            while (curr_sum >= target) { // Move to left side while current sum is bigger than target
                min_len = min(min_len, right-left+1); // this should be in "left moving loop" so that we can get Minimum value
                curr_sum -= nums[left]; 
                left++;
            }
        }
        if (min_len == INT_MAX) return 0;
        else return min_len;
    }
};
/*
<Sliding Window>
If current sum is bigger than target, move leftptr
*/