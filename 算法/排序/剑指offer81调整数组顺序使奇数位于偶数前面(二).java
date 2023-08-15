import java.util.*;


public class Solution {
    // 双指针交换
    // 维护两个指针
    // 第一个指针指向左边第一个偶数
    // 第二个指针指向右边第一个计数
    public int[] reOrderArrayTwo (int[] array) {
        if(array==null){
            return array;
        }
        int nextOdd = array.length-1;
        int nextEven = 0;
        while(nextEven < nextOdd){
            while(nextEven<array.length && array[nextEven] % 2!=0){
                nextEven ++;
            }

            if(nextEven>=array.length){
                break;
            }

            while(nextOdd>=0 && array[nextOdd] % 2==0){
                nextOdd --;
            }
            if(nextOdd<=0){
                break;
            }
            if(nextEven<nextOdd){
                // 交换
                int tmp = array[nextEven];
                array[nextEven] = array[nextOdd];
                array[nextOdd] = tmp;
            }else{
                break;
            }
        }
        return array;
    }
}