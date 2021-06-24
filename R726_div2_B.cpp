#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

#define mp    make_pair
#define pb    push_back
#define ab(x) (((x)<0)?-(x):(x))

ll dis(ll a, ll b, ll c) {
    return ab(a - b) + ab(b - c) + ab(c - a);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        int y, x;
        cin >> n >> m >> y >> x;

        ll p[4][2];
        p[0][0] = 1, p[0][1] = 1;
        p[1][0] = 1, p[1][1] = m;
        p[2][0] = n, p[2][1] = 1;
        p[3][0] = n, p[3][1] = m;

        ll r = -1, q = -1;
        for (int k = 0; k < 9; k++) {
            int i = k / 3;
            int j = k % 3;
            ll v = dis(y, p[i][0], p[j][0]) + dis(x, p[i][1], p[j][1]);

            if (v > r) {
                r = v;
                q = k;
            }
        }
        cout << p[q % 3][0] << " " << p[q % 3][1] << " " << p[q / 3][0] << " " << p[q / 3][1] << endl;
    }
}
