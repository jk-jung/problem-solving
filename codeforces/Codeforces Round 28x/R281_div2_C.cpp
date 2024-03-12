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
    vi a(n);
    vi v;
    for (int &x: a)cin >> x, v.pb(x), v.pb(x - 1), v.pb(x + 1);
    int m;
    cin >> m;
    vi b(m);
    for (int &x: b)cin >> x, v.pb(x), v.pb(x - 1), v.pb(x + 1);;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    int A = 0, B = 1 << 30;
    int i = 0, j = 0;
    for (int x: v) {
        while(i < n && a[i] < x)i++;
        while(j < m && b[j] < x)j++;
        int A1 = 3 * (n - i) + 2 * i;
        int B1 = 3 * (m - j) + 2 * j;
        if (A1 - B1 > A - B)A = A1, B = B1;
        else if (A1 - B1 == A - B && A1 > A) A = A1, B = B1;
    }

    cout << A << ":" << B << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
