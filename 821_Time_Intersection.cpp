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
     * @param seqA: the list of intervals
     * @param seqB: the list of intervals
     * @return: the time periods
     */
    vector<Interval> timeIntersection(vector<Interval> &seqA, vector<Interval> &seqB) {
        // Write your code here
        //sort(seqA.begin(),seqA.end());
        //sort(seqB.begin(),seqB.end());
        int i = 0;
        int j = 0;
        vector<Interval> res;
        while(i < seqA.size() && j <seqB.size()){
            int maxstart = max(seqA[i].start, seqB[j].start);
            int minend = min(seqA[i].end, seqB[j].end);
            //cout<<" "<<maxstart<<" "<<minend<<endl;
            if(maxstart <= minend){
                Interval ii(maxstart, minend);
                res.push_back(ii);
            }
            if(minend == seqA[i].end) i++;
            if(minend == seqB[j].end) j++;
        }
        return res;
    }
};



//this is my solution
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
     * @param seqA: the list of intervals
     * @param seqB: the list of intervals
     * @return: the time periods
     */
    vector<Interval> timeIntersection(vector<Interval> &seqA, vector<Interval> &seqB) {
        // Write your code here
        vector<pair<int,int>> vec;
        for(auto i:seqA){
            vec.emplace_back(i.start,1);
            vec.emplace_back(i.end,-1);
        }
        for(auto i:seqB){
            vec.emplace_back(i.start,1);
            vec.emplace_back(i.end,-1);
        }
        sort(vec.begin(),vec.end());
        vector<Interval> an;pair<int,int> last = {-1,-1};int index = 0;
        for(auto a:vec){
            if(a.second <0 && last.second >0 && index ==2 ){
                an.emplace_back(last.first,a.first);
            }
            index += a.second <0? -1:1;
            last = a;
        }
        return an;
    }
};
