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

int n;
string s;
int d[1505][1505];
int t[1505][30];

int go(int i, int c, int a) {
    if (i == n)return 0;
    int &r = d[i][c];
    if (r != -1)return r;

    r = 0;
    if (s[i] - 'a' == a) r = go(i + 1, c, a) + 1;
    else if (c) r = max(r, go(i + 1, c - 1, a) + 1);
    return r;
}

void solve() {

    cin >> n >> s;

    for (int a = 0; a < 26; a++) {
        memset(d, -1, sizeof(d));
        for (int i = 0; i < n; i++) {
            for (int c = 0; c <= n; c++) {

                t[c][a] = max(t[c][a], go(i, c, a));

            }
        }
    }


    int q;
    cin >> q;
    while (q--) {
        int i;
        char c;
        cin >> i >> c;
        cout << t[i][c - 'a'] << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
