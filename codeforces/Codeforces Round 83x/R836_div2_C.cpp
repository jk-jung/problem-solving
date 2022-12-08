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

int n, k;

bool go(int x, ll t, set<int> &st) {
    if (t > n) return false;
    for (int i = x; i <= n; i += t) {
        st.insert(i);
        if(i == n || go(i + i, i, st))return true;
        st.erase(i);
    }
    return false;
}

void solve() {
    cin >> n >> k;
    vi v(n);
    queue<int> q;
    set<int> st;
    go(k * 2, k, st);
    if (k == n || st.count(n)) {
        cout << k << " ";
        for (int i = 2; i < n; i++) {
            if (i == k) {
                k = *st.begin();
                cout << k << " ";
                st.erase(k);
            } else cout << i << " ";
        }
        cout << "1\n";
    } else {
        cout << "-1\n";
    }
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
