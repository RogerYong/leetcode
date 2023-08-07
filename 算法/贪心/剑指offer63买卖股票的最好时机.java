import java.util.*;


public class Solution {
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param prices int整型一维数组
     * @return int整型
     */
    public int maxProfit (int[] prices) {
        // write code here

        if (prices == null || prices.length <= 1 ) {
            return 0;
        }
        // prices.length >= 2

        int minPrice= prices[0];
        int maxPro = 0;
        for(int i=1;i<prices.length;++i){
            if(prices[i] >= minPrice){
                maxPro = Math.max(maxPro, prices[i]-minPrice);
            }else{
                minPrice = prices[i];
            }
        }
        return maxPro;
    }
}