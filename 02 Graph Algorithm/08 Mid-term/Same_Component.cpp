#include <bits/stdc++.h>
using namespace std;

char graph[1001][1001];
bool vis[1001][1001];

int n, m;

int dx[4] = {-1, 0, 1, 0}; // row er move
int dy[4] = {0, 1, 0, -1}; // col er move

bool valid(int x, int y)
{

    if (x >= 0 && x < n && y >= 0 && y < m && graph[x][y] == '.')
    {
        return true;
    }
    else
    {
        return false;
    }
}
int cnt = 0;
void dfs(int si, int sj)
{
    cnt++;
    vis[si][sj] = true;

    for (int i = 0; i < 4; i++)
    {

        int ci = si + dx[i]; // children er row
        int cj = sj + dy[i]; // children er column

        if (valid(ci, cj) && vis[ci][cj] == false)
        {
            vis[ci][cj] = true;
            dfs(ci, cj);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> graph[i][j];
        }
    }

    int si, sj;
    cin >> si >> sj;
    dfs(si, sj);

    int di, dj;
    cin >> di >> dj;
    if(vis[di][dj])
        cout << "YES";
    else
        cout << "NO";
    // int cnt = 0;
  

    // cout << cnt << endl;
}