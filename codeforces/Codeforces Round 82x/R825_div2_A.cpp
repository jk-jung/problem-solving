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

vi read(int n) {
    vi v(n);
    for (int &x: v)cin >> x;
    return v;
}

void solve() {
    int n;
    cin >> n;
    vi a = read(n), b = read(n);
    int c01 = 0, c10 = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            if (a[i])c10++;
            else c01++;
        }
    }
    if(!c01 || !c10) cout << c01 + c10 << endl;
    else cout << ab(c01 - c10) + 1 << endl;
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
