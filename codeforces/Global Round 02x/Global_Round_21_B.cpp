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
    deque<int> q;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        q.pb(x);
    }
    while (!q.empty() && q.front() == 0)q.pop_front();
    while (!q.empty() && q.back() == 0)q.pop_back();

    map<int, int> ck;
    for (int x: q) ck[x]++;
    if (q.empty()) {
        cout << 0 << endl;
    } else if (ck[0] > 0) {
        cout << 2 << endl;
    } else {
        cout << 1 << endl;
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
