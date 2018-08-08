//就是求最晚的一天满足恰好有m组，何为组呢，至少连续k个位置开花叫组
class Solution {
public:
    /**
     * @param flowers: an array
     * @param k: an integer
     * @param m: an integer
     * @return: the last day
     */
    int flowerProblem(vector<int> flowers, int k, int m) {
        int n = flowers.size();

        blooming.resize(n + 2, false);
        groups.resize(n + 2);
        fathers.resize(n + 2);

        for (int i = 0; i < n + 2; i++) {
            fathers[i] = i;
        }

        int result = -1;
        int count = 0;
        for (int i = 0; i < n; i++) {
            int slot = flowers[i];
            blooming[slot] = true;
            groups[slot] = 1;

            if (blooming[slot - 1]) {
                if (groups[find(slot - 1)] >= k) {
                    count--;
                }
                merge(slot, slot - 1);
            }
            if (blooming[slot + 1]) {
                if (groups[find(slot + 1)] >= k) {
                    count--;
                }
                merge(slot, slot + 1);
            }

            if (groups[find(slot)] >= k) {
                count++;
            }

            if (count == m) {
                result = i + 1;
            }
        }

        return result;
    }

private:
    int find(int x) {
        if (fathers[x] == x) {
            return fathers[x];
        }

        return fathers[x] = find(fathers[x]);
    }

    void merge(int x, int y) {
        int fx = find(x);
        int fy = find(y);

        if (fx != fy) {
            fathers[fy] = fx;
        }

        groups[fx] += groups[fy];
    }
    
    vector<bool> blooming;
    vector<int> groups;
    vector<int> fathers;
};
