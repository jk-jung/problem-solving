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
    for (int &x: v)cin >> x;
    vi r;
    r.pb(v[0]);
    for (int i = 1; i < n; i++)r.pb(v[i] - v[i - 1]);

    vi rr;
    for (int i = 1; i <= n; i++) {
        bool ok = true;
        if(i == 4){
            i = i;
        }
        for (int j = 0; j < n; j++) {
            if (r[j] != r[j % i])ok = false;
        }
        if (ok)rr.pb(i);
    }
    cout << rr.size() << endl;
    for (int x: rr)cout << x << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
