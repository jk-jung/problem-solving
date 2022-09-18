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
    string s;
    cin >> s;
    map<char, vi> c;
    for (int i = 1; i <= s.size(); i++)c[s[i - 1]].pb(i);
    vi r;

    for (char i = s[0];; i += (s[0] < s.back() ? 1 : -1)) {
        for (int x: c[i])r.pb(x);
        if (i == s.back())break;
    }
    cout << ab(s.back() - s[0]) << " " << r.size() << '\n';
    for(int x:r)cout << x << ' ';
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
