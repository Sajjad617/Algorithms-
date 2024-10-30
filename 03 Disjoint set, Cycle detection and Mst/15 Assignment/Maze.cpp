#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
bool vis[N][N];
int dx[4] = {-1, 1, 0, 0}; // row er move
int dy[4] = {0, 0, -1, 1}; // col er move
map<pair<int, int>, pair<int, int>> par;
int n, m;
char graph[N][N];

bool valid(int ci, int cj)
{

    if (ci >= 0 && ci < n && cj >= 0 && cj < m)
    {
        return true;
    }
    else
        return false;
}

void bfs(int si, int sj)
{
    vis[si][sj] = true;

    queue<pair<int, int>> q;
    q.push({si, sj});

    while (!q.empty())
    {
        pair<int, int> node = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ci = node.first + dx[i];
            int cj = node.second + dy[i];

            if (valid(ci, cj) && !vis[ci][cj] && graph[ci][cj] != '#')
            {
                vis[ci][cj] = true;
                q.push({ci, cj});
                par[{ci, cj}] = {node.first, node.second};
            }
        }
    }
}

int main()
{

    cin >> n >> m;

    memset(vis, false, sizeof(vis));
    int si, sj, di, dj;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> graph[i][j];
            if(graph[i][j]=='D')
            {
                si = i;
                sj = j;
            }
            else if(graph[i][j]=='R')
            {
                di = i;
                dj = j;
            }

        }
    }
    bfs(si, sj);
    if(vis[di][dj])
    {
        int sti = par[{di, dj}].first, stj = par[{di, dj}].second;
        while (true)
        {
            if(graph[sti][stj] == 'D') break;

            graph[sti][stj] = 'X';
            int Nsti = par[{sti, stj}].first;
            int Nstj = par[{sti, stj}].second;
            sti = Nsti;
            stj = Nstj;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << graph[i][j];
        }
        cout << endl;
    }
}