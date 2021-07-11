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
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(a.begin(), a.end());
    map<int, vector<int>> aa, bb;

    for (int i = 0; i < n; i++) {
        aa[a[i]].pb(i % 2);
        bb[b[i]].pb(i % 2);
    }


    for (auto t: aa) {
        auto na = t.S;
        auto nb = bb[t.F];

        int sa = 0;
        int sb = 0;
        for(int i=0;i<na.size();i++){
            sa += na[i];
            sb += nb[i];
        }

        if(sa != sb) {
            cout <<"NO" <<endl;
            return;
        }
    }
    cout << "YES" <<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) solve();
}
