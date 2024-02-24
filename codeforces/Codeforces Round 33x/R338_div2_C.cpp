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
    string a0, a1, b;
    cin >> a0 >> b;
    a1 = a0;
    reverse(a1.begin(), a1.end());
    int n = a0.size();
    int m = b.size();
    vector<pi> t;
    for (int i = 0; i < m;) {
        string x;
        while (i < m && a0.find(x) != string::npos || a1.find(x) != string::npos) {
            x += b[i++];
        }
        int i0 = a0.find(x);
        int i1 = a1.find(x);
        if (!x.empty() && i0 == string::npos && i1 == string::npos) {
            x.pop_back();
            i--;
        }
        i0 = a0.find(x);
        i1 = a1.find(x);
        if (x.size() == 0) {
            cout << -1 << endl;
            return;
        }

        if (i0 != string::npos) {
            t.pb({i0, i0 + x.size() - 1});
        } else {
            t.pb({n - i1 - 1, n - i1 - x.size()});
        }
    }
    cout << t.size() << endl;
    for (auto &p: t) {
        cout << p.F + 1 << " " << p.S + 1 << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
