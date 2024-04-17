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
    vi a(n), b(n);
    map<int, int> ck;
    for (int i = 0; i < n; i++) {
        cin >> a[i], b[i] = k * i;
        if (a[i] - k * i > 0)
            ck[b[i] - a[i]]++;
        else ck[b[i] - a[i]] -= 1000000;
    }
    int r = 0, rr = 1 << 30;
    for (auto i: ck) {
        if (i.S > r) r = i.S, rr = i.F;
    }
    cout << n - r << endl;

    for (int i = 0; i < n; i++) {
        int val = b[i] - a[i];
        if (val != rr) cout << (val > rr ? '+' : '-') << " " << i + 1 << ' ' << ab(val - rr) << endl;
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
}
