#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int ary[n+1];
        int mx1 = INT_MIN;
        int mx2 = INT_MIN;
        int idx1;
        int idx2;
        for(int i=0; i<n; i++)
        {
            cin >> ary[i];
            if(mx1 < ary[i])
            {
                mx1 = ary[i];
                idx1 = i;
            }
        }
        for(int i=0; i<n; i++)
        {
            if(mx2 < ary[i] && idx1!=i)
            {
                // cout << "##" << endl;
                mx2 = ary[i];
                idx2 = i;
            }
        }
        if(idx1 < idx2)
            cout << idx1 << " " << idx2 << endl;
        else
            cout << idx2 << " " << idx1 << endl;


        // cout << ary[idx1] << " " << ary[idx2] << endl;
        
    }
    return 0;
}