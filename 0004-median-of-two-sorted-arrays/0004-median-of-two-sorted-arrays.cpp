class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged;
        vector<int>::iterator i;
        for (i=nums1.begin(); i!=nums1.end(); i++) merged.push_back(*i);
        for (i=nums2.begin(); i!=nums2.end(); i++) merged.push_back(*i);
        sort(merged.begin(), merged.end());

        int len = merged.size();
        if (len % 2 == 0) return (double)(merged[len/2] + merged[len/2 -1])/2;
        else return (merged[(len+1)/2 - 1]);
    }
};
// 1. Merge : push both array's elements into one new vec
// 2. Sort (it will mainly decide the speed. )
// 3. Find the median by accessing with index.