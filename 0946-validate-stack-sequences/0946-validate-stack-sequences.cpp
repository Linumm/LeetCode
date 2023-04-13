class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> tmp;
        int idx = 0;
        for (auto i : pushed) {
            tmp.push(i);

            while (!tmp.empty() && tmp.top() == popped[idx]) {
                idx++;
                tmp.pop();
            }
        }
        if (idx == popped.size()) return true;
        else return false;
    }
};