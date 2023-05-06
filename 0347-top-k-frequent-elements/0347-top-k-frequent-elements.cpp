class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int num = nums.front();
        int count = 0;
        int idx = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, less<pair<int,int>>> frequency;
        // Check frequency and make it as a pairs, then push into heap
        for (int i=0; i<nums.size(); i++) {
            if (num != nums[i]) {
                frequency.push({count, num}); // {frequency, nums}
                num = nums[i];
                count = 1;
                continue;
            }
            count++;
        }
        // push last element
        frequency.push({count, num});

        vector<int> top_k_frequent;
        for (int i=0; i<k; i++) {
            top_k_frequent.push_back(frequency.top().second);
            frequency.pop();
        }

        return top_k_frequent;
    }
};