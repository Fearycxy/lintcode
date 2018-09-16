#include<bitset>
class Solution {
public:
    /**
     * @param num: the number of "1"s on a given timetable
     * @return: all possible time
     */
    vector<string> binaryTime(int num) {
        // Write your code here
        vector<string> ans;
        for (int h = 0; h < 12; ++h) {
            for (int m = 0; m < 60; ++m) {
                if (bitset<10>((h << 6) + m).count() == num) {
                    ans.push_back(to_string(h) + (m < 10 ? ":0" : ":") + to_string(m));
                }
            }
        }
        return ans;
    }

};
