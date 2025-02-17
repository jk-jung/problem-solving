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


ll d[100005];

ll a[100005];
ll b[100005];
ll c[100005];

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 0; i < m; i++)
        cin >> a[i] >> b[i] >> c[i];
    ll r = 0;
    while (k--) {
        int x;
        cin >> x;


        for (int i = 0; i < m; i++) {
            if (a[i] <= x && x <= b[i]) {
                r += c[i] + x - a[i];
            }
        }
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
