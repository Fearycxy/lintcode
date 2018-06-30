class Vector2D {
public:
vector<int> vec;
vector<int>::iterator it;
    Vector2D(vector<vector<int>>& vec2d) {
        // Initialize your data structure here
        for(auto f:vec2d)
            for(int y:f)
                vec.push_back(y);
        it = vec.begin();
    }

    int next() {
        return *it++;
        // Write your code here
    }

    bool hasNext() {
        return it != vec.end();
        // Write your code here
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */
