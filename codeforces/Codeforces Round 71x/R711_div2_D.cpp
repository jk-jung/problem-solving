#include <string.h>
#include <stdio.h>
#include <math.h>
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

int r[100005];
int ck[100005], CK;

void solve() {
    ll n, m;
    cin >> n >> m;

    r[0] = 1;
    for (ll k = 0, t, x, y; k < n; k++) {
        cin >> t >> x >> y;
        ll yy = y;
        CK++;
        for (ll i = m; i >= 0; i--) {
            if (!r[i]) continue;
            y = yy;
            for (ll j = i; j <= m && y >= 0; y--) {
                if (ck[j] == CK) break;
                ck[j] = CK;
                if (!r[j]) r[j] = k + 1;

                if (t == 1) j = j + (x + 99999) / 100000;
                else j = (j * x + 99999) / 100000;
            }
        }
    }

    for (int i = 1; i <= m; i++)cout << (r[i] == 0 ? -1 : r[i]) << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
