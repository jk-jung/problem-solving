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

void solve() {
    int n, m;
    string s;
    cin >> n >> m >> s;
    vi v(m);
    for (int &x: v)cin >> x;
    sort(v.begin(), v.end());
    int last = 0;

    vi r(26), c(26);
    v.pb(n);
    for (int x: v) {
        while (last < x)c[s[last++] - 'a']++;
        for (int i = 0; i < 26; i++)r[i] += c[i];
    }
    for (int x: r) cout << x << " ";
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
