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

// 参考https://blog.csdn.net/qq_38649940/article/details/108391045
void dijkstra(int s)
{

    priority_queue<P, vector<P>, greater<P>> que;
    for (int i = 0; i < MAXV; i++)
    {
        d[i] = INF;
        vis[i] = false;
        path[i] = -1;
    }

    d[s] = 0;
    que.push(P(0, s)); //把起点推入队列

    while (!que.empty())
    {
        P p = que.top();
        que.pop();
        int v = p.second; //顶点的编号

        if (vis[v])
        {
            continue;
        }
        vis[v] = true;
        for (int i = 0; i < G[v].size(); i++)
        {
            edge e = G[v][i];
            if (vis[e.to])
            {
                continue;
            }
            if (d[e.to] > d[v] + e.cost)
            {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));

                path[e.to] = v; // 更新路径
            }
        }
    }
}