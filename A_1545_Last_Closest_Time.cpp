class Solution {
public:
    /**
     * @param time: 
     * @return: return a string represent time
     */
    string lastTime(string &time) {
        // Write your code here
        if(time.size()!=5) return "-1";
        auto col=time.find(':');
        int h=stoi(time.substr(0,col)),m=stoi(time.substr(col+1));
        if(h>=24 || h<0 || m>=60 || m<0) return "-1";
        if(m==0){
            m=59;
            if(h==0){
                h=23;
            }
            else{
                --h;
            }
        }
        else{
            --m;
        }
        string rst="";
        if(h<10){
            rst+='0';
        }
        rst+=to_string(h)+':';
        if(m<10){
            rst+='0';
        }
        rst+=to_string(m);
        return rst;
    }
};
