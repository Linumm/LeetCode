class Solution { //Two Pointer
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int boat_num = 0;
        int i = 0;
        int j = people.size()-1;
        sort(people.begin(), people.end()); //Since it is natural num, just sort from start.

        while (i<=j) {
            if (i == j) {
                boat_num++;
                break;
            }
            if (people[i] + people[j] <= limit) {
                i++;
                j--;
                boat_num++;
                continue;
            }
            else {
                j--;
                boat_num++;
            }
            
        }
        return boat_num;
    }
};
/* Time Limit exceeded.
int boat_nums = 0;
        int left_point;
        int right_point;
        int _max;
        vector<int> idx_stack(people.size());

        for (int i=0; i<people.size(); i++) {
            right_point = 0;
            _max = 0;
            if (idx_stack[i] == 1) continue;
            else if (people[i] == limit) {
                boat_nums++;
                idx_stack[i] = 1;
                continue;
            }
            else {
                left_point = people[i];
                for (int j=i+1; j<people.size(); j++) {
                    if (idx_stack[j] == 1) continue;
                    else if (left_point + people[j] == limit) {
                        _max = left_point + people[j];
                        right_point = j;
                        break;
                    }
                    else if (left_point + people[j] < limit && left_point + people[j] > _max) {
                        _max = left_point + people[j];
                        right_point = j;
                    }
                }
                idx_stack[i] = 1;
                idx_stack[right_point] = 1;

                if (right_point == 0)
                    idx_stack[i] = 1;
                boat_nums++;
            }
        }

        return boat_nums;
        */