#include<bits/stdc++.h>
using namespace std;
char  graph[1005][1005];
bool vt[1005][1005];
int dis[1005][1005];
pair<int, int> parent[1005][1005];
int r, c;
int cnt= 0;
vector<pair<int, int>> d = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
bool valid(int ci, int cj)
{
    if(ci>=0 && ci<r && cj>=0 && cj<c)
        return true;
    else
        return false;
}

void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    vt[si][sj] = true;
    dis[si][sj] = 0;
    while(!q.empty())
    {
        pair<int, int> p = q.front();
        int a = p.first, b = p.second;
        q.pop();
        for(int i=0; i<4; i++)
        {
            int ci = a + d[i].first;
            int cj = b + d[i].second;
            // if(valid(ci, cj) && !vt[ci][cj] && graph[ci][cj]=='.' || graph[ci][cj]=='A' || graph[ci][cj]=='B')
            if(valid(ci, cj) && !vt[ci][cj] && graph[ci][cj]!='#')
            {
                // cnt++;
                q.push({ci, cj});
                vt[ci][cj] = true;
                dis[ci][cj] = dis[a][b]+1;
                parent[ci][cj] = {a,b};
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    // int r, c;
    cin >> r >> c;
    int si, sj, di, dj;
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            cin >> graph[i][j];
            if(graph[i][j]=='A')
            {
                si = i;
                sj = j;
            }
            if(graph[i][j]=='B')
            {
                di = i;
                dj = j;
            }
        }
    }
    // for(int i=0; i<r; i++)
    // {
    //     for(int j=0; j<c; j++)
    //     {
    //         cout << graph[i][j];
    //     }
    //     cout << endl;
    // }

    
    memset(vt, false, sizeof(vt));
    memset(dis, -1, sizeof(dis));
    bfs(si, sj);
    if(vt[di][dj])
    {
        cout << "YES\n" << dis[di][dj] << endl;
        pair<int, int> p ={di, dj};
        vector<pair<int, int>> path;
        while(!(p.first == si && p.second == sj))
        {
            path.push_back(p);
            p = parent[p.first][p.second];
        }
        path.push_back({si, sj});
        reverse(path.begin(), path.end());

        string ans = "";
        for(int i=1; i<path.size(); i++)
        {
            if(path[i-1].first == path[i].first)
            {
                if(path[i-1].second+1 == path[i].second)
                    ans += "R";
                else
                    ans += "L";
            }
            else
            {
                if(path[i-1].first+1 == path[i].first)
                    ans += "D";
                else
                    ans += "U";
            }
        }
        cout << ans << endl;
    }
    else
    {
        cout << "NO\n";
    }

    return 0;
}