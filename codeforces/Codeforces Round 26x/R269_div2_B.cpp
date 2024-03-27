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
    int n;
    cin >> n;
    vector<pi> v(n);
    for (int i = 1; i <= n; i++) {
        cin >> v[i - 1].F;
        v[i - 1].S = i;
    }
    vector<vector<pi> > r;
    sort(v.begin(), v.end());
    r.pb(v);
    for (int i = 1; i < v.size(); i++) {
        if (v[i - 1].F == v[i].F) {
            swap(v[i - 1], v[i]);
            r.pb(v);
        }
    }
    if (r.size() >= 3) {
        cout << "YES\n";
        for(int i=0;i<3;i++) {
            for(int j=0;j<n;j++) {
                cout << r[i][j].S << " ";
            }
            cout << endl;
        }
    }
    else {
        cout <<"NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
