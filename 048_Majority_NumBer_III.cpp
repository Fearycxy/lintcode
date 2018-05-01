class Solution {
public:
    /**
     * @param nums: A list of integers
     * @param k: An integer
     * @return: The majority number
     */
    int majorityNumber(vector<int> &nums, int k) {
        // write your code here
        k = k-1;
        int tem[k];
        fill(tem,tem+k,INT_MIN);
        int time[k];
        fill(time,time+k,0);
        for(int y:nums){
            bool p = true;//none hits
            for(int g = 0;g<k;g++){
               
                if(y == tem[g]){
                    time[g]++;
                      p = false;
                    break;
                }
            }
            if(!p){
                continue;
            }
            for(int g=0;g<k;g++){
                if(time[g]==0){
                    time[g] = 1;
                    tem[g] = y;
                    p = false;
                    break;
                }
            }
             if(!p){
                continue;
            }
             for (int u = 0;u<k;u++) {
            time[u]--;
        }
        }
        memset(time,0,sizeof(time));
        int re;
        int max = INT_MIN;
        for(int h :tem){
            cout <<h<<endl;
        }
        for(int y:nums){
            for(int g=0;g<k;g++){
                if(y == tem[g]){
                    time[g]++;
                    if(time[g]>max){
                        max = time[g];
                        re = tem[g];
                    }
                }
            }
        }
        return re;
    }
};
