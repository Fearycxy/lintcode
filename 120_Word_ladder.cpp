class Solution {
    private:
    bool canChange(string s1, string s2){
        int f = 0;
        for(auto it1 = s1.begin(),it2=s2.begin();it1!=s1.end();it1++,it2++){
            if(*it1!=*it2){
                f++;
            }
            if(f>1){
                return false;
            }
        }
        return true;
    }
public:
    /*
     * @param start: a string
     * @param end: a string
     * @param dict: a set of string
     * @return: An integer
     */
    int ladderLength(string &start, string &end, unordered_set<string> &dict) {
        // write your code here
        if(end == start){
            return 1;
        }
        vector<string> vec;
        for(auto it = dict.begin();it!=dict.end();it++){
            vec.push_back(*it);
        }
        int n = dict.size();
        queue<string> que;
        que.push(end);
        int re = 1;
        string last =end;
        string l;
        while(!que.empty()){
            string f = static_cast<basic_string<char, char_traits<char>, allocator<char>> &&>(que.front());
            que.pop();
            if(canChange(start,f)){
                cout <<f <<endl;
                return re+1;
            }

            for(auto it = dict.begin();it!=dict.end();){
                if(canChange(*it,f)){
                    cout <<*it<<" "<<f<<endl;
                    que.push(*it);
                    l = *it;
                    it = dict.erase(it);
                }else{
                    it++;
                }
            }
            if(last == f){
                cout <<f <<endl;
                re++;
                last = l;
            }
        }
        return 0;
    }

};
