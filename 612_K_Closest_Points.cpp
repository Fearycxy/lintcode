/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * }; * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

class Solution {
public:
    /**
     * @param points: a list of points
     * @param origin: a point
     * @param k: An integer
     * @return: the k closest points
     */
    vector<Point> kClosest(vector<Point> &points, Point &origin, int k) {
        // write your code here
        vector<Point> re;
        return quickSort(points,origin,k,0,points.size()-1,re);
    }



    vector<Point> quickSort(vector<Point> &points, Point &origin, int k, int s, int e, vector<Point> &re) {
        //first partition:
        if (k == 0) return re;
        auto cmp = [&origin](Point &p1, Point &p2) {
            double d1 = sqrt(pow(p1.x - origin.x, 2) + pow(p1.y - origin.y, 2));
            double d2 = sqrt(pow(p2.x - origin.x, 2) + pow(p2.y - origin.y, 2));
            if (d1 == d2) {
                if (p1.x == p2.x)return p1.y < p2.y;
                return p1.x < p2.x;
            }
            return d1 < d2;
        };
        int l = s - 1;
        for (int j = s; j <= e; j++) {
            if (cmp(points[j], points[e])) {
                swap(points[j], points[++l]);
            }
        }
        swap(points[l+1], points[e]);
        if (l - s + 1 <=k) {
            sort(points.begin()+s, points.begin()+l+1, cmp);
            re.insert(re.end(),points.begin()+s, points.begin()+l+1);
            if(l - s + 1 ==k) return re;
            re.push_back(points[l+1]);
            return quickSort(points, origin, k - l + s - 2, l + 2, e, re);
        } else {
            return quickSort(points, origin, k, s, l, re);
        }
    }
};
