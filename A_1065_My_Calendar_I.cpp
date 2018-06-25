class MyCalendar {
public:
std::vector<int> p;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(int i=0;i<p.size();i=i+2){
            if( (end >p[i] && start <=p[i]) || (start<p[i+1] &&start >= p[i])){
                return false;
            }
        }
        p.push_back(start);
        p.push_back(end);
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * bool param_1 = obj.book(start,end);
 */
