#include<bits/stdc++.h>
using namespace std;
vector<int> v[1005];
bool vt[1005];
void bfs(int src, int des)
{
    queue<pair<int, int>> q;
    q.push({src, 0});
    vt[src] = true;
    bool paici = false;
    while(!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        int parent = p.first;
        int level = p.second;
        if(parent == des)
        {
            cout << level << endl;
            paici = true;
        }
        for(auto child : v[parent])
        {
            if(!vt[child])
            {
                q.push({child, level+1});
                vt[child] = true;
                
            }
        }
        if(paici == false)
            cout << -1 << endl;
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
    int src;
    cin >> src;
    memset(vt, false, sizeof(vt));
    bfs(src, 9);
    return 0;
}