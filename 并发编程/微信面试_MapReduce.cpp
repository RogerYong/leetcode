#include <algorithm>
#include <numeric>
#include <map>
#include <string>
#include <atomic>
#include <utility>
#include <iostream>
#include <execution>
#include <time.h>

std::string get_top_domain(std::string domain) // 得到顶级域名
{
    domain.erase(domain.find_last_not_of("\t\n\v\f\r ") + 1); // 去空格
    auto idx = domain.find_last_of(".");
    if (idx != std::string::npos)
    {
        domain.erase(0, idx + 1);                                                // 得到顶级域名
        std::transform(domain.begin(), domain.end(), domain.begin(), ::tolower); // 转小写
        return domain;
    }
    else
    {
        // 没有点, 表示没有顶级域名
        domain.clear();
        return domain;
    }
}
using visit_map_type = std::unordered_map<std::string, unsigned long long>;

struct combine_visits // 一个多态的二元函数
{
    // 在reduce过程中, 因为reduce是任意顺序的
    // 要求 result类型能和元素类型 "相加" 得到result类型
    // 因此需要一个多态的binary_op
    // 支持两种类型之间的任意"求和"
    visit_map_type
    operator()(visit_map_type lhs, visit_map_type rhs) const
    {
        if (lhs.size() < rhs.size())
        {
            std::swap(lhs, rhs);
        }
        // 合并lhs和rhs
        // 把结果保持在lhs中
        for (auto const &entry : rhs)
        {
            lhs[entry.first] += entry.second;
        }
        return lhs;
    }
    visit_map_type operator()(std::string domain, visit_map_type map) const
    {
        if (domain.size() > 0)
        {
            ++map[domain];
        }
        return map;
    }
    visit_map_type operator()(visit_map_type map, std::string domain) const
    {
        if (domain.size() > 0)
        {
            ++map[domain];
        }
        return map;
    }
    visit_map_type operator()(std::string domain1, std::string domain2) const
    {
        visit_map_type map;
        if (domain1.size() > 0)
        {
            ++map[domain1];
        }
        if (domain2.size() > 0)
        {
            ++map[domain2];
        }
        return map;
    }
};

int main()
{
    // 制造数据
    visit_map_type fake = {{"com", 1000000},
                           {"cn", 1000000}};
    std::vector<std::string> domains;
    for (auto &kv : fake)
    {
        for (int i = 0; i < kv.second; ++i)
        {
            domains.push_back("shit." + kv.first);
        }
    }
    timespec t1, t2;

    clock_gettime(CLOCK_MONOTONIC, &t1);
    // 开始
    visit_map_type result = std::transform_reduce(
        std::execution::par_unseq,
        domains.begin(), domains.end(), visit_map_type(),
        combine_visits(), get_top_domain);

    clock_gettime(CLOCK_MONOTONIC, &t2);

    std::cout << (t2.tv_sec - t1.tv_sec) * 1000 + (t2.tv_nsec - t1.tv_nsec) / 1000000 << "ms" << std::endl;
    for (auto &kv : result)
    {
        std::cout << kv.first << ": " << kv.second << std::endl;
    }

    // 100W数据, 不开编译器优化, 523ms, 132ms
    // 1000W数据, 不开编译器优化, 8398ms; -O3, 2607ms
    return 0;
}