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

int n;
int a[555], b[555], c[555], d[555];

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++)cin >> a[i] >> b[i] >> c[i] >> d[i];
    int r = -1;
    for (int i = 0; i < n; i++) {
        bool ok = true;
        for (int j = 0; j < n; j++) {
            if (a[i] < a[j] && b[i] < b[j] && c[i] < c[j]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            if (r == -1) r = i;
            else if (d[r] > d[i]) r = i;
        }
    }
    cout << r + 1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
