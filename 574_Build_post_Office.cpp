//1, BEST 九章version  这个解法太巧妙了 前缀和的前缀和是 距离之和 记下结论， 应该用的到(不过就这题而言，第四种直接算就可以啦)
class Solution {
public:
    /**
     * @param grid a 2D grid
     * @return an integer
     */
    int shortestDistance(vector<vector<int>>& grid) {
        // Write your code here
        int row = grid.size(), column = grid[0].size();
        if(row == 0 || column == 0 || !haveZero(grid, row, column)) {
            return -1;
        }

        vector<int> rowSum(row);
        vector<int> columnSum(column);
        for(int i = 0; i < row; i++)
            for(int j = 0; j < column; j++)
                if (grid[i][j] == 1) {
                    rowSum[i]++;
                    columnSum[j]++;
                }

        vector<int> costRow(row);
        vector<int> costColumn(column);
        getSumDistance(rowSum,row,costRow);
        getSumDistance(columnSum,column,costColumn);

        int cost = INT_MAX;
        for(int i = 0; i < row; i++)
            for(int j = 0; j < column; j++)
                if(grid[i][j] == 0 && cost > costRow[i] + costColumn[j]) {
                    cost = costRow[i] + costColumn[j];
                }
        return cost;
    }

    void getSumDistance(vector<int>& a, int n, vector<int>& cost) {
        vector<int> prefixSum1(n);
        vector<int> prefixSum2(n);
        /*
    	第一阶段，处理前缀。
    	prefixSum1记录数组 a 的前缀和，即:prefixSum1[i]=a[0]+a[1]+..+a[i].
    	prefixSum2记录数组 prefixSum1 前缀和，prefixSum2即为i之前的点到第 i 个点的代价和。
    	*/
    	prefixSum1[0] = a[0];
    	for(int i = 1; i < n; i++) {
    		prefixSum1[i] = prefixSum1[i - 1] + a[i];
    	}
    	prefixSum2[0] = 0;
    	for(int i = 1; i < n; i++) {
    		prefixSum2[i] = prefixSum2[i - 1] + prefixSum1[i - 1];
     	}

     	for(int i = 0; i < n; i++) {
     		cost[i] = prefixSum2[i];
     	}

    	/*
    	第二阶段，处理后缀。
    	prefixSum1记录数组 a 的后缀和，即:prefixSum1[i]=a[n-1]+a[n-2]+..+a[i].
    	prefixSum2记录数组 prefixSum1 的后缀和，prefixSum2即为 i 之后的点到第 i 个点的代价和。
    	*/
    	prefixSum1[n - 1] = a[n - 1];
    	for(int i = n - 2; i >= 0; i--) {
    		prefixSum1[i] = prefixSum1[i + 1] + a[i];
    	}
    	prefixSum2[n - 1] = 0;
    	for(int i = n - 2; i >= 0; i--) {
    		prefixSum2[i] = prefixSum2[i + 1] + prefixSum1[i + 1];
     	}

     	for(int i = 0; i < n; i++) {
     		cost[i] += prefixSum2[i];
     	}

     	/*
     	cost[i] 即为a数组中所有点到第 i 点的代价和
     	*/
    }

    bool haveZero(vector<vector<int>>& grid, int row, int column) {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                if (grid[i][j] == 0) {
                    return true;
                }
            }
        }
        return false;
    }
};

//2, 二分法计算距离 
public class Solution {
    /**
     * @param grid a 2D grid
     * @return an integer
     */
    public int shortestDistance(int[][] grid) {
        // Write your code here
        int n = grid.length;
        if (n == 0)
            return -1;

        int m = grid[0].length;
        if (m == 0)
            return -1;

        List<Integer> sumx = new ArrayList<Integer>();
        List<Integer> sumy = new ArrayList<Integer>();
        List<Integer> x = new ArrayList<Integer>();
        List<Integer> y = new ArrayList<Integer>();

        int result = Integer.MAX_VALUE;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (grid[i][j] == 1) {
                    x.add(i);
                    y.add(j);
                }
        
        Collections.sort(x);
        Collections.sort(y);

        int total = x.size();

        sumx.add(0);
        sumy.add(0);
        for (int i = 1; i <= total; ++i) {
            sumx.add(sumx.get(i-1) + x.get(i-1));
            sumy.add(sumy.get(i-1) + y.get(i-1));
        }

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (grid[i][j] == 0) {
                    int cost_x = get_cost(x, sumx, i, total);
                    int cost_y = get_cost(y, sumy, j, total);
                    if (cost_x + cost_y < result)
                        result = cost_x + cost_y;
                }

        return result;
    }

