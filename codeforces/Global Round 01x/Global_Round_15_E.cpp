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
typedef vector<int> vi;

#define mp    make_pair
#define pb    push_back
#define F     first
#define S     second
#define ab(x) (((x)<0)?-(x):(x))

bool sf(pi &a, pi &b) {
//    return a.S - a.F < b.S - b.F;
    return a.S < b.S;
}

void solve() {
    int n, k;
    cin >> n >> k;
    int N = n * k;
    int m = (n + k - 2) / (k - 1);
    vector<int> v(N), last(n), L(n), R(n), cnt(N);
    for (int i = 0; i < N; i++) cin >> v[i], v[i]--;

    vector<pi> t;
    for (int i = 0; i < n; i++) {
        last[i] = L[i] = R[i] = -1;
    }
    for (int i = 0; i < N; i++) {
        int c = v[i];
        if (last[c] != -1)t.pb({last[c], i});
        last[c] = i;
    }

    sort(t.begin(), t.end(), sf);
    for (int i = 0; i < t.size(); i++) {
        int s = t[i].F;
        int e = t[i].S;
        int c = v[s];
        if (L[c] != -1)continue;

        bool ok = true;
        for (int j = s; j <= e; j++)
            if (cnt[j] + 1 > m) {
                ok = false;
                break;
            }

        if (ok) {
            for (int j = s; j <= e; j++)
                cnt[j]++;
            L[c] = s;
            R[c] = e;
        }
    }

    for (int i = 0; i < n; i++) {
        if (L[i] == -1) exit(1);
        cout << L[i] + 1 << " " << R[i]  + 1<< endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

        solve();
}
