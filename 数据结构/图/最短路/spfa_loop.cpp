#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

// int 的 INF假定为1e9,
// 或者 直接使用std::INT_MAX
#define INF 1e9

// 最大点数
#define MAXV 1000005

// 事实上c++ float的inf是 std::numeric_limits<float>::infinity()
// double 的 inf std::numeric_limits<double>::infinity()
// http://www.enseignement.polytechnique.fr/informatique/INF478/docs/Cpp/en/cpp/types/numeric_limits/infinity.html
using namespace std;

struct edge
{
    int to, cost;
};
typedef pair<int, int> P; //first是最短距离，second是顶点的编号
int V;                    //顶点个数
vector<edge> G[MAXV];     // 邻接表
int d[MAXV];              // 距离
int path[MAXV];
bool vis[MAXV];
int cnt[MAXV]; // 用于统计每个点进入队列的次数 > n 表示有负环

bool spfa_loop(int s)
{
    // 点id从0开始
    queue<int> q;
    for (int i = 0; i < MAXV; i++)
    {
        d[i] = INF;
        vis[i] = false;
        path[i] = -1;
        cnt[i] = 0;
    }

    d[s] = 0;
    q.push(s);
    vis[s] = true; // 用vis表示在queue中
    cnt[s]++;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        vis[v] = false;
        for (int i = 0; i < G[v].size(); i++)
        {
            edge e = G[v][i];
            if (d[v] + e.cost < d[e.to])
            {
                d[e.to] = d[v] + e.cost;
                path[e.to] = v;

                cnt[e.to]++;
                if (cnt[e.to] >= V)
                {
                    return true; // 存在负环
                }

                if (!vis[e.to])
                {
                    q.push(e.to);
                    vis[e.to] = true;
                }
            }
        }
    }
    return false; // 没有负环
}