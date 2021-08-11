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


#define mod 998244353

int d[1000005];
int s[1000005];
int ck[1000005];
vi p;

void solve() {
    int n;
    cin >> n;

    d[1] = 1;
    s[1] = 1;

    int nn = sqrt(n) + 0.1;
    for (int i = 2; i <= nn; i++) {
        if (ck[i])continue;
        p.pb(i);
        for (int k = i + i; k <= nn; k += i)ck[k] = 1;
    }
    for (int i = 2; i <= n; i++) {
        int c = 1, m = sqrt(i) + 0.1;
        int x = i;
        for (int j = 0; j < p.size() && p[j] <= m; j++) {
            int c2 = 1;
            while (x % p[j] == 0) {
                c2++;
                x /= p[j];
            }
            c *= c2;
        }
        if (x != 1) c *= 2;
        d[i] = (s[i - 1] + c) % mod;
        s[i] = (s[i - 1] + d[i]) % mod;
    }

    cout << d[n] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
