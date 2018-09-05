class Solution {
public:

    /**
     * @param formula: a string
     * @return: return a string
     */
    string countOfAtoms(string &formula) {
        // write your code here
        map<string, long long> mp;
        stack<map<string, long long>> st;
        long long n = formula.size(), left = 0, now = 0, pre = 0;
        while (now < n) {
            if (formula[now] == ')') {
                if (now > left) {
                    mp[formula.substr(left, now - left)] += 1;
                }
                now++;
                long long l = now;
                while (now < formula.size() && formula[now] >= '0' && formula[now] <= '9') now++;
                long long t = now > l ? stoll(formula.substr(l, now - l)) : 1;
                left = now;
                auto last = st.top();
                st.pop();
                for (auto &y :mp) {
                    y.second *= t;
                    last[y.first] += y.second;
                }
                mp = last;
            } else if (formula[now] >= '0' && formula[now] <= '9') {
                string s = formula.substr(left, now - left);
                long long l = now;
                while (now < formula.size() && formula[now] >= '0' && formula[now] <= '9') now++;
                long long t = stoll(formula.substr(l, now - l));
                left = now;
                mp[s] += t;
            } else if (formula[now] >= 'a' && formula[now] <= 'z') {
                now++;
            } else {
                if (now > left) {
                    mp[formula.substr(left, now - left)] += 1;
                }
                if (formula[now] == '(') {
                    map<string, long long> p;
                    st.push(mp);
                    mp = p;
                    now++;
                    left = now;
                } else {
                    left = now;
                    now++;
                }
            }
        }
        if (now > left) mp[formula.substr(left, now - left)] += 1;
        string re;
        for (auto &y:mp) {
            re += y.first;
            if (y.second > 1) re += to_string(y.second);
        }
        return re;
    }
};
