class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> um;
        for (int i: nums) {
            um[i]++; // first, initialized by 0, so directly use []
        }
        for (auto i: um) {
            if (i.second == 1) return i.first;
        }
        return -1;
    }
};
// hash table (better to use [] than insert)