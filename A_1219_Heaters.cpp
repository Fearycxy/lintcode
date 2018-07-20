class Solution {
public:
    /**
     * @param houses: positions of houses
     * @param heaters: positions of heaters
     * @return: the minimum radius standard of heaters
     */
    int findRadius(vector<int> &houses, vector<int> &heaters) {
        // Write your code here
        int an = 0;
        sort(heaters.begin(),heaters.end());
        for(int house :houses){
            auto y = lower_bound(heaters.begin(),heaters.end(),house);
            int distance = INT_MAX;
            if(y!=heaters.end()) distance = min(abs(*y - house),distance);
            if(y!=heaters.begin())distance = min(abs(*(y-1) - house),distance);
            an = max(an,distance);
        }
        return an;
    }
};
