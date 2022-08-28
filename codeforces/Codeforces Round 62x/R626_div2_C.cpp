#include <cstring>
#include <cstdio>
#include <cmath>
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

void solve() {
    int n;
    string s;
    cin >> n >> s;

    map<int, int> ck;
    vi d(n + 1, -1e9);
    ck[0] = 0;
    d[0] = 0;
    for (int i = 0, st = 0; i < n; i++) {
        if (s[i] == '(') st++;
        else st--;

        if (ck.count(st)) {
            int pos = ck[st];
            if (d[pos] >= 0) {
                bool ok = true;
                for (int j = pos, ss = 0; j <= i; j++) {
                    if (s[j] == '(') ss++;
                    else ss--;
                    if (ss < 0)ok = false;
                }
                int cost = ok ? 0 : i - pos + 1;
                d[i + 1] = d[pos] + cost;
            }
        }
        ck[st] = i + 1;
    }

    cout << (d[n] < 0 ? -1 : d[n]) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
