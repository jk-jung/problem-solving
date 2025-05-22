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
    int n = s.size();
    int r = 0, cnt = 1;

    vector<pi> st;
    st.pb(mp(0, -1));
    int state = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') state++;
        else state--;

        while (!st.empty() && st.back().F > state) st.pop_back();

        int idx = lower_bound(st.begin(), st.end(), mp(state, -99)) - st.begin();
        if(idx < st.size() && st[idx].F == state) {
            int t = i - st[idx].S;
            if (t > r) {
                r = t;
                cnt = 1;
            } else if (t == r) cnt++;
        }

        if (st.empty() || st.back().F < state)st.pb(mp(state, i));
    }
    cout << r << " " << cnt << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
