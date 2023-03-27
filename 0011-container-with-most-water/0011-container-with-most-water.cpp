class Solution {
public:
    int maxArea(vector<int>& height) {
        int leftP = 0;
        int rightP = height.size() -1;
        int waterAmount = 0;

        while (leftP < rightP) {
            waterAmount = max(waterAmount, ((rightP - leftP) * min(height[leftP], height[rightP])));
            if (height[leftP] <= height[rightP]) 
                leftP ++;
            else if (height[leftP] >= height[rightP]) 
                rightP --;
        }

        return waterAmount;
    }
};

// Maximum water amount -> maximum distance, maximum water height.
// By using 2 pointers, times * 1/2 for searching
