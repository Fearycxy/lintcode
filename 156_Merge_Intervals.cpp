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
     static bool help_sort(Interval a1,Interval a2) {
         return a1.start < a2.start;
     }
    /**
     * @param intervals: interval list.
     * @return: A new interval list.
     */
    vector<Interval> merge(vector<Interval> &intervals) {
        // write your code here
        sort(intervals.begin(),intervals.end(),help_sort);
        int last = INT_MIN;
        for(auto it = intervals.begin();it != intervals.end();){
            auto t = *it;
            if(t.start<=last){
                 last= max(last,t.end);
                (*(it-1)).end = last;
                (*(it-1)).start = min( (*(it-1)).start,t.start);
                it = intervals.erase(it);
            }else{
                last = t.end;
                it++;
            }
        }
        return intervals;
    }
};
