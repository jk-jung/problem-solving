/*
 * Idea
 * - Find differences
 * - Look at the all updates on the same coordinate 𝑥.
 *   The only case we care about is: the current set of open segments contain
 *   exactly one segment and there is at least one adding update.
 */
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
    vector<tuple<int, int, int>> v;
    for (int i = 0, x, y; i < n; i++) {
        cin >> x >> y;
        v.pb(make_tuple(x, -1, i));
        v.pb(make_tuple(y, 1, i));
    }
    sort(v.begin(), v.end());

    int tot = 0, g_size = 0, state = 0;
    vi r(n);
    int rst = 0;
    set<int> st;
    for (int i = 0; i < v.size();) {
        int pos = get<0>(v[i]);
        int st_size = st.size();
        int idx = st.size() == 1 ? *st.begin() : -1;
        int bg_size = g_size;
        int idx2 = -1;
        while (i < v.size() && get<0>(v[i]) == pos) {
            auto [x, z, y] = v[i++];
            idx2 = y;
            state -= z;
            if (z == -1) {
                if (st.empty()) tot++;
                st.insert(y);
                g_size++;
            } else st.erase(y);
        }

        if (st_size == 1 && bg_size >= 2 && g_size > bg_size) {
            r[idx] ++;
        }
        if (st.empty()) {
            if (g_size == 1)r[idx2]--;
            g_size = 0;
        }
    }
    rst = -199999;
    for(int x:r)rst = max(rst, x);
    cout << tot + rst << endl;
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
