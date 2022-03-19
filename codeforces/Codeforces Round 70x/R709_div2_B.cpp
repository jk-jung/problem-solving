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
    vi v(n);
    for (int &x: v)cin >> x;

    map<int, int> dif;
    for (int i = 1; i < n; i++) {
        dif[v[i] - v[i - 1]]++;
    }
    if (dif.size() > 2) {
        cout << -1 << endl;
        return;
    }
    if (dif.size() < 2) {
        cout << 0 << endl;
        return;
    }

    int a = dif.begin()->F;
    int b = dif.rbegin()->F;

    ll m = b - a;
    ll c = b;

    ll s = v[0] % m;
    for(int i=0;i<n;i++){
        if(s != v[i]) {
            cout << -1 << endl;
            return;
        }

        s = (s + c) % m;
    }
    cout << m <<" " << c << endl;
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
