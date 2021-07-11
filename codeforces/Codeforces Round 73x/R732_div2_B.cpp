#include <string.h>
#include <stdio.h>
#include <math.h>
#include <map>
#include <queue>
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
    int n, m;
    cin >> n >> m;
    vector<string> a(n), b(n - 1);
    vector<int> v(n);
    for (int i = 0; i < n; i++)cin >> a[i];
    for (int i = 0; i < n - 1; i++)cin >> b[i];

    vector<int> aa(26), bb(26);
    for (int i = 0; i < n; i++)v[i] = 0;
    for (int p = 0; p < m; p++) {

        for (int i = 0; i < 26; i++)aa[i] = bb[i] = 0;
        for (int i = 0; i < n; i++) {
            if (i < n - 1) bb[b[i][p] - 'a']++;
            aa[a[i][p] - 'a']++;
        }
        char k = 'a';
        for (int i = 0; i < 26; i++) {
            if (aa[i] != bb[i]) k = 'a' + i;
        }
        for (int i = 0; i < n; i++)if (a[i][p] == k)v[i]++;
    }

    for (int i = 0; i < n; i++)
        if (v[i] == m) {
            cout << a[i] << endl;
            return;
        }


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) solve();
}
