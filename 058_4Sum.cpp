class Solution {
public:
    /**
     * @param numbers: Give an array
     * @param target: An integer
     * @return: Find all unique quadruplets in the array which gives the sum of zero
     */
vector<vector<int>> fourSum(vector<int> &numbers, int target) {
    // write your code here
    map<int, vector<vector<int>>> mp;//直接照着三改改
    sort(numbers.begin(), numbers.end());
    int n = numbers.size();
    int fir = INT_MAX;
    int se = INT_MAX;
    map<int, int> time;
    for (int i = 0; i < n; i++) {
        if (time.count(numbers[i])) {
            time[numbers[i]]++;
        } else {
            time[numbers[i]] = 1;
        }
        if (numbers[i] == fir) {
            continue;
        }
        fir = numbers[i];
        for (int j = i + 1; j < n; j++) {
            if (numbers[j] == se) {
                continue;
            }
            se = numbers[j];
            vector<int> tem;
            tem.push_back(numbers[i]);
            tem.push_back(numbers[j]);
            tem.push_back(INT_MAX);
            tem.push_back(INT_MAX);
            if (!mp.count(numbers[i] + numbers[j])) {
                vector<vector<int>> tt;
                mp[numbers[i] + numbers[j]] = tt;
            }
            mp[numbers[i] + numbers[j]].push_back(tem);
        }
        se = INT_MAX;
    }
    fir = INT_MAX;
    se = INT_MAX;
    vector<vector<int>> re;
    for (int i = 0; i < n; i++) {
        if (numbers[i] == fir) {
            continue;
        }
        fir = numbers[i];
        for (int t = i + 1; t < n; t++) {
            if (numbers[t] == se) {
                continue;
            }
            se = numbers[t];
            int yu = numbers[i] + numbers[t];
            if (mp.count(target - yu)) {
                for (int j = 0; j < mp[target-yu].size(); j++) {

                    if (mp[target-yu][j][1] > numbers[i]) {
                        continue;
                    } else {
                        if (mp[target-yu][j][1] == numbers[i]) {
                            int ts = time[numbers[i]];
                            if (ts <= 1) {
                                continue;
                            } else {
                                if (mp[target-yu][j][0] == numbers[i] || numbers[t] == numbers[i]) {
                                    if (ts <= 2) {
                                        continue;
                                    }
                                    if(mp[target-yu][j][0] == numbers[i] && numbers[t] == numbers[i]){
                                        if(ts<=3){
                                            continue;
                                        }
                                    }
                                }
                            }
                        }
                        mp[target-yu][j][2] = numbers[i];
                        mp[target-yu][j][3] = numbers[t];
                        re.push_back(mp[target-yu][j]);
                    }
                }
            }
        }

        se = INT_MAX;
    }
    return re;
}
};
