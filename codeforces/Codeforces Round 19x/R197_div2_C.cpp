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
    string s;
    cin >> s;
    int n;
    cin >> n;
    vi v;
    for (int i = 0; i < 10; i++) {
        if (s[i] == '1')v.pb(i + 1);
    }
    if (v.size() == 0) {
        cout << "NO\n";
        return;
    }
    if (v.size() == 1 && n >= 2) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    cout << v[0] << " ";
    for (int i = 1; i < n; i++)cout << v.back() << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
