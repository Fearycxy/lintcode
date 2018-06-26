class Trie {
public:
bool f = false;
Trie *child[128]={0};
    Trie() {
        // do intialization if necessary
    }
    /*
     * @param word: a word
     * @return: nothing
     */
    void insert(string &word) {
        // write your code here
        if(word.empty()) {
            f = true;
            return;
        }
        if(!child[word[0]]) child[word[0]] = new Trie;
        string k = word.substr(1);
        child[word[0]]->insert(k);
    }

    /*
     * @param word: A string
     * @return: if the word is in the trie.
     */
    bool search(string &word) {
        // write your code here
        if(word.empty()) return f;
        if(!child[word[0]]) return false;
        string k =word.substr(1);
        return child[word[0]]->search(k);
    }

    /*
     * @param prefix: A string
     * @return: if there is any word in the trie that starts with the given prefix.
     */
    bool startsWith(string &prefix) {
        // write your code here
        if(prefix.empty()) return true;
        if(!child[prefix[0]]) return false;
        string k =prefix.substr(1);
        return child[prefix[0]]->startsWith(k);
    }
};
