import java.util.*;

/**
 * 排序法
 * 空间复杂度O(n)
 * 
 * insert 时间复杂度O(n) 
 * GetMedian 时间复杂度O(1)
 */


public class Solution {
    private List<Integer> data = new ArrayList<>();
    public void Insert(Integer num) {
        data.add(num);
        if (data.size() > 1) {
            int i = data.size() - 1;
            for (; i > 0 && num < data.get(i - 1); --i) {
                data.set(i, data.get(i - 1));
            }
            data.set(i, num);
        }
    }

    public Double GetMedian() {
        if (data.isEmpty()) {
            return 0.0;
        } else if (data.size() % 2 == 0) {
            return Double.valueOf( data.get(data.size() / 2 )  + data.get(
                                       data.size() / 2 - 1 ) ) / 2.0;
        } else {
            return Double.valueOf( data.get((data.size() - 1) / 2 ));
        }
    }
}