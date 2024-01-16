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

string s;
int n;
int d[100005][4];

int go(int idx, int len) {
    if (idx + len > n) return 0;
    if (idx + len == n)return 1;
    int &r = d[idx][len];
    if (r != -1)return r;

    r = 0;

    string a = s.substr(idx, len);
    string b = s.substr(idx + len, len);

    if (a != b && go(idx + len, len))r = 1;
    if (go(idx + len, len == 2 ? 3 : 2))r = 1;
    return r;
}

void solve() {
    memset(d, -1, sizeof(d));
    cin >> s;
    n = s.size();

    set<string> r;
    for (int i = 5; i < n; i++) {
        for (int j = 2; j <= 3; j++) {
            if (go(i, j))r.insert(s.substr(i, j));
        }
    }
    cout << r.size() << endl;
    for (auto x: r)cout << x << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
