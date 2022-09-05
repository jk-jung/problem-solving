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

int a[55][55];
int aa[55];
int bb[55];

void solve() {
    int n, m;
    memset(a, 0,sizeof(a));
    memset(aa, 0,sizeof(aa));
    memset(bb, 0,sizeof(bb));
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            aa[i] += a[i][j];
            bb[j] += a[i][j];
        }
    }
    int v1 = n, v2 = m;
    for (int i = 0; i < n; i++)v1 -= (aa[i] > 0);
    for (int i = 0; i < m; i++)v2 -= (bb[i] > 0);

    int v = min(v1, v2);
    cout << (v % 2 ? "Ashish" : "Vivek") << endl;
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
