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


#define MOD 1000000007


void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<char, int> c;
    int m = 0;
    for (char x: s)m = max(m, ++c[x]);
    int cnt = 0;
    for (auto [x, y]: c)cnt += y == m;

    ll r = 1;
    for (int i = 0; i < n; i++)r = (r * cnt) % MOD;
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
