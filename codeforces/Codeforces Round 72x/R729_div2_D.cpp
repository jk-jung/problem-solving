#include <stdio.h>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

typedef long long ll;

#define mp make_pair
#define pb push_back
#define ab(x) (((x)<0)?-(x):(x))

ll mod = 998244353 ;

ll d[505][505];
int CK;
int ck[505][505];
int n;
ll a[505];

ll go(int small, int pos) {
    if (pos == n) return 1;

    ll &r = d[small][pos];
    if (ck[small][pos] == CK) return r;
    ck[small][pos] = CK;

    r = go(small, pos + 1);
    if (pos == CK);
    else if (pos < CK) {
        if (a[pos] < 0)
            r = (r + go(max(0, small - 1), pos + 1)) % mod;
        else if (a[pos] <= a[CK])
            r = (r + go(small + 1, pos + 1)) % mod;
        else
            r = (r + go(small, pos + 1)) % mod;
    } else {
        if (a[pos] < 0) {
            if (small > 0)
                r = (r + go(small - 1, pos + 1)) % mod;
        } else if (a[pos] < a[CK])
            r = (r + go(small + 1, pos + 1)) % mod;
        else
            r = (r + go(small, pos + 1)) % mod;
    }

    return r;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(ck, -1, sizeof(ck));
    cin >> n;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        if (c == '-')
            a[i] = -1;
        else
            cin >> a[i];
    }

    ll r = 0;
    for (int i = 0; i < n; i++) {
        CK = i;
        if (a[i] > 0) {
            r = (r + go(0, 0) * a[i] % mod) % mod;
        }
    }
    cout << r << endl;
}