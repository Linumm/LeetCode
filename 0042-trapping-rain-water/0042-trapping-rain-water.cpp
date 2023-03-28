class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int maxLeft = 0, maxRight = 0;
        int waterAmount = 0;

        while (left <= right) {
            if (height[left] <= height[right]) {
                maxLeft = max(maxLeft, height[left]);
                waterAmount += maxLeft - height[left];
                left++;
            }
            else {
                maxRight = max(maxRight, height[right]);
                waterAmount += maxRight - height[right];
                right--;
            }
        }

        return waterAmount;
    }
};