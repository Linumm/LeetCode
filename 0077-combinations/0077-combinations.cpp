class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> combine(int n, int k) 
    {
        vector<int> sample;
        for (int i=1; i<=n; i++) {
            sample.push_back(i);
        }
        vector<int> tmp;
        Combination(sample, tmp, k, 0);
        
        return result;
    }
    void Combination(vector<int> sample, vector<int>& target, int size, int dup_ctrl) 
    {
        // dup_ctrl: duplication control
        if (target.size() == size) {
            result.push_back(target);
            return;
        }
        for (int i=dup_ctrl; i<sample.size(); i++) {
            target.push_back(sample[i]);
            Combination(sample, target, size, i+1); //Only accept ascending order by dup_ctrl
            target.pop_back();
        }
    }
};