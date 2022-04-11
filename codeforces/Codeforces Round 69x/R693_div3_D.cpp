#include <string.h>
#include <stdio.h>
#include <math.h>
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


int pop(vi &v) {
    int x = v.back();
    v.pop_back();
    return x;
}

int move(vi &a, vi &b) {
    if(a.empty() && b.empty()) return 0;
    if(a.empty()) return pop(b) * 0;
    if(b.empty()) return pop(a);
    int aa = a.back();
    int bb = b.back();

    if(aa < bb) return pop(b) * 0;
    return pop(a);
}

void solve() {
    int n;
    cin >> n;
    vi a, b;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        if (x & 1)b.pb(x);
        else a.pb(x);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll sa = 0, sb = 0;

    while(!a.empty() || !b.empty()) {
        sa += move(a, b);
        sb += move(b, a);
    }

    if(sa == sb) {
        cout << "Tie\n";
    }else {
        cout << (sa > sb ? "Alice\n" : "Bob\n");
    }
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
