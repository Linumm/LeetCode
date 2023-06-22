class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;
        int curr_pdct = 1;
        int left = 0, right = 0;
        int count = 0;
        for (right = 0; right < nums.size(); right++) {
            curr_pdct *= nums[right];
            while (curr_pdct >= k) {
                curr_pdct /= nums[left];
                left++;
            } // until this process, it's same with usual sliding window
            count += right - left + 1; // This should be come up with finding pattern.
            // if you add one element then "len" number of subarray follow

            // + This is "subarray", not subset
        }
        return count;
    }
};