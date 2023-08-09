import java.util.*;
public class Solution {

/***

参考: https://zhuanlan.zhihu.com/p/371184302

原码: 机器数真值表示的一样，即用第一位表示符号，其余位表示数值
反码: 正数的反码=原码, 负数的反码=符号位不变, 其他位取反
补码: 正数的补码=原码, 负数的补码=反码+1

计算机的内存中, 存的是补码

为什么是补码? 对cpu, 只需要加法器就能正负数/加减法, 不需要额外的逻辑


如果使用原码运算, 需要考虑符号位, cpu的实现比较麻烦.

如果用反码运算, 结果是正确的, 但是存在两个0, 分别是+0 -0.

补码能解决+0,-0的问题.

正数 负数的加法, 可以直接在补码上进行.

 */
    public int Add(int num1, int num2) {

        int sum, carry;

        do {
            sum = num1 ^ num2;
            carry = (num1 & num2) << 1;
            System.out.println(String.format("%s+%s=%s, %s", Integer.toBinaryString(num1),
                                             Integer.toBinaryString(num2), Integer.toBinaryString( sum),
                                             Integer.toBinaryString( carry)));
            num1 = sum;
            num2 = carry;
        } while (carry != 0);

        return sum;
    }
}