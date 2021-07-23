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


int n;
int a[200005];

ll tre[1 << 20];
ll tre2[1 << 20];
ll trec[1 << 20];
int sz = 1 << 19;


void up(ll *t, int i, int v) {
    int s = sz + i;
    while (s) {
        t[s] += v;
        s /= 2;
    }
}

ll read(ll *t, int s, int e) {
    s += sz;
    e += sz;
    ll r = 0;
    while (s <= e) {
        if (s % 2 == 1) r += t[s], s++;
        if (e % 2 == 0) r += t[e], e--;
        s /= 2;
        e /= 2;
    }
    return r;
}

void solve() {
    cin >> n;
    int M = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        M = max(M, a[i]);
    }

    ll r = 0;
    for (int i = 0; i < n; i++) {
        int v = a[i];
        for (int s = 0; s <= M; s += v) {
            int e = min(s + v - 1, M);

            ll ss = read(tre, s, e);
            ll cnt = read(trec, s, e);

            r += ss - cnt * s;
            if (s >= v) r += cnt * v;
        }

        ll ss = read(tre2, 1, v);
        ll cnt = read(trec, 1, v);

        r += cnt * v - ss;

        for (int s = v; s <= M; s += v) up(tre2, s, v);
        up(tre, v, v);
        up(trec, v, 1);

        cout << r << " ";
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}