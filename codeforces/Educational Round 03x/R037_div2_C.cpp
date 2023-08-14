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
    vi v(n);
    for (int &x: v)cin >> x;
    vi t = v;
    sort(t.begin(), t.end());
    string s;
    cin >> s;
    s += '0';
    for (int i = 0, a = 0, b = 0; i < n; i++) {
        if (s[i] == '0') {
            if(b != -1) sort(v.begin() + a, v.begin() + b + 1);
            a = i + 1;
            b = -1;
        } else {
            b = i + 1;
        }
    }

    cout << (t == v ? "YES" : "NO") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
