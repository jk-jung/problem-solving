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

vi v, ck;
string s;

int go(int x, int cnt = 0) {
    if (ck[x] != -1) return cnt;
    ck[x] = 0;
    ck[x] = go(v[x], cnt + (s[x] == '0'));
    return ck[x];
}

void solve() {
    int n;
    cin >> n;
    v.clear();
    ck.clear();
    v.resize(n);
    ck.resize(n);
    for (int i = 0; i < n; i++)ck[i] = -1;
    for (int &x: v)cin >> x, x--;
    cin >> s;
    for (int i = 0; i < n; i++) {
        int r = ck[i] == -1 ? go(i) : ck[i];
        cout << r << " ";
    }
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
