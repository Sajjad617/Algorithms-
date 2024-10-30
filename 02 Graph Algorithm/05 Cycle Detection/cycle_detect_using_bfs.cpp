#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
bool vt[N];
vector<int> adj[N];
int parentarry[N];
bool ans;

void bfs(int s)
{
    queue<int> q;
    q.push(s);
    vt[s] = true;
    while(!q.empty())
    {
        int parent = q.front();
        q.pop();
        for(int child : adj[parent])
        {
            if(vt[child] && child != parentarry[parent])
            {
                ans = true;
            }
            if(!vt[child])
            {
                parentarry[child] = parent;
                vt[parent] = true;
                q.push(child);
                // dfs(child);
            }
        }

    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n, e;
    cin >> n >> e;
    while(e--)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);

    }
    memset(vt, false, sizeof(vt));
    memset(parentarry, -1, sizeof(parentarry));

    ans = false;
    for(int i=0; i<n; i++)
    {
        if(!vt[i])
            bfs(i);
    }
    if(ans) cout << "Cycle Detected";
    else cout << "Cycle Not found";
    return 0;
}