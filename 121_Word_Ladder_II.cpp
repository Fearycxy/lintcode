//first time limited excption
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
     * @return: a list of lists of string
     */
    vector<vector<string>> findLadders(string &start, string &end, unordered_set<string> &dict) {
         // write your code here
        int n = dict.size();
        queue<string> que;
        vector<string> tem;
        tem.push_back(start);
        que.push(start);
        vector<vector<string>> an;
        an.push_back(tem);
        bool flag = false;
        vector<string> ll;
        ll.push_back(start);
        int l = 1;
        int xin = 0;
        while(!que.empty()){
            string f = que.front();
            que.pop();
            if(canChange(end,f)){
                for(auto tt = an.begin();tt != an.end();tt++){
                    if((*tt)[(*tt).size()-1]==f){
                       (*tt).push_back(end);
                    }
                }
                flag = true;
            }
            vector<vector<string>> hh;
            for(auto tt = an.begin();tt != an.end();){
                if((*tt).back()==f){
                    hh.push_back(*tt);
                    tt =an.erase(tt);
                }else{
                    tt++;
                }
            }
            for(auto it = dict.begin();it!=dict.end();it++){
                if(canChange(*it,f)){
                    que.push(*it);
                    xin ++;
                    ll.push_back(*it);
                    for(auto ht = hh.begin();ht!=hh.end();ht++){
                        vector<string> g = *ht;
                        g.push_back(*it);
                        an.push_back(g);
                    }
                }
            }
            l--;
            if(l == 0){
                if(flag){
                    break;
                }
                 for(auto it = dict.begin();it!=dict.end();){
                     if(find(ll.begin(),ll.end(),*it)!=ll.end()){
                         it = dict.erase(it);
                     }else{
                         it++;
                     }
                 }
                 ll.clear();
                l = xin;
                xin  =0;
            }
        }
        for(auto tt = an.begin();tt != an.end();){
                if((*tt).back()!=end){
                    tt = an.erase(tt);
                }else{
                    tt++;
                }
            }
        return an;
    }
};

//两个主要的优化，一个是遍历方式从dict里轮询判断是否满足，换成对26个字母的轮换替换，从O(n)到t*26*log(n)的一个变化，在dict较大时会有优化(实测不做这个优化会死在82%)

更重要的是直接把queue存的不是每一次bfs的last而是直接存的路径，减少不必要的操作

class Solution {
public:
    /*
     * @param start: a string
     * @param end: a string
     * @param dict: a set of string
     * @return: a list of lists of string
     */
    vector<vector<string>> findLadders(string &start, string &end, unordered_set<string> &dict) {
        // write your code here
        queue<vector<string>> paths;
        dict.insert(end);
        vector<string> path{start};
        unordered_set<string> words;
        paths.push(path);
        vector<vector<string>> re;
        int size = 1;bool over = false;
        while(!paths.empty()){
            path = paths.front();paths.pop();
            if(path.size()>size){
                if(over){
                    break;
                }
                for (string w : words) dict.erase(w);
                words.clear();
                size = path.size();
            }
            string back = path.back();
            for(int i =0;i<back.size();i++){
                string tem = back;
                for(char c = 'a';c<='z';c++){
                    tem[i] = c;
                    if(!dict.count(tem)) continue;
                    words.insert(tem);
                    auto p = path;
                    p.push_back(tem);
                    if(tem == end){
                        re.push_back(p);
                        over = true;
                    }else{
                        paths.push(p);
                    }
                }
            }
        }
        return re;
    }
};

