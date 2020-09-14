// POJ1502 MPI Maelstrom
// 分布式系统的一次广播的用时
// 也就是单源最短路的最大距离
// 同类型的题: LeetCode 743
/*
测试用例

输入:
5
50
30 5
100 20 50
10 x x 10

输出:
35
*/

// #include <bits/stdc++.h>
#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <utility>

#define ll long long
#define ull unsigned long long

// int 的 INF假定为1e9,
// 或者 直接使用INT_MAX
#define INF 1e9

// 最大点数
#define MAXV 105
using namespace std;

struct edge
{
    int to, cost;
};
typedef pair<int, int> P; //first是最短距离，second是顶点的编号
int V;                    //顶点个数
vector<edge> G[MAXV];     // 邻接表
int d[MAXV];              // 距离
// int path[MAXV];           // 路径
bool vis[MAXV];

int max_cost = 0;

void string_split(string &s, vector<string> &sv, const string &delimiters = " \t\n\v\f\r")
{
    // c++ 中的space
    //
    // ' '	(0x20)	space (SPC)
    // '\t'	(0x09)	horizontal tab (TAB)
    // '\n'	(0x0a)	newline (LF)
    // '\v'	(0x0b)	vertical tab (VT)
    // '\f'	(0x0c)	feed (FF)
    // '\r'	(0x0d)	carriage return (CR
    sv.clear();

    string::size_type lastPos = s.find_first_not_of(delimiters, 0);
    string::size_type pos = s.find_first_of(delimiters, lastPos);

    // [lastpos, pos) 是新的字符串
    while (lastPos != string::npos || pos != string::npos)
    {
        sv.push_back(s.substr(lastPos, pos - lastPos));
        // 为了减少临时变量, c++11后使用emplace_back
        // sv.emplace_back(s, lastPos, pos - lastPos);

        lastPos = s.find_first_not_of(delimiters, pos);
        pos = s.find_first_of(delimiters, lastPos);
    }
}

string &ltrim(string &str, const string &chars = "\t\n\v\f\r ")
{
    str.erase(0, str.find_first_not_of(chars));
    return str;
}

string &rtrim(string &str, const string &chars = "\t\n\v\f\r ")
{
    str.erase(str.find_last_not_of(chars) + 1);
    return str;
}

string &trim(string &str, const string &chars = "\t\n\v\f\r ")
{
    return ltrim(rtrim(str, chars), chars);
}

void dijkstra(int s)
{
    priority_queue<P, vector<P>, greater<P>> que;
    for (int i = 0; i < MAXV; i++)
    {
        d[i] = INF;
        vis[i] = false;
        // path[i] = -1;
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

        if (d[v] > max_cost)
        {
            max_cost = d[v];
        }

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

                // path[e.to] = v; // 更新路径
            }
        }
    }
}

int main()
{
    // input
    // cin >> V;
    // getchar(); // 下面使用getline, 这里需要把\n吃掉
    scanf("%d\n", &V);
    if (V == 1)
    {
        cout << 0 << endl;
        return 0;
    }
    string line;
    vector<string> buffer;
    int tmp_dis;

    for (int i = 1; i <= V - 1; ++i)
    {
        // V-1行邻接矩阵
        getline(cin, line); // 避免空格 // 注意getline前, 需要吃掉之前的空格
        trim(line);
        string_split(line, buffer);
        for (int j = 0; j < buffer.size(); ++j)
        {
            if (buffer[j] == "x")
            {
                continue;
            }
            else
            {
                // i to j 的距离
                // tmp_dis = stoi(buffer[j]); // c++ 11有stoi
                tmp_dis = atoi(buffer[j].c_str());

                edge i_to_j, j_to_i;

                i_to_j.to = j;
                i_to_j.cost = tmp_dis;

                j_to_i.to = i;
                j_to_i.cost = tmp_dis;

                // 构建邻接表
                G[i].push_back(i_to_j);
                G[j].push_back(j_to_i);
            }
        }
    }

    // dij
    dijkstra(0);

    // output
    cout << max_cost << endl;
    return 0;
}