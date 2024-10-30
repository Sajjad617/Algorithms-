#include<bits/stdc++.h>
using namespace std;

bool vt[20][20];
int di[20][20];
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int n, m;
char a[20][20];
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
    vt[si][sj] = true;
    di[si][sj] = 0;
    while(!q.empty())
    {
        pair<int, int> par = q.front();
        int a = par.first, b = par.second;
        q.pop();
        for(int i=0; i<4; i++)
        {
            int ci = a + d[i].first;
            int cj = b + d[i].second;
            if(valid(ci, cj) == true && vt[ci][cj]==false)
            {
                q.push({ci, cj});
                vt[ci][cj] = true;
                di[ci][cj] = di[a][b]+1;
            }
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
            cin >> a[i][j];
        }
    }
    int si, sj;
    cin >> si >> sj;
    memset(vt, false, sizeof(vt));
    memset(di, -1, sizeof(di));
    bfs(si, sj);
    cout << di[1][5];
    return 0;
}

/*
3 4
. . . .
. . . .
. . . .
1 1
*/