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
    int n;
    vi v;
    cin >> n;

    int r = 0;
    int zero = 0;
    for (int i = 0; i < n * 2; i++) {
        string x;
        cin >> x;
        int t = 0, c = 0;
        for (char k: x) {
            if (c)t = t * 10 + k - '0';
            if (k == '.') c = 1;
        }
        v.pb(t);
        r += -t;
        if (t == 0)zero++;
    }
    int rst = 1 << 30;
    int cnt = 0;

    if(zero >= n)rst = ab(r);
    for (int i = 0; i < n * 2; i++) {
        if (v[i] == 0)continue;
        r += 1000;
        cnt++;
        if (rst > ab(r) && cnt <= n && cnt + zero >= n)
            rst = ab(r);
    }
    string s = to_string(rst);
    if (s.size() == 1)cout << "0.00" << s << endl;
    else if (s.size() == 2)cout << "0.0" << s << endl;
    else if (s.size() == 3)cout << "0." << s << endl;
    else cout << s.substr(0, s.size() - 3) << "." << s.substr(s.size() - 3, 3) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
