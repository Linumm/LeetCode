class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> tmp;
        vector<bool> visited(nums.size(), false);
        permutation(result, tmp, nums, visited);

        return result;
    }

    void permutation(vector<vector<int>>& result, vector<int>& current, vector<int> given, vector<bool>& visited)
    {
        if (current.size() == given.size()) {
            result.push_back(current);
            return;
        }

        for (int i=0; i<given.size(); i++) {
            if (!visited[i]) {
                visited[i] = true;
                current.push_back(given[i]); // push to make permutation
                permutation(result, current, given, visited);
                current.pop_back(); // pop to restart from other number
                visited[i] = false;
            }
        }
    }
};
