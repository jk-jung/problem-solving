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

int a[2][55];

void solve() {
    int n, l;
    cin >> n >> l;

    vi A, B;
    for (int i = 0; i < n; i++)cin >> a[0][i];
    for (int i = 0; i < n; i++)cin >> a[1][i];
    a[0][n] = l + a[0][0];
    a[1][n] = l + a[1][0];
    for (int i = 1; i <= n; i++)A.pb(a[0][i] - a[0][i - 1]);
    for (int i = 1; i <= n; i++)B.pb(a[1][i] - a[1][i - 1]);

    for (int k = 0; k <= n; k++) {
        if(A == B) {
            cout <<"YES\n";
            return;
        }
        int t = A[0];
        for (int i = 0; i < n - 1; i++)A[i] = A[i + 1];
        A[n-1] = t;
    }
    cout <<"NO";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
