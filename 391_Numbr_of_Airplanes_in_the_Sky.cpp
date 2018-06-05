/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */
//借鉴天空线的解法
class Solution {
public:
    /**
     * @param airplanes: An interval array
     * @return: Count of airplanes are in the sky.
     */
    int countOfAirplanes(vector<Interval> &airplanes) {
        // write your code here
        vector<pair<int,bool>> dp;
        for(auto &interval: airplanes){
            dp.push_back(make_pair(interval.start,true));
            dp.push_back(make_pair(interval.end,false));
        }
        sort(dp.begin(),dp.end());
        int re = 0,cur = 0;
        for(auto &s : dp){
            if(s.second){
                cur++;
            }else{
                re = max(cur,re);
                cur--;
            }
        }
        return re;
    }
};
