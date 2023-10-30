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
    cin >> n >> k;
    vector<pi> v(n);
    for(int i=0;i<n;i++)cin>>v[i].F;
    for(int i=0;i<n;i++)cin>>v[i].S, v[i].F -= v[i].S;
    sort(v.begin(), v.end());
    int r = 0;
    for (int i = 0; i < n; i++) {
        if (i < k)r += v[i].F + v[i].S;
        else r += min(v[i].F + v[i].S, v[i].S);
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
