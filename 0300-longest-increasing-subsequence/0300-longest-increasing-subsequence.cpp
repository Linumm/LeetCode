class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // Binary search
        int n = nums.size();
        vector<int> subsequence;
        subsequence.push_back(nums[0]);

        for (int i=1; i<n; i++) {
            if (nums[i] > subsequence.back()) subsequence.push_back(nums[i]);
            else {
                int idx = idxBinarySearch(subsequence, nums[i], 0, subsequence.size()-1);
                subsequence[idx] = nums[i];
            }
        }
        return subsequence.size();
    }
    int idxBinarySearch(const vector<int>& subsequence, int target, int l, int r)
    {
        if (r-l < 0) return l;

        int mid = l + (r-l)/2;
        if (subsequence[mid] == target) return mid;
        if (target > subsequence[mid]) {
            return idxBinarySearch(subsequence, target, mid+1, r);
        }
        else
            return idxBinarySearch(subsequence, target, l, mid-1);
    }
};

/*
int idxBinarySearch(const vector<int>& subsequence, int target, int l, int r)
    {
        if (l == r) return r;

        int mid = l + (r-l)/2;
        if (subsequence[mid] == target) return mid;
        if (target > subsequence[mid]) {
            return idxBinarySearch(subsequence, target, mid+1, r);
        }
        else
            return idxBinarySearch(subsequence, target, l, mid-1);
    }
    int idx = lower_bound(subsequence.begin(), subsequence.end(), nums[i]) - subsequence.begin();
            if (idx == subsequence.size()) subsequence.push_back(nums[i]);
            else subsequence[idx] = nums[i];
*/