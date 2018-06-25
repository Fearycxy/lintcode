class MyCalendarTwo {
public:
    MyCalendarTwo() {
    }
    std::vector<int> p;
    std::vector<int> over;
    bool book(int start, int end) {
        int flag = 0;
        for(int i =0;i<over.size();i=i+2){
             int s = max(start,over[i]);
            int e = min(end,over[i+1]);
            if(s < e )
                return false;
        }
        for(int i=0;i<p.size();i=i+2){
            int s = max(start,p[i]);
            int e = min(end,p[i+1]);
            if(s < e ){
                over.push_back(s);
                over.push_back(e);
            }
        }
        p.push_back(start);
        p.push_back(end);
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo obj = new MyCalendarTwo();
 * bool param_1 = obj.book(start,end);
 */
