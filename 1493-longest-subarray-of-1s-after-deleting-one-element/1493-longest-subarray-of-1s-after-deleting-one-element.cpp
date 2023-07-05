class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        // Subarray
        int zero_count = 0;
        int max_len = INT_MIN;
        int l = 0;

        for (int r=0; r<nums.size(); r++) {
            if (nums[r] == 0) zero_count++;
            while (zero_count > 1) { // Move left ptr until zero_count < 2
                if (nums[l] == 0) zero_count--;
                l++;
            }

            max_len = max(max_len, r-l); // r-l +1 -1 (bcs of dcare of zero)
        }

        return max_len;
    }
};