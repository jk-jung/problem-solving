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
    int n, L, a;
    cin >> n >> L >> a;
    vi v(n), w(n);
    for (int i = 0; i < n; i++)cin >> v[i] >> w[i];

    int s = 0, r = 0;
    for (int i = 0; i < n; i++) {
        r += (v[i] - s) / a;
        s = v[i] + w[i];
    }
    r += (L - s) / a;
    cout << r << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
}
