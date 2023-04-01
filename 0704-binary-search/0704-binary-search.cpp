class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        int mid;
        // Usually mid = (left + right)/2
        // There was an issue of overflow that the left+right can go over the int's maximum expression. So there's other way : left + (right-left)/2
        
        while (left <= right) {
            mid = (int)(left + (right-left)/2);
            if (nums[mid] < target) left = mid + 1;
            else if (nums[mid] > target) right = mid - 1;
            else if (nums[mid] == target) return mid;
        }
        
        return -1;
    }
};