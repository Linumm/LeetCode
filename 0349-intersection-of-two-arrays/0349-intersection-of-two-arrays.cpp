class Solution { // Two pointer
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int len_1 = nums1.size();
        int len_2 = nums2.size();

        vector<int> res;
        if (len_1 < 1 || len_2 < 1) return res;

        // sort both vector first to easily use "two pointer" method
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int i = 0; // nums1 idx
        int j = 0; // nums2 idx
        int prev = -1;

        while (i < len_1 && j < len_2) {
            if (prev == nums1[i])
                i++;
            else if (prev == nums2[j])
                j++;
            
            else if (nums1[i] == nums2[j]) {
                prev = nums1[i];
                res.push_back(prev);
                i++;
                j++;
            }
            
            else if (nums1[i] > nums2[j])
                j++;
            else
                i++;
        }

        return res;
    }
};