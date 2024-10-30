#include<bits/stdc++.h>
using namespace std;
vector<int> v[1005];
bool vt[1005];
int level[1005];

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vt[src] = true;
    level[src] = 0;
    while(!q.empty())
    {
        int parent = q.front();
        q.pop();

        for(auto child : v[parent])
        {
            if(!vt[child])
            {
                q.push(child);
                vt[child] = true;
                level[child] = level[parent]+1;
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n, e ;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int src, d;
    cin >> src >> d;
    memset(vt, false, sizeof(vt));
    memset(level, -1, sizeof(level));
    bfs(src);
    // for(int i=0; i<n; i++)
    // {
    //     cout << i << " " << level[i] << endl;
    // }
    // cout << level[d];

    return 0;
}