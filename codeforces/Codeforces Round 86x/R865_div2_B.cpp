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

int c[2][100005];
int r[2][100005];

void solve() {
    int n;
    cin >> n;

    vector<tuple<int, int, int>> v;
    for (int i = 0; i < n; i++) {
        c[0][i] = n - i;
        c[1][i] = i + 1;
        v.pb(make_tuple((n - i) * (i % 2 == 0 ? 1 : -1), 0, i));
        v.pb(make_tuple((i + 1) * (i % 2 == 1 ? 1 : -1), 1, i));
    }
    sort(v.begin(), v.end());
    int s =0;
    for(auto [k, y, x]: v) {
        r[y][x] = ++ s;
    }
    for (int i = 0; i < n; i++)cout << r[0][i] << " ";
    cout << endl;
    for (int i = 0; i < n; i++)cout << r[1][i] << " ";
    cout << endl;
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
