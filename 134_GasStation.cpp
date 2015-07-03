// 134 Gas Station
// There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

// You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

// Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

// Note:
// The solution is guaranteed to be unique.

// Hide Tags Greedy

//Caution, start from i, goes j step to i+j-1 station. if the left gas is less than 0, i is not a good start
//than the station between i and i+j-1 including the two end are all not a good start, we should start from i+j
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int i = 0;
        int j = 0;
        int n = gas.size();
        for(i = 0; i < n; i += j) { //i means the started state idx
            int gas_left = 0;
            for(j = 1; j <= n; ++j) { //j means how many segments we can travel
                int k = (i+j-1)%n;
                gas_left += (gas[k]-cost[k]);
                if(gas_left < 0) break;
            }
            if(j > n) return i;
        }
        return -1;
    }
};