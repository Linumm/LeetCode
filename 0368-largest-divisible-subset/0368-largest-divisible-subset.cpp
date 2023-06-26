class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
				sort(nums.begin(), nums.end());
        int n = nums.size(), ans = INT_MIN, max_idx = 0;
				vector<int> dp(n,1); // dp[i] = max_len
				vector<int> parent(n,-1); // pointing parent idx 
				
				for (int i=0; i<n; i++) {
					for (int prev_idx=0; prev_idx<i; prev_idx++) {
						if (nums[i] % nums[prev_idx] == 0 && dp[i] < 1 + dp[prev_idx]) {
							dp[i] = 1 + dp[prev_idx];
							parent[i] = prev_idx;
						}
					}
					if (dp[i] > ans) { // update ans and idx of last
						ans = dp[i];
						max_idx = i;
					}
				}
				vector<int> tmp;

				while (max_idx != -1) { // find root
					tmp.push_back(nums[max_idx]);
					max_idx = parent[max_idx];
				}

				return tmp;
    }
};
/*BACKTRACK
class Solution { 
public:
    vector<int> ptr;
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> tmp;
        dfs(nums, tmp, 0, 1);
        return ptr;
    }
    void dfs(const vector<int>& nums, vector<int>& current, int idx, int prev)
    {
        if (current.size() > ptr.size())
            ptr = current;
        for (int i=idx; i<nums.size(); i++) {
            if (nums[i] % prev == 0) {
                current.push_back(nums[i]);
                dfs(nums, current, i+1, nums[i]);
                current.pop_back();
            }
        }
    }
};
*/