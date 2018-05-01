class Solution {
public:
    /**
     * @param numbers: An array of Integer
     * @param target: target = numbers[index1] + numbers[index2]
     * @return: [index1 + 1, index2 + 1] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &numbers, int target) {
        // write your code here
        map<int,int> mp;
        vector<int> a;
        int n = numbers.size();
        for(int t=0;t<n;t++){
            if(!mp.count(numbers[t])){
                mp[target-numbers[t]] = t;
            }else{
                a.push_back(mp[numbers[t]]);
                a.push_back(t);
                break;
            }
        }
        return a;
        
    }
};
