class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        vector<int> temp(gas.size());

        for(int i=0; i<gas.size(); i++)
            temp[i] = gas[i]-cost[i];

        int total = 0, idx = 0, currentSum = 0;

        for(int i=0; i<gas.size(); i++){
            total += temp[i];
            currentSum += temp[i];
            if(currentSum<0)
            {
                idx = i+1;
                currentSum = 0;
            }
        }

        return total>=0?idx:-1;
    }
};
