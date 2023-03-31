
//Using Stack to compare the index difference!
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<int> st;
        int n = temp.size();
        vector<int> answer(n, 0);

        for(int i=0; i<n; i++) {
            int cnt = 1;
            while(!st.empty() && temp[st.top()] < temp[i]) {
                answer[st.top()] = i - st.top();
                cnt++;
                st.pop();
            }

            st.push(i);
        }
        return answer;
    }
};