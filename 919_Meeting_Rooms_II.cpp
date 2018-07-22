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

class Solution {
public:
    /**
     * @param intervals: an array of meeting time intervals
     * @return: the minimum number of conference rooms required
     */
    int minMeetingRooms(vector<Interval> &intervals) {
        // Write your code here
        multiset<pair<int,int>> vec;
        for(auto y:intervals) {
            vec.emplace(y.start,1);
            vec.emplace(y.end,-1);
        }
        int tem = 0 ,an  = 0;
        for(auto f:vec){
            tem += f.second;
            an = max(an,tem);
        }
        return an;
    }
};
