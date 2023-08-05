# c++ 
lower_bound
upper_bound

  本文主要讲lowe_bound和upper_bound这两个底层皆基于二分查找，当然STL标准库中还有 equal_range() 和 binary_search() 也是基于二分查找实现的。读者可自行了解！

C++ lower_bound()函数
       lower_bound() 函数用于在指定区域内查找不小于目标值的第一个元素。也就是说，使用该函数在指定范围内查找某个目标值时，最终查找到的不一定是和目标值相等的元素，还可能是比目标值大的元素。
       以下为其常用的两种用法：
       //在 [first, last) 区域内查找不小于 val 的元素
ForwardIterator lower_bound (ForwardIterator first, ForwardIterator last,const T& val);

       //在 [first, last) 区域内查找第一个不符合 comp 规则的元素
ForwardIterator lower_bound (ForwardIterator first, ForwardIterator last, const T& val, Compare comp);

C++ upper_bound()函数
       lower_bound()函数 用于在指定范围内查找**大于**目标值的第一个元素。
       以下为其常用的两种用法（与lower_bound类似）：
       //查找[first, last)区域中第一个大于 val 的元素。
ForwardIterator upper_bound (ForwardIterator first, ForwardIterator last,const T& val);

       //查找[first, last)区域中第一个不符合 comp 规则的元素
ForwardIterator upper_bound (ForwardIterator first, ForwardIterator last, const T& val, Compare comp);
————————————————
版权声明：本文为CSDN博主「叫我蘑菇先生」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/weixin_43305485/article/details/122347842


# java

Arrays.binarySearch

# python 

bisect