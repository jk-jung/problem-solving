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
    vi v(n);
    vector<pi> R(n + 1);
    for (int &x: v)cin >> x;
    R[n] = {1 << 30, -1};
    for (int i = n - 1; i >= 0; i--) {
        R[i] = min(R[i + 1], {v[i], i});
    }
    for (int i = 0, s = 1 << 30, idx = -1; i < n - 1; i++) {
        if(s < v[i] && v[i] > R[i + 1].F) {
            cout <<"YES\n";
            cout << idx + 1 <<" " << i + 1 << " "<< R[i + 1].S + 1 << endl;
            return;
        }
        if (v[i] < s) {
            s = v[i];
            idx = i;
        }
    }
    cout <<"NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
