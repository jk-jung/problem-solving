#include <cstring>
#include <cstdio>
#include <cmath>
#include <cassert>
#include <set>
#include <map>
#include <array>
#include <stack>
#include <queue>
#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

#define mp    make_pair
#define pb    push_back
#define F     first
#define S     second
#define ab(x) (((x)<0)?-(x):(x))

void solve() {
    int n, k;
    cin>>n>>k;
    vector<pi> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i].F;
        v[i].S = i + 1;
    }
    vector<pi> r;
    while(true){
        sort(v.begin(), v.end());
        if(v[0].F == v.back().F)break;
        r.pb(mp(v.back().S, v[0].S));
        v.back().F--;
        v[0].F++;
        if(-- k == 0)break;
    }
    sort(v.begin(), v.end());
    int rr = v.back().F - v[0].F;
    cout << rr <<" " << r.size() << endl;
    for(auto [x, y]: r)cout << x <<" " << y << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
}

