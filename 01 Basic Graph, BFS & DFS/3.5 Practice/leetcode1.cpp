#include<bits/stdc++.h>
using namespace std;

char a[20][20];
bool vt[20][20];
vector<pair<int, int>> d ={{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int n, m;
bool valid(int i, int j)
{
    if( i<0 || i>=n || j<0 || j>=m)
        return false;
    return true;
}

void dfs(int si, int sj)
{
    cout << a[si] << " " << a[sj] << endl;
    vt[si][sj] = true;
    for(int i=0; i<4; i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;

        if(valid(ci, cj) == true && vt[ci][cj] == false && a[ci][cj]==1)
        {
            // a[ci][cj] = 2;
            dfs(ci, cj);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    cin  >> n >> m;
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin >> a[i][j];
        }
    }

    int si, sj;
    cin >> si >> sj;
    memset(vt, false, sizeof(vt));
    dfs(si, sj);
    return 0;
}

/*
3 4
. . . .
. . . .
. . . .
1 1
*/