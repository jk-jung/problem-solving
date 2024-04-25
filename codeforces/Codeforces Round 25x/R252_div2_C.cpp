#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define ab(x) (((x) < 0) ? -(x) : (x))

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<pi> v;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i % 2 == 0)v.pb(mp(i + 1 ,j + 1));
            else v.pb(mp(i + 1,m-j));
        }
    }
    for(int i=0;i<k-1;i++){
        cout << 2 <<" ";
        cout << v.back().F <<" " << v.back().S <<" ";
        v.pop_back();
        cout << v.back().F <<" " << v.back().S <<" ";
        v.pop_back();
        cout << endl;
    }
    cout << v.size() <<" ";
    for(auto x:v)cout << x.F <<" " << x.S <<" ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
