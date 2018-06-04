class Solution {
    /*
     * @param k : description of k
     * @param nums : array of nums
     * @return: description of return
     */
      public int kthLargestElement(int k, ArrayList<Integer> numbers) {
        if (numbers == null || numbers.isEmpty()) return -1;

        int result = qSort(numbers, 0, numbers.size() - 1, k);
        return result;
    }

    private int qSort(ArrayList<Integer> nums, int l, int u, int k) {
        // l should not greater than u
        if (l >= u) return nums.get(u);

        // index m of nums
        int m = l;
        for (int i = l + 1; i <= u; i++) {
            if (nums.get(i) > nums.get(l)) {
                m++;
                Collections.swap(nums, m, i);
            }
        }
        Collections.swap(nums, m, l);

        if (m + 1 == k) {
            return nums.get(m);
        } else if (m + 1 > k) {
            return qSort(nums, l, m - 1, k);
        } else {
            return qSort(nums, m + 1, u, k);
        }
    }
     public int kthLargestElement(int k, int[] nums) {
        ArrayList<Integer> l = new ArrayList();
        for (int i : nums) {
            l.add(i);
        }
        // write your code here
        return kthLargestElement(k, l);

    }

  /*  public int kthLargestElements(int k, LinkedList<Integer> nums) {
        int length = nums.size();
        if (length == 0) {
            return 0;
        }
        int mid = nums.get(0);
        int cu = 0;
        LinkedList<Integer> left = new LinkedList();
        LinkedList<Integer> right = new LinkedList();
        for (int i = 0; i < length; i++) {
            if (i == 0) {
                continue;
            }
            if (nums.get(i) < mid) {
                left.add(nums.get(i));
            } else {
                right.add(nums.get(i));
            }
        }
        if (right.size() == k - 1) {
            return mid;
        } else if (right.size() < k - 1) {
            return kthLargestElements(k - 1 - right.size(), left);
        } else {
            return kthLargestElements(k, right);
        }
    }*/
};
