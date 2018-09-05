//第二次重做，发现原来的自己的做法是真的蠢
class Solution {
public:
    /**
     * @param numbers: Give an array numbers of n integer
     * @return: Find all unique triplets in the array which gives the sum of zero.
     */
  vector<vector<int>> threeSum(vector<int> &numbers) {
    // write your code here
    int n = numbers.size();
    vector<vector<int>> re;
    sort(numbers.begin(),numbers.end());
    for(int i = 0;i< n-2;i++){
        if(i && numbers[i]==numbers[i-1]) continue;
        int left = i+1,right = n-1;
        while(left<right){
            while(left<right && numbers[left]+numbers[right]+numbers[i]>0)right--;
            while(left<right && numbers[left]+numbers[right]+numbers[i]<0)left++;
            if(left<right && numbers[left]+numbers[right]+numbers[i] == 0){
                re.push_back({numbers[i],numbers[left],numbers[right]});
                int l = numbers[left],r = numbers[right];
                while(left<right && numbers[left]==l)left++;
                while(left<right && numbers[right]==r)right--;
            }
        }
    }
    return re;
  }
};

//第一次的代码
class Solution {
public:
    /**
     * @param numbers: Give an array numbers of n integer
     * @return: Find all unique triplets in the array which gives the sum of zero.
     */
  vector<vector<int>> threeSum(vector<int> &numbers) {
    // write your code here
    map<int, vector<vector<int>>> mp;//感觉用空间换时间也不怎么高明
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
            sort(tem.begin(), tem.end());
            if (!mp.count(numbers[i] + numbers[j])) {
                vector<vector<int>> tt;
                mp[numbers[i] + numbers[j]] = tt;
            }
            mp[numbers[i] + numbers[j]].push_back(tem);
        }
        se = INT_MAX;
    }
    se = INT_MAX;
    vector<vector<int>> re;
    for (int i = 0; i < n; i++) {
         if (numbers[i] == se) {
                continue;
            }
            se = numbers[i];
        if (mp.count(0 - numbers[i])) {
            for (int j = 0; j < mp[-numbers[i]].size(); j++) {
                if (mp[-numbers[i]][j][1] > numbers[i] || mp[-numbers[i]][j][2] == numbers[i]) {
                    continue;
                } else {
                    if (mp[-numbers[i]][j][1] == numbers[i]) {
                        int ts = time[numbers[i]];
                        if (ts <= 1) {
                            continue;
                        } else {
                            if (0== numbers[i] && ts <= 2) {
                                continue;
                            }
                        }
                    }
                    mp[-numbers[i]][j][2] = numbers[i];
                    re.push_back(mp[-numbers[i]][j]);
                }
            }
        }
         se = INT_MAX;
    }
    return re;
}
};
