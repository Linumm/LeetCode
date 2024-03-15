class Solution { // Two pointer
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int left = 1;
        int right = 1;
        int l_idx = 0;
        int r_idx = n-1;

        vector<int> res(n, 1);

        // Core is that both pointer only save the each's backward cumulative product.
        while (l_idx != n && r_idx != -1) {
            res[l_idx] *= left;
            res[r_idx] *= right;

            left *= nums[l_idx];
            right *= nums[r_idx];

            l_idx++;
            r_idx--;
        }

        return res;
    }
};