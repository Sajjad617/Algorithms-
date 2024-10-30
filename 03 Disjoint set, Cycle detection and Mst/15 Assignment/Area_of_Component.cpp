#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
char graph[N][N];
bool vis[N][N];

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
    vector<int> vc;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            if (graph[i][j] == '.' && vis[i][j] == false)
            {
                cnt=0;
                dfs(i, j);
                vc.push_back(cnt);
                
            }
        }
    }
    sort(vc.begin(), vc.end());
    if(vc.empty())
    {
        cout << -1;
    }
    else
    {
        cout << vc[0];
    }
}



// #include <bits/stdc++.h>
// using namespace std;

// const int N = 1e3 + 10;
// bool vis[N][N];
// int dx[4] = {-1, 0, 1, 0}; // row er move
// int dy[4] = {0, 1, 0, -1}; // col er move

// int n, m;
// int cnt;
// char graph[N][N];

// bool valid(int ci, int cj)
// {

//     if (ci >= 0 && ci < n && cj >= 0 && cj < m)
//     {
//         return true;
//     }
//     else
//         return false;
// }

// void bfs(int si, int sj)
// {
//     vis[si][sj] = true;

//     queue<pair<int, int>> q;
//     q.push({si, sj});

//     while (!q.empty())
//     {
//         pair<int, int> node = q.front();
//         q.pop();

//         cnt++;
//         for (int i = 0; i < 4; i++)
//         {
//             int ci = node.first + dx[i];
//             int cj = node.second + dy[i];

//             if (valid(ci, cj) && !vis[ci][cj] && graph[ci][cj]=='.')
//             {
//                 vis[ci][cj] = true;
//                 q.push({ci, cj});
//             }
//         }
//     }
// }

// int main()
// {

//     cin >> n >> m;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             cin >> graph[i][j];
//         }
//     }
//     memset(vis, false, sizeof(vis));
//     int mn = INT_MAX;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             if(!vis[i][j] && graph[i][j]=='.')
//             {
//                 cnt = 0;
//                 bfs(i ,j);
//             }

//             if(mn > cnt)
//             {
//                 mn = cnt;
//             }
//         }
//     }
//     if(mn==0)
//         cout << "-1";
//     else
//         cout << mn << endl;
// }