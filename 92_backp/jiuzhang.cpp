/**
* 本参考程序来自九章算法，由 @九章算法 提供。版权所有，转发请注明出处。
* - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
* - 现有的面试培训课程包括：九章算法班，系统设计班，算法强化班，Java入门与基础算法班，Android 项目实战班，
* - Big Data 项目实战班，算法面试高频题班, 动态规划专题班
* - 更多详情请见官方网站：http://www.jiuzhang.com/?source=code
*/ 


class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> A) {
        bool f[m + 1];
        for (int i = 0; i <= m; i++) {
            f[i] = false;
        }
        f[0] = true;//
        for (int j = 0; j < A.size(); j++) {f[i]表示前j个是否能达到重量i
            for (int i = m; i >= A[j]; i--) {
                f[i] = f[i] || f[i - A[j]];//已经达到或者通过之前的加上A[j]
            } // for j
        } // for i
        
        for (int i = m; i >= 0; i--) {
            if (f[i]) {
                return i;
            }
        }
        return 0;
    }
};
