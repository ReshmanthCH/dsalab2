//Finding the number of winners of a game using Binary Search Tree
#include <bits/stdc++.h>
using namespace std;

#define _test   int _TEST; cin>>_TEST; while(_TEST--)
 
int main()
{
    _test
    {
        int n, q, x, y;
        cin >> n >> q;
        cin >> x;
        while(--n) cin >> y;
        while(q--) {
            cin >> y;
            cout << min(x-1, y) << ' ';
        }
        cout << '\n';
 
    }
}