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
    vi v(n), t(n + 1);
    for (int &x: v)cin >> x;
    for (int i = 0; i < n; i++)t[v[i]] = i + 1;
    if (t[1] < t[n] && t[2] < t[n]) {
        cout << max(t[1], t[2]) << " " << t[n] << endl;
    } else if (t[1] > t[n] && t[2] > t[n]) {
        cout << min(t[1], t[2]) << " " << t[n] << endl;
    } else cout << "1 1\n";
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
