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
     * @return: if a person could attend all meetings
     */
    bool canAttendMeetings(vector<Interval> &intervals) {
        // Write your code here
        bool isRepeat = false;
        sort(intervals.begin(),intervals.end(),[&isRepeat](Interval a,Interval b){
            if(a.start == b.start) isRepeat = true;
            return a.start<b.start;
        });
        if(isRepeat) return false;
        int last = -1;
        for(auto p:intervals){
            if(p.start < last) return false;
            last = p.end;
        }
        return true;
    }
};
