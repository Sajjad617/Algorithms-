// Problem link: https://www.spoj.com/problems/NAKANJ/

#include <bits/stdc++.h>
using namespace std;
bool vis[105][105];
int dis[105][105];
vector<pair<int, int>> d = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1},{1, 2}, {1, -2}, {-1, 2}, {-1, -2}};
int n, m;

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}

void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    dis[si][sj] = 0;
    while (!q.empty())
    {
        pair<int, int> par = q.front();
        int a = par.first, b = par.second;
        q.pop();
        for (int i = 0; i < 8; i++)
        {
            int ci = a + d[i].first;
            int cj = b + d[i].second;
            if (valid(ci, cj) == true && vis[ci][cj] == false)
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
                dis[ci][cj] = dis[a][b] + 1;
            }
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        // n = 8, m = 8;

        // string s,d;
        // cin >> s >> d;
        int si, sj, di, dj;
        cin >> si >> sj >> di >> dj;
        // si = s[0] - 'a';
        // sj = s[1] - '1';
        // di = d[0] - 'a';
        // dj = d[1] - '1';
        
        memset(vis, false, sizeof(vis));
        memset(dis, -1, sizeof(dis));
        bfs(si, sj);
        if(dis[di][dj]==-1)
            cout << -1 << endl;
        else
            cout << dis[di][dj] << endl;
    }
    
    return 0;
}