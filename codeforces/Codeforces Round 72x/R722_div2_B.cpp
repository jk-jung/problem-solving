#include <string.h>
#include <stdio.h>
#include <math.h>
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

void solve() {
    int n, dif = 2100000000;
    cin >> n;
    vi v(n);
    vi r;
    for (int i = 0; i < n; i++)cin >> v[i];
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        if (!i) r.pb(v[i]);
        else if (ab(v[i] - r.back()) >= v[i] && dif >= v[i]) {
            dif = min(dif, ab(v[i] - r.back()));
            r.pb(v[i]);
        }
    }

    cout << r.size() << endl;
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
