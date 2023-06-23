class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 0) return false;
        if (nums.size() == 1) return true;
        int min_jump = 1;
        for (int i=nums.size()-2; i>=0; i--) { // Consider from the second last
            if (nums[i] >= min_jump) min_jump = 1;
            else min_jump++;
        }
        
        if (min_jump == 1) return true;
        else return false;
    }
};
// But it seems if we start from leftmost, we can just end quickly..