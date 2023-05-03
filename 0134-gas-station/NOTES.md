int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int remained_gas = 0;
        int start_station = -1;
        int num_of_station = gas.size();

        vector<int> diff_gas_cost;
        for (int i=0; i<num_of_station; i++)
            diff_gas_cost.push_back(gas[i] - cost[i]);
        
        for (int i=0; i<num_of_station; i++) {
            if (diff_gas_cost[i] >= 0) {
                remained_gas = diff_gas_cost[i];
                if (SubCheck(diff_gas_cost, remained_gas, i+1))
                    return i;
            }
        }
        
        return -1;
    }

    bool SubCheck(vector<int>& diff, int remained_gas, int idx)
    {
        int num = diff.size();
        for (int i=0; i<num; i++) {
            remained_gas += diff[idx % num];
            if (remained_gas < 0 )
                return false;
            idx++;
        }
        return true; 
    }
  
-it is the way checking one by one, so time exceeded.
-Branch the impossible case first.
