#include <bits/stdc++.h>
using namespace std;

char graph[1001][1001];
bool vis[1001][1001];

int n, m;

int dx[4] = {-1, 0, 1, 0}; // row er move
int dy[4] = {0, 1, 0, -1}; // col er move

bool valid(int x, int y)
{

    if (x >= 0 && x < n && y >= 0 && y < m && graph[x][y] == '.' || graph[x][y] == 'A' || graph[x][y] == 'B' )
    {
        return true;
    }
    else
    {
        return false;
    }
}

void dfs(int si, int sj)
{
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
    int A_row, A_column;
    int B_row, B_column;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            
            cin >> graph[i][j];
            if(graph[i][j]=='A')
            {
                A_row = i;
                A_column = j;
            }
            if(graph[i][j]=='B')
            {
                B_row = i;
                B_column = j;
            }
        }
    }

    

    dfs(A_row, A_column); // source node

    if (vis[B_row][B_column])
    {
        cout << "YES" << endl;
    }
    else
        cout << "NO";

    return 0;
}