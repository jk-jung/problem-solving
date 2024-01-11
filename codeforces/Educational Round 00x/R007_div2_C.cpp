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
    int n, m;
    cin >> n >> m;
    vi v(n), t(n);
    for (int &x: v)cin >> x;
    int a = n, b = n;
    v.pb(-1);
    for (int i = n - 1; i >= 0; i--) {
        if (v[a] != v[i]) t[i] = a;
        else t[i] = b;

        if (v[a] == v[i])a = i;
        else if (v[b] == v[i])b = i;
        else {
            b = a;
            a = i;
        }
    }

    while (m--) {
        int s, e, k;
        cin >> s >> e >> k;
        s--, e--;
        if(v[s] != k)cout << s + 1 << endl;
        else cout << (t[s] <= e ? t[s] + 1 : -1) << endl;
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
