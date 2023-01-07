class Solution
{
    public:
        int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
        {
            int n = gas.size();
            /*
            gas.resize(2*(1e5));
            cost.resize(2*(1e5));
            for(int i=0; i < n; i++)
            {
                gas[i+n] = gas[i];
            }
            for(int i=0; i < n; i++)
            {
                cost[i+n] = cost[i];
            }

            for(int i=0; i < n; i++)
            {
                int gain = gas[i];
                int req = cost[i];
                gain -= req;
                if(gain < 0) continue;
                for(int j=i+1; j<2*n; j++)
                {
                    gain += gas[j]-cost[j];
                    if(gain < 0) break;
                    if(j%n == i) return i;
                }
            }
            return -1;
            */
            int curr_gas = 0;
            int prev_gas = 0;
            int start = 0;
            for (int i = 0; i < gas.size(); i++)
            {
                curr_gas += gas[i] - cost[i];
                if (curr_gas < 0)
                {
                    start = i + 1;
                    prev_gas += curr_gas;
                    curr_gas = 0;
                }
            }
            if (curr_gas + prev_gas >= 0)
            {
                return start;
            }
            return -1;
        }
};