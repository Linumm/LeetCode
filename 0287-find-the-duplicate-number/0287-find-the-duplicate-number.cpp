class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size(), slow = 0, fast = 0;
        slow = nums[slow];
        fast = nums[nums[fast]]; // to start from different idx with l

        while (slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]]; // 'fast' moves faster so double jump
        }
        // now we have to find parent that made to meet two pointers.
        // Collision point and duplicate points are different!
        slow = 0;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast]; 
        }
        return slow;
    }
};