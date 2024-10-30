#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, e;
    cin >> n >> e;
    vector<int> mat[n];
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        mat[a].push_back(b);
        mat[b].push_back(a);
    }
    // vector<int> v;
    int t;
    cin >> t;
    while(t--)
    {
        int f;
        cin >> f;
        vector<int>v;
        for (int i = 0; i < mat[f].size(); i++)
        {
            v.push_back(mat[f][i]);
            // cout << mat[f][i] << " ";
        }
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        if(v.empty())
            cout << -1;
        else{

            for(auto x : v)
            {
                cout << x << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
}