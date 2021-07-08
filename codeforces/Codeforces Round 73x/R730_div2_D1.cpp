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


void solve() {
    int n, k;
    cin >> n >> k;

    int q = 0, r;
    for (int i = 0; i < n; i++) {
        if (i == 0) cout << 0 << endl;
        else cout << (i ^ (i-1)) << endl;
        cout.flush();
        cin >> r;
        if (r == 1)break;
    }
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
