class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        int element;
        vector<int> unique;
        unique.push_back(nums[0]);
        for (int i=0; i<nums.size(); i++) {
            element = nums[i];
            if (unique.back() != element)
                unique.push_back(element);
        }

        nums = unique;
        return unique.size();
        
    }
};