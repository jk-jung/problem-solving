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
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)cin >> v[i];

    vector<int> r(n);

    r[0] = 0;
    int x = v[0] ^ r[0];
    for (int i = 1; i < n; i++) {
        for (int k = 0; k < 31; k++) {
            int a = x >> k & 1;
            int b = v[i] >> k & 1;
            if (a == 1 && b == 0) r[i] |= (1 << k);
        }

        x = v[i] ^ r[i];
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
