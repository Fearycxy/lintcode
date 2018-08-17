class node {
public:
    bool is_end = false;
    node *child[26]{};
    string word ;
};

void insert(node *root, string &s) {
    for (char c:s) {
        if (!(root->child)[c - 'a']) (root->child)[c - 'a'] = new node;
        root = (root->child)[c - 'a'];
    }
    root->word = s;
    root->is_end = true;
}

class Solution {
public:
    /*
     * @param words: a set of words without duplicates
     * @return: all word squares
     */
    vector<vector<string>> wordSquares(vector<string> &words) {
        // write your code here
        vector<vector<string>> an;
        if(words.empty()) return an;
        node r;
        for(auto &s:words) insert(&r,s);
        int size = words[0].size();
        for(auto &s:words){
            dfs(an,size-1,&r,{s},&r,1,0);
        }
        return an;
    }
    
    void dfs(vector<vector<string>> &an,int index,node *root,vector<string> tem,node *p,int x,int y){
        if(index == 0) {
            an.push_back(tem);
            return;
        }
        if(p->is_end){
            tem.push_back(p->word);
            dfs(an,index-1,root,tem,root,x+1,0);
            return;
        }
        if(y<tem.size()){
            auto n = p->child[tem[y][x]-'a'];
            if(n) dfs(an,index,root,tem,n,x,y+1);
        }else{
            for(int i=0;i<26;i++){
                if(p->child[i]){
                     dfs(an,index,root,tem,p->child[i],x,y+1);
                }
            }
        }
        
    }
};
