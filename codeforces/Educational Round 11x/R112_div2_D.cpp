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


string t[] = {
        "abc",
        "acb",
        "bac",
        "bca",
        "cab",
        "cba",
};
int d[200005][6];

void solve() {
    int n, m;
    string v;
    cin >> n >> m >> v;
    for (int i = 1; i <= n; i++) {
        char x = v[i - 1];
        for (int k = 0; k < 6; k++) {
            char y = t[k][(i - 1) % 3];
            d[i][k] = d[i - 1][k] + (x == y ? 0 : 1);
        }
    }

    while (m--) {
        int s, e;
        cin >> s >> e;
        int r = n;
        for (int k = 0; k < 6; k++) {
            r = min(r, d[e][k] - d[s - 1][k]);
        }
        cout << r << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


        solve();
}
