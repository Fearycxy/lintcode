class Solution {
public:
    /**
     * @param n: the number of disks
     * @return: the order of moves
     */
    vector<string> towerOfHanoi(int n) {
        // write your code here
        vector<string> re;
        if(n==1){
            re.push_back("from A to C");
            return re;
        }
        auto vt = towerOfHanoi(n-1);
         for(string &s:vt){
            for(int i =5;i<=10;i*=2){
                if(s[i]=='B'){
                    s[i] = 'C';
                }else if(s[i] == 'C'){
                    s[i] ='B';
                }
            }
        }
        
        re.insert(re.end(),vt.begin(),vt.end());
        re.push_back("from A to C");
         for(string &s:vt){
            for(int i =5;i<=10;i*=2){
                if(s[i]=='A'){
                    s[i] = 'B';
                }else if(s[i] == 'B'){
                    s[i] ='C';
                }else if(s[i]=='C'){
                    s[i]='A';
                }
            }
        }
         re.insert(re.end(),vt.begin(),vt.end());
         return re;
    }
};
