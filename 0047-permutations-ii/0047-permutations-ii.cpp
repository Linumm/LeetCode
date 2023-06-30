class Solution {
public:
    vector<vector<int>> ans;
    set<vector<int>> dup; // to check duplication
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> tmp;
        vector<bool> visited(nums.size(), false);

        Permutation(nums, tmp, visited);
        return ans;
    }
    void Permutation(const vector<int>& given, vector<int>& current, vector<bool>& visited)
    {
        if (current.size() == given.size() && dup.find(current) == dup.end()) {
            ans.push_back(current);
            dup.insert(current);
            return;
        }

        for (int i=0; i<given.size(); i++) {
            if (!visited[i]) {
                visited[i] = true;
                current.push_back(given[i]);
                Permutation(given, current, visited);
                current.pop_back();
                visited[i] = false;
            }
        }
    }
};