    public int get_cost(List<Integer> x, List<Integer> sum, int pos, int n) {
        if (n == 0)
            return 0;
        if (x.get(0) > pos)
            return sum.get(n) - pos * n;

        int l = 0, r = n - 1;
        while (l + 1 < r) {
            int mid = l + (r - l) / 2;
            if (x.get(mid) <= pos)
                l = mid;
            else
                r = mid - 1;
        }
        
        int index = 0;
        if (x.get(r) <= pos)
            index = r;
        else
            index = l;
        return sum.get(n) - sum.get(index + 1) - pos * (n - index - 1) + 
               (index + 1) * pos - sum.get(index + 1);
    }
}

//3. 从中间往外搜索，减少搜索的点，可与第二种结合优化，当然都远不如第一种   https://zhengyang2015.gitbooks.io/lintcode/build_post_office_573.html
public class Solution {
    /**
     * @param grid a 2D grid
     * @return an integer
     */
    class Node{
        int x;
        int y;
        public Node(int x, int y){
            this.x = x;
            this.y = y;
        }
    }
    int[] dx = {0, 0, -1, 1, -1, 1, -1, 1};
    int[] dy = {-1, 1, 0, 0, -1, -1, 1, 1};

    //Median version
    public int shortestDistance(int[][] grid) {
        // Write your code here
        if(grid == null || grid.length == 0 || grid[0].length == 0){
            return -1;
        }

        int n = grid.length;
        int m = grid[0].length;
        boolean[][] visit = new boolean[n][m];
        ArrayList<Node> house = new ArrayList<Node>();
        ArrayList<Integer> xArr = new ArrayList<Integer>();
        ArrayList<Integer> yArr = new ArrayList<Integer>();
        //find house position
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    house.add(new Node(i, j));
                    xArr.add(i);
                    yArr.add(j);
                }
            }
        }
        //no empty place
        if(house.size() == m * n){
            return -1;
        }

        if(house.size() == 0){
            return 0;
        }

        //find the median of house positions
        int xMedian = getMedian(xArr);
        int yMedian = getMedian(yArr);

        Queue<Node> queue = new LinkedList<Node>();
        queue.add(new Node(xMedian, yMedian));
        visit[xMedian][yMedian] = true;
        int min = Integer.MAX_VALUE;
        while(!queue.isEmpty()){
            int size = queue.size();
            for(int i = 0; i < size; i++){
                Node curt = queue.poll();
                if(grid[curt.x][curt.y] == 0){
                    min = Math.min(min, search(house, curt));
                }
                for(int j = 0; j < 8; j++){
                    int nextX = curt.x + dx[j];
                    int nextY = curt.y + dy[j];
                    if(nextX >= 0 && nextX < n && nextY >= 0 && nextY < m && !visit[nextX][nextY]){
                        visit[nextX][nextY] = true;
                        queue.add(new Node(nextX, nextY));
                    }
                }
            }
            if(min != Integer.MAX_VALUE){
                return min;
            }
        }

        return -1;
    }

    private int getMedian(ArrayList<Integer> arr){
        Collections.sort(arr);

        int Median = arr.get(arr.size() / 2);

        if(arr.size() % 2 == 0){
            Median = (Median + arr.get(arr.size() / 2 - 1)) / 2;
        }

        return Median;
    }

    private int search(ArrayList<Node> house, Node curt){
        int sum = 0;
        for(Node node : house){
            sum += Math.abs(curt.x - node.x) + Math.abs(curt.y - node.y);
        }
        return sum;
    }
}

//4,其实就是第一种，不过这样看来根本没必要弄那些，直接算不就出来了嘛
class Solution {
public:
    /**
     * @param grid: a 2D grid
     * @return: An integer
     */
    int shortestDistance(vector<vector<int>> &grid) {
        // write your code here
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        
        vector<int> rowCount(grid.size());
        vector<int> colCount(grid[0].size());
        
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j]) {
                    rowCount[i]++;
                    colCount[j]++;
                }
            }
        }
        
        vector<int> rowDistance(grid.size());
        vector<int> colDistance(grid[0].size());
        
        getDistances(rowCount, grid.size(), rowDistance);
        getDistances(colCount, grid[0].size(), colDistance);
        
        int shortestPath = INT_MAX;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (!grid[i][j]) {
                    shortestPath = min(shortestPath, rowDistance[i] + colDistance[j]);
                }
            }
        }
        return shortestPath;
    }
    
private:
    void getDistances(vector<int> &count, int size, vector<int> &distance) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                distance[i] += count[j] * abs(j - i);
            }
        }
    }
};

