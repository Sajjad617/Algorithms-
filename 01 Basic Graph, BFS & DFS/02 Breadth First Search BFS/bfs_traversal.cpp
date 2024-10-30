#include<bits/stdc++.h>
using namespace std;
vector<int> v[1005];
bool vt[1005];

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vt[src] = true;

    while(!q.empty())
    {
        int parent = q.front();
        q.pop();
        cout << parent << endl;
        for(auto child : v[parent])
        {
            if(vt[child]==false)
            {
                q.push(child);
                vt[child] = true;
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
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int src; 
    cin >> src;
    memset(vt, false, sizeof(vt));
    bfs(src);
    return 0;
}