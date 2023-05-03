class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int entire_gas = 0;
        int entire_cost = 0;
        int idx = 0;
        for (int i=0; i<gas.size(); i++) { // First check if cost is higher than remained gas
            entire_gas += gas[i];
            entire_cost += cost[i];
        }

        if (entire_gas - entire_cost < 0)
            return -1;
        else {
            int diff = 0;
            for (int i=0; i<gas.size(); i++) { // And just greedly check
                diff += gas[i] - cost[i];

                if (diff < 0) {
                    idx = i + 1;
                    diff = 0;
                } 
            }

            return idx;
        }
    }

};