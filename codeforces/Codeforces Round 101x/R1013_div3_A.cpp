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

void solve() {
    int n;
    cin >> n;
    vi v(n);
    for (int &x: v)cin >> x;
    map<int, int> ck = {
            {0, 3},
            {1, 1},
            {2, 2},
            {3, 1},
            {5, 1}
    };
    int tot = 0;
    for (int i = 0; i < n; i++) {
        int x = v[i];
        if (--ck[x] == 0)tot++;
        if (tot == 5) {
            cout << i + 1 << endl;
            return;
        }
    }
    cout << "0\n";
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
