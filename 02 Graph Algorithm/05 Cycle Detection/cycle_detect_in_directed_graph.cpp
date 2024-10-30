#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
bool vt[N];
bool pathvt[N];
vector<int> adj[N];
bool ans;

void dfs(int parent)
{
    vt[parent] = true;
    pathvt[parent] = true;
    for(int child : adj[parent])
    {
        if(pathvt[child])
        {
            ans = true;
        }
        if(!vt[child])
        {
            // parentarry[child] = parent;
            dfs(child);
        }
    }
    pathvt[parent] = false;
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
        // adj[b].push_back(a);

    }
    memset(vt, false, sizeof(vt));
    memset(pathvt, false, sizeof(pathvt));

    ans = false;
    for(int i=0; i<n; i++)
    {
        if(!vt[i])
            dfs(i);
    }
    if(ans) cout << "Cycle Detected";
    else cout << "Cycle Not found";
    return 0;
}