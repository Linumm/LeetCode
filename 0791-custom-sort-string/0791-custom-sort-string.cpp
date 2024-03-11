class Solution { // Hash (unordered_map)
public:
    string customSortString(string order, string s) {
        string res = "";
        unordered_map<char, int> mp;

        // First check the number of each alphabet and insert it into map
        for (auto c : s)
            mp[c]++;
        
        // By checking 'order' from front, if char found in map,
        // add the char into 'res' and decrease the number of the char.
        for (auto c2 : order) {
            while (mp[c2] > 0) {
                res.push_back(c2);
                mp[c2]--;
            }
        }
        
        // after finishing checking 'order', append the remain of alphabet in the map. 
        for (auto [c, i] : mp) {
            while (i > 0) {
                res.push_back(c);
                i--;
            }
        }
        
        return res;
    }
    // c++ : append is with str, not char. 
};