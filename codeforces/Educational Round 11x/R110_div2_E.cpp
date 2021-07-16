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


int a[300005];
int c[300005];

int d[300005][20];

void build(int x) {
    for (int i = 1; i < 20; i++)d[x][i] = -1;
    int k = d[x][0];
    for (int i = 1; i < 20; i++) {
        if (d[k][i - 1] == -1) break;
        k = d[x][i] = d[k][i - 1];
    }
}


void read(int s, int w) {
    ll r = 0, t = 0;
    while (w) {
        int x = s;
        for (int i = 19; i >= 0; i--) {
            if (d[x][i] != -1 && a[d[x][i]] > 0) x = d[x][i];
        }
        int m = min(w, a[x]);
        a[x] -= m;
        w -= m;
        r += (ll)m * c[x];
        t += m;
        if (x == s)break;
    }
    cout << t << " " << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int q;
    cin >> q >> a[0] >> c[0];
    d[0][0] = -1;
    build(0);
    for (int i = 1; i <= q; i++) {
        int op;
        cin >> op;
        if (op == 1) {
            cin >> d[i][0] >> a[i] >> c[i];
            build(i);
        } else {
            int s, w;
            cin >> s >> w;
            read(s, w);
        }
    }
}
