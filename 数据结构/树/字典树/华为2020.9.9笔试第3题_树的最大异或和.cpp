// https://blog.csdn.net/nimphy/article/details/108502492
// 其实这个前缀树的做法我是不赞成的, 虽然这个题解的作者AC了
// 但是, 这个前缀树, 可能得到的是, 跨越左右子树的前缀和
// 这就有一个问题 根节点 ROOT    Li 是左边的第i个节点, Rj是右边的第j个节点, 那么从Li到Rj的异或和, 根节点被异或了两次

// 所以建立图的时候, 应该把点变成边, 把树节点权变成边权

// 那点权, 就是父亲,左孩子,右孩子之间的三条边的边权


#include <bits/stdc++.h>
using namespace std;
const int maxn = 200010;
int Laxt[maxn], Next[maxn], To[maxn], cnt;
// 链式前向星, 把树保存成图, 性能更高?
// 树是无环的
// Laxt[i] 第i个点的边的链表头
// Next[i] 第i条边的下一个同源边, Next[i]==0表示无更多同源边, Next[0]不是边, 所有边从1开始
// To[i] 第i条边的终点

int W[maxn], ch[maxn * 30][2], ans, node;
// W数组: 每个点到根节点的异或和
// ch: 01trie. 用数组做字典树, 同样是
// node是01trie的下一个存储空间的位置
// ch[i][0]!=0 表示是当前位0, 且下一位的索引j = ch[i][0]

void add(int u, int v)
{
    Next[++cnt] = Laxt[u];
    Laxt[u] = cnt;
    To[cnt] = v;
}
void dfs(int u, int f)
{
    // u 当前节点
    // f from节点, 上一个节点
    W[u] = W[f] ^ W[u];                   // 递归计算第i个点到根节点的异或和
    for (int i = Laxt[u]; i; i = Next[i]) // 遍历起点为u的所有边
    {
        int v = To[i];
        if (To[i] == f) // 父亲节点
            continue;
        dfs(To[i], u);
    }
}
int query(int x)
{
    // 计算最大异或和
    int now = 0, res = 0;
    for (int i = 30; i >= 0; i--)
    {
        int t = (x >> i) & 1;
        if (ch[now][1 - t]) //
            res += (1 << i), now = ch[now][1 - t];
        else
            now = ch[now][t];
    }
    return res;
}
int insert(int x)
{
    // 插入节点
    int now = 0;
    for (int i = 30; i >= 0; i--)
    {
        int t = (x >> i) & 1; // 二进制第i位
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
    // 计算W数组
    dfs(1, 0);

    // 构建前缀树
    for (int i = 1; i <= N; i++)
    {
        //
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
