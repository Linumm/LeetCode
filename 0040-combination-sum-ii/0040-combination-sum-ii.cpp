class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> tmp;
        sort(candidates.begin(), candidates.end());
        Combination(candidates, tmp, 0, target, 0);
        return result;
    }
    void Combination(vector<int> given, vector<int>& current, int sum, int target, int dup_ctrl)
    {
        if (sum > target) {
            return;
        }
        if (sum == target) {
            result.push_back(current);
            return;
        }
        for (int i=dup_ctrl; i<given.size(); i++) {
            if (i>dup_ctrl && given[i] == given[i-1]) //Skip procedure to prevent duplication
                continue;
            current.push_back(given[i]);
            Combination(given, current, sum+given[i], target, i+1);
            current.pop_back();
        }
    }
};