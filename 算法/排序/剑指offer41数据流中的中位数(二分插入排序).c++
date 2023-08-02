

/**
 * 排序法
 * 空间复杂度O(n)
 * 
 * insert 时间复杂度O(n). 二分查找O(logn), 数组中挪数据则是O(n) 
 * GetMedian 时间复杂度O(1)
 * 
 * 注: 这里二分只能用数组, 不能用链表. 否则查找时间复杂度会很高.
 */


class Solution {
public:
    #define SCD static_cast<double>
    vector<int> v;
    void Insert(int num)
    {
        if (v.empty()) {
            v.push_back(num);
        }
        else {
            auto it = lower_bound(v.begin(), v.end(), num);
            v.insert(it, num);
        }
    }

    double GetMedian()
    { 
        int sz = v.size();
        if (sz & 1) {
            return SCD(v[sz >> 1]);
        }
        else {
            return SCD(v[sz >> 1] + v[(sz - 1) >> 1]) / 2;
        }
    }

};