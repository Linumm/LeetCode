class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> tmp;
        Combination(candidates, tmp, 0, target);
        return result;
    }

    void Combination(vector<int> candidates, vector<int>& current, int idx, int target_sum)
    {
        if (target_sum < 0)
            return;
        if (target_sum == 0) {
            result.push_back(current);
            return;
        }

        for (int i=idx; i<candidates.size(); i++) { // To prevent duplication, loop start with assigned index
            current.push_back(candidates[i]);
            Combination(candidates, current, i, target_sum-candidates[i]);
            current.pop_back();
        }
        // This loop allows, only "asscending order combination"
    }
};