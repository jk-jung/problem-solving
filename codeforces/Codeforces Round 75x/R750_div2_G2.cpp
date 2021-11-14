#include <string.h>
#include <stdio.h>
#include <math.h>
#include <cassert>
#include <set>
#include <map>
#include <array>
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

int n;
int a[1000005];
int d[1000005];
map<int, int> *pr[1000005], org[1000005];
string s;

int p[1000005];

bool can(map<int, int>& a, map<int, int>& b) {
    for (auto[k, v]: b)
        if (!a.count(k) || a[k] + v < 0) return false;
    return true;
}

void solve() {
    for (int i = 2; i <= 1000000; i++) {
        if (p[i])continue;
        for (int j = i + i; j <= 1000000; j += i) p[j] = i;
    }

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> s;
    for (int i = 0; i < n; i++)if (a[i] == 1)s[i] = '*';
    for (int i = 0; i < n; i++) {
        int op = s[i] == '*' ? +1 : -1;
        int x = a[i];

        while(p[x]) org[i][p[x]] += op, x /= p[x];
        if (x > 1) org[i][x] += op;
        pr[i] = &org[i];
    }

    ll r = 0;
    for (int i = n - 1, j; i >= 0; i--) {
        if (s[i] != '*') continue;
        map<int, int> *ck = pr[i];

        for (j = i + 1; j < n; j++) {
            if (s[j] == '*') {
                for (auto[k, v]: *ck) (*pr[j])[k] += v;
                ck = pr[j];
                j = d[j];
            }
            if (j == n)break;

            if(!can(*ck, *pr[j])) break;
            for (auto[k, v]: *pr[j]) (*ck)[k] += v;
        }
        d[i] = j;
        pr[i] = ck;
        r += (j - i);
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}