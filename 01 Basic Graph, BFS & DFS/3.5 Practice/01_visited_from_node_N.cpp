#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
vector<int> v[N];
bool vt[N];
int cnt = 0;

void dfs(int src)
{
    // cout << src << " ";
    cnt += 1;
    vt[src] = true;
    for(auto child : v[src])
    {
        if(!vt[child])
            dfs(child);
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
        v[a].push_back(b);
        v[b].push_back(a);
    }
    memset(vt, false, sizeof(vt));
    int f;
    cin >> f;
    dfs(f);
    cout << cnt;
    return 0;
}