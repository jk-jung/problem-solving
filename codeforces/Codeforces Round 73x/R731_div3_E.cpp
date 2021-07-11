#include <string.h>
#include <stdio.h>
#include <math.h>
#include <map>
#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;

#define mp    make_pair
#define pb    push_back
#define F     first
#define S     second
#define ab(x) (((x)<0)?-(x):(x))


int a[300005];
int t[300005];

void solve() {
    int n, k;

    cin >> n >> k;
    vector<pi> down, up;
    vector<int> r(n);
    for (int i = 0; i < k; i++) cin >> a[i];
    for (int i = 0; i < k; i++) cin >> t[i];
    for (int i = 0; i < k; i++) {
        a[i]--;
        down.pb({t[i] + a[i], a[i]});
        up.pb({t[i] + (n - a[i] - 1), a[i]});

    }
    for(int i=0;i<n;i++)r[i] = 2000000000;
    sort(down.begin(), down.end());
    sort(up.begin(), up.end());
    for (int i = 0, p = 0; i < n; i++) {
        while (p < down.size() && down[p].S < i)p++;
        if (p<down.size())
            r[i] = down[p].F - i;
    }


    for (int i = n - 1, p = 0; i >= 0; i--) {
        while (p < up.size() && up[p].S > i)p++;
        if (p<up.size())
            r[i] = min(r[i], up[p].F - (n - 1 - i));
    }
    for (int i = 0; i < n; i++)cout << r[i] << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
