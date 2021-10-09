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

void solve() {
    ll n, h;
    cin >> n >> h;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)cin >> v[i];
    sort(v.begin(), v.end());

    ll v1 = v[n-1];
    ll v2 = v[n-2];

    ll cnt = h / (v1 + v2);
    ll need = 0;
    ll ss = cnt * (v1 + v2);
    if (ss < h) need++, ss += v1;
    if (ss < h) need++, ss += v2;
    cout << cnt * 2 + need << endl;

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
