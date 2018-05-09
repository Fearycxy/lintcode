//切记这里的剪枝有问题！！
class Solution {
public:
    int m;
    int n;
    int* flag;
    std::map<int, unordered_set<string>> mp;
    vector<vector<char>> board;
    /**
     * @param board: A list of lists of character
     * @param word: A string
     * @return: A boolean
     */
    bool exist(vector<vector<char>> &board, string &word) {
        // write your code here
        m = static_cast<int>(board.size());
        n = static_cast<int>(board[0].size());
        flag = new int[m*n];
        memset(flag,0,m*n*sizeof(int));
        this ->board = board;
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(help(i,j,word)){
                    return true;
                }
            }
        }
        return false;
    }

    bool help(int x,int y ,string word){
        int i = x * n + y;
        if(flag[i]){
            return false;
        }else{
            flag[i] = true;
        }/*
        if(mp.count(i) &&mp[i].count(word)){
            flag[i] = false;
            cout <<i<<": "<<flag[i]<<" false"<<endl;
            return false;
        }*/
        if(board[x][y] == word[0]){
            if(word.size() == 1){
                return true;
            }
            string neww = word.substr(1);
            if(x && help(x-1,y,neww)){
                return true;
            }
            if(y && help(x,y-1,neww)){
                return true;
            }
            if((x+1 < m) && help(x+1,y,neww)){
                return true;
            }
            if(y+1 < n && help(x,y+1,neww)){
                return true;
            }/*
            if(!mp.count(i)){
                unordered_set<string> tmp;
                tmp.insert(word);
                mp[i] = tmp;
            }else{
                mp[i].insert(word);
            }*/
        }
        flag[i] = 0;
        return false;
    }
};

int main(){
    int array[]={3,4,8,5};
    vector<int> vec;
    vec.insert(vec.end(),array,array+ sizeof(array)/ sizeof(int));
    Solution solution;
    vector<vector<char>> board{{'A','B','C','E'},{'S','F','E','S'},{'A','D','E','E'}};
    string word ="ABCESEEEFS";
    solution.exist(board,word);
}
