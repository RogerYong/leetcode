// Dijkstra的邻接矩阵版
// 感觉邻接矩阵没有邻接表好用
#define INF 0x3f3f3f3f
// max是最大点数
#define Max 10000

int adj_matrix[Max][Max]; //adj_matrix[i][j]代表从i->j的距离，不通设为无穷大
int dis[Max];             //dis[i]代表从起点到i的最短距离
bool vis[Max];            //vis[i]代表点i是否在S中
int n;                    //n个顶点

void Dijkstra(int s)
{
    // 点的id从1开始
    for (int i = 1; i <= n; i++) //初始化dis数组
        dis[i] = adj_matrix[s][i];

    for (int i = 1; i <= n; i++) //初始化vis数组
        vis[i] = false;
    dis[s] = 0;

    for (int i = 1; i <= n; i++)
    {
        int minDis = INF;
        int k = -1; //找到与s最近的顶点k
        for (int j = 1; j <= n; j++)
        {
            if (vis[j] == false && dis[j] < minDis)
            {
                minDis = dis[j];
                k = j;
            }
        }
        if (k == -1)
        {
            // 没有这个点
            break;
        }
        vis[k] = true;

        for (int j = 1; j <= n; j++)
        {
            if (!vis[j] && adj_matrix[k][j] < INF)
            {
                if (dis[j] > dis[k] + adj_matrix[k][j])
                    dis[j] = dis[k] + adj_matrix[k][j];
            }
        }
    }
}