class Solution {
public:
    /*
     * @param nums: a list of integers
     * @return: The majority number that occurs more than 1/3
     */
    int majorityNumber(vector<int> &nums) {
        // write your code here
        int cur1 = INT_MIN;
        int n1 = 0;
        int cur2 = INT_MIN;
        int n2 = 0;
        for(int f:nums){
            if(f == cur1){
                n1++;
            }else if(f == cur2){
                n2++;
            }else{
                if(n1 ==0){
                    cur1 = f;
                    n1 =1;
                }else if(n2==0){
                    cur2 = f;
                    n2 =1 ;
                }else{ 
                    n2--;    
                    n1--;
                }
            }
        }
        cout <<cur1<<endl;
        cout <<cur2<<endl;
        int y = 0;
        for(int f:nums){
            if(f == cur1){
                y++;
            }else if(f == cur2){
                y--;
            }
        }
        if(y>0){
            y = cur1; 
        }else{
            y = cur2;
        }
        return y;
    }
};
