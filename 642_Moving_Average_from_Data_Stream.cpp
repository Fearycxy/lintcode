class MovingAverage {
public:
int size;
queue<int> que;
double total;
    /*
    * @param size: An integer
    */MovingAverage(int size) {
        // do intialization if necessary
        this->size = size;
        total = 0;
    }

    /*
     * @param val: An integer
     * @return:  
     */
    double next(int val) {
        que.push(val);
        total+=val;
        if(que.size()>size){
            total-= que.front();
            que.pop();
        }
        return total/(double)que.size();
        
        // write your code here
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param = obj.next(val);
 */
