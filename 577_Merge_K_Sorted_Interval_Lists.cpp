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
     * @param intervals: the given k sorted interval lists
     * @return:  the new sorted interval list
     */
    vector<Interval> mergeKSortedIntervalLists(vector<vector<Interval>> &intervals) {
        // write your code here
        vector<pair<int,int>> tem;
        for(auto &it:intervals){
            for(auto &t:it){
                tem.emplace_back(t.start,-1);
                tem.emplace_back(t.end,1);
            }
        }
        sort(tem.begin(),tem.end());
        vector<Interval> an;int last = 0,index;
        for(auto p:tem){
            last += p.second;
            if(p.second <0 && last == -1){
                index = p.first;
            }else if(last==0 && p.second >0){
                an.emplace_back(index,p.first);
            }
        }
        return an;
    }
};
