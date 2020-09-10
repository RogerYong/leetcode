#include <bits/stdc++.h>
using namespace std;
const int maxn = 200010;
int Laxt[maxn], Next[maxn], To[maxn], cnt;
int W[maxn], ch[maxn * 30][2], ans, node;
void add(int u, int v)
{
    Next[++cnt] = Laxt[u];
    Laxt[u] = cnt;
    To[cnt] = v;
}
void dfs(int u, int f)
{
    W[u] = W[f] ^ W[u];
    for (int i = Laxt[u]; i; i = Next[i])
    {
        int v = To[i];
        if (To[i] == f)
            continue;
        dfs(To[i], u);
    }
}
int query(int x)
{
    int now = 0, res = 0;
    for (int i = 30; i >= 0; i--)
    {
        int t = (x >> i) & 1;
        if (ch[now][1 - t])
            res += (1 << i), now = ch[now][1 - t];
        else
            now = ch[now][t];
    }
    return res;
}
int insert(int x)
{
    int now = 0;
    for (int i = 30; i >= 0; i--)
    {
        int t = (x >> i) & 1;
        if (!ch[now][t])
            ch[now][t] = ++node;
        now = ch[now][t];
    }
}
int main()
{
    int N, id, x;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
    {
        scanf("%d", &id);
        scanf("%d", &W[id]);
        for (int j = 1; j <= 2; j++)
        {
            scanf("%d", &x);
            if (x != -1)
            {
                add(id, x);
                add(x, id);
            }
        }
    }
    dfs(1, 0);
    for (int i = 1; i <= N; i++)
    {
        if (i > 1)
            ans = max(ans, query(W[i]));
        insert(W[i]);
    }
    printf("%d\n", ans);
    return 0;
}
/*
5
1 1 2 3
2 4 -1 -1
3 2 -1 4
4 5 -1 5
5 3 -1 -1
*/
