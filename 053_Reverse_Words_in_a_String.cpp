class Solution {
public:
    /*
     * @param s: A string
     * @return: A string
     */
  string reverseWords(string &s) {
    // write your code here
    
    if (s.size() == 0) {
        return s;
    }
     for (string::iterator last = s.begin(); last != s.end();) {
        if (*last == ' ') {
            last = s.erase(last);
        } else {
           break;
        }
    }
    if (s.size() == 0) {
        return s;
    }
    for (string::reverse_iterator last = s.rbegin(); last != s.rend();) {
        if (*last == ' ') {
            last = string::reverse_iterator(s.erase((++last).base()));
        } else {
           break;
        }
    }
    reverse(s.begin(), s.end());
    string::iterator it = s.begin();
    string::iterator start = it;
    it++;
    for (; it != s.end(); it++) {
        if (*it == ' ') {
            reverse(start, it);
            start = it + 1;
        }
    }
    reverse(start, s.end());
    return s;
}
};
