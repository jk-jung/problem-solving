#include <string.h>
#include <stdio.h>
#include <math.h>
#include <map>
#include <stack>
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

int mod;
int n;
int d[4000005];
int ss[4000005];

void solve() {
    cin >> n >> mod;
    d[n] = 1;
    ss[n] = 0;
    for (int i = n - 1; i >= 1; i--) {
        ss[i + 1] = (ss[i+2] + d[i+1]) % mod;
        d[i] = ss[i + 1];

        for (int k = 2;; k++) {
            int s = i * k;
            int e = min(n, i * k + k - 1);
            if (s > n)break;

            int y = ((ll)ss[s] - ss[e+1] + mod) % mod;
            d[i] = (d[i] + y) % mod;

        }
    }
    cout << d[1] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

        solve();
}
