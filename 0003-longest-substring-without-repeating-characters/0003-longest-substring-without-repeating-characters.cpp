
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int right_most = 0;
        int left_most = 0;
        int n = s.length();
        int max_len = 0;

        while (right_most < n) {
            if (mp.find(s[right_most]) != mp.end()) {
                while (left_most < mp[s[right_most]])
                    mp.erase(s[left_most++]);
                left_most = mp[s[right_most]] + 1; // move left ptr right to the repeated char
            }
            mp[s[right_most]] = right_most; // save char by its idx
            max_len = max(max_len, right_most - left_most + 1);
            right_most++; // move 
        }
        return max_len;
    }
};