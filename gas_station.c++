class Solution {
public:


    int helper(vector<int>&gas, vector<int> &cost){
        int gasSize = gas.size();
        int costSize = cost.size();

        vector<int> visited(gasSize,0);
        int count = 0;
        int i = 0;
        int curFuel = 0;
        int requiredFuel = 0;

        while(!visited[i] && count<gasSize){
            if(count==0? cost[i] > gas[i]: cost[i] > (curFuel+gas[i])){
                i = (i+1)%gasSize;
                if(count!=0){
                    count = 0;
                    curFuel = 0;
                    requiredFuel = 0;
                    fill(visited.begin(), visited.end(), 0);
                }
                continue;
            }

            curFuel += gas[i];
            requiredFuel = cost[i];
            
            curFuel -= requiredFuel;
            visited[i] = 1;
            count++;
            
            i = (i+1)%gasSize;
        }
        return i;

    }

    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int gasSize = gas.size();
        int costSize = cost.size();
        int totalGas = 0;
        int totalCost = 0;
        for(int i=0;i<gasSize;i++){
            totalGas += gas[i];
            totalCost += cost[i];
        }
        if(totalCost > totalGas) return -1;
        return helper(gas,cost);
    }
};
