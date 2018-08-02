class Solution {
public:
    /**
     * @param time: 
     * @return: return a string represents time
     */
    string lastTime(string &time) {
        // Write your code here
        if(time.size()!=5) return "-1";
        auto pos=time.find(':');
        int h=stoi(time.substr(0,pos)),m=stoi(time.substr(pos+1));
        if(h<0 || h>=24 || m<0 || m>=60) return "-1";
        bool nxt=false;
        while(1){
            if(h==0 || h==11 || h==22) {
                --h;
                nxt=true;
            }
            if(h<0) h+=24;
            int start= nxt? 59:m,
                h1=h/10,
                h2=h % 10;
            for(int i=start;i>=1;--i){
                if(i==55 || i==44 || i==33 || i==22 || i==11) continue;
                int i1=i/10,
                    i2=i % 10;
                if(i1!=h1 && i1!=h2 && i2!=h1 && i2!=h2){
                    string rst="";
                    if(h<10){
                        rst+='0';
                    }
                    rst+=to_string(h)+':';
                    if(i<10){
                        rst+='0';
                    }
                    rst+=to_string(i);
                    return rst;
                }
            }
            nxt=true;
            --h;
        }
    }
};
