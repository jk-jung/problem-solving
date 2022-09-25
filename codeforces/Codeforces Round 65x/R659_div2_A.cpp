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
    vector<string> r;
    r.pb(string(100, 'a'));
    for (int i = 1, x; i <= n; i++) {
        cin >> x;
        string a;
        for (int k = 0; k < x; k++)a += r.back()[k];
        char t = (r.back()[x] - 'a' + 1) % 26 + 'a';
        while (a.size() < 100)a += t;
        r.pb(a);
    }
    for (auto x: r)cout << x << endl;
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
