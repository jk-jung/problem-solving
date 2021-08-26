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
    int n;
    cin >> n;
    vector<pi> v(n);

    for (int i = 0; i < n; i++) {
        int k, m = 0, t;
        cin >> k;
        for (int j = 0; j < k; j++) {
            cin >> t;
            m = max(m, t - j);
        }
        v[i] = {m, k};
    }
    sort(v.begin(), v.end());
    int r = v[0].F + 1, up = 0;

    for(int i=0;i<n;i++){
        if (r + up <= v[i].F) {
            r = v[i].F - up + 1;
        }
        up += v[i].S;
    }

    cout << r << endl;
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
