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

void solve() {
    int n;
    cin >> n;
    vector<ll> v(n);
    for (ll &x: v)cin >> x;
    if (v[n - 1] < 0) {
        bool ok = true;
        for(int i=0;i<n-1;i++)if(v[i] > v[i+1])ok = false;
        cout <<(ok ? 0 : -1 ) << endl;
        return;
    }
    if (v[n - 2] > v[n - 1]) {
        cout << -1 << endl;
        return;
    }
    cout << n - 2 << endl;
    for (int i = 0; i < n - 2; i++) {
        cout << i + 1 << " " << n - 1 << " " << n << '\n';
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
