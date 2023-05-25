class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<int> empty_set;
        result.push_back(empty_set);
        if (nums.size() == 0)
            return result;

        for (int i=1; i<=nums.size(); i++) {
            vector<int> tmp;
            Combination(nums, tmp, i, 0);
        }

        return result;
    }
    void Combination(vector<int> nums, vector<int>& subset, int size, int dup_ctrl)
    {
        if (subset.size() == size) {
            result.push_back(subset);
            return;
        }
        for (int i=dup_ctrl; i<nums.size(); i++) {
            subset.push_back(nums[i]);
            Combination(nums, subset, size, i+1);
            subset.pop_back();
        }
    }
};