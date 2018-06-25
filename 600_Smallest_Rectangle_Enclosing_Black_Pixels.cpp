class Solution {
public:
    /**
     * @param image: a binary matrix with '0' and '1'
     * @param x: the location of one of the black pixels
     * @param y: the location of one of the black pixels
     * @return: an integer
     */
    int minArea(vector<vector<char>> &image, int x, int y) {
        // write your code here
        int m = image.size();
        int n = image[0].size();
        int l = search(image, 0, y + 1, 0, m - 1, true, true);
        int r = search(image, y, n, 0, m - 1, true, false);
        int t = search(image, 0, x + 1, l, r, false, true);
        int b = search(image, x, m, l, r, false, false);
        return (b - t) * (r - l);
    }

    inline int search(vector<vector<char>> &image, int l, int r, int s, int e, bool h, bool opt) {
        while (l < r) {
            int mid = (l + r) / 2;
            bool flag = false;
            for (int i = s; i <= e; i++) {
                char f = h ? image[i][mid] : image[mid][i];
                if (f == '1') {
                    flag = true;
                    break;
                }
            }
            if (flag == opt) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};
