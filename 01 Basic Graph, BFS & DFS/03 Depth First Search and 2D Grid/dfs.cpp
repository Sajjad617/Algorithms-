#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
vector<int> v[N];
bool vt[N];

void dfs(int src)
{
    cout << src << " ";
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
    dfs(0);
    return 0;
}

/*
Input
6 6
0 1
0 2
0 3
1 4
3 5
3 2

Output
All value
0 1 4 2 3 5
*/