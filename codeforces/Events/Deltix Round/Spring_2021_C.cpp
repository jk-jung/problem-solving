#include <string.h>
#include <stdio.h>
#include <math.h>
#include <cassert>
#include <map>
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


string make(vi &st) {
    string r;
    for (int i = 0; i < st.size(); i++) {
        if (i) r += ".";
        r += to_string(st[i]);
    }
    return r;
}

void solve() {
    int n;
    cin >> n;
    vi st, v(n);
    vector<string> r;
    for (int i = 0; i < n; i++)cin >> v[i];

    st.pb(0);

    for (int x: v) {
        if (st.back() + 1 == x) {
            st.pop_back();
        } else if (x == 1) {
        } else {
            while (st.back() + 1 != x)st.pop_back();
            st.pop_back();
        }
        st.pb(x);
        r.pb(make(st));
    }

    for (int i = 0; i < n; i++)cout << r[i] << '\n';
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
