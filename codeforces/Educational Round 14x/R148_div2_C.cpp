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
    vi v(n), st;
    for (int &x: v)cin >> x;

    for (int x: v) {
        if(st.size() >= 1 && st.back() == x)continue;
        if (st.size() >= 2) {
            if (st[st.size() - 2] <= st.back() && st.back() <= x) {
                st.pop_back();
            } else if (st[st.size() - 2] >= st.back() && st.back() >= x) {
                st.pop_back();
            }
        }
        st.pb(x);
    }
    cout << st.size() << endl;
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
