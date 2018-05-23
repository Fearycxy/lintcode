class Solution {
public:
    /**
     * @param gas: An array of integers
     * @param cost: An array of integers
     * @return: An integer
     */
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        // write your code here
        int start = 0;
        const int n = gas.size();
        int cur = n;
        int oil =0;
        while(cur!=start){
            while(gas[start]<cost[start]){ 
                start++;
                if(start ==n) return -1;
            }
            cur =(start +1)%n ;
            oil = gas[start]-cost[start];
            for(;cur!=start;cur = (cur+1)%n){
                oil+=gas[cur];
                if(oil<cost[cur]){
                    if(start && cur<start) return -1;
                    start = cur+1;
                    if(start ==n) return -1;
                    break;
                }
                oil -=cost[cur];
            }
        }
        return start;
    }
};


//九章的好多了其实只差一点点
class Solution {
public:
    /**
	 * @param gas: a vector of integers
	 * @param cost: a vector of integers
	 * @return: an integer
	 */
	int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
		int sum = 0;
        int total = 0;
        int index = -1;

        for(int i = 0; i<gas.size(); i++) {
            sum += gas[i] - cost[i];
            total += gas[i] - cost[i];
            if(sum < 0) {
                index = i;
                sum = 0;
            }
        }
        return total < 0 ? -1 : index + 1;
	}
};
