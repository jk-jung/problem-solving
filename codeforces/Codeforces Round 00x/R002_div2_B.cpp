#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define ab(x) (((x) < 0) ? -(x) : (x))

int n;

int a[1005][1005];
int d[1005][1005];

pair<int, string> f(int x) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int t = a[i][j], c = 0;
            while (t && t % x == 0)t /= x, c++;

            if (i == 0 && j == 0) {
                d[i][j] = c;
            } else if (i == 0) {
                d[i][j] = d[i][j - 1] + c;
            } else if (j == 0) {
                d[i][j] = d[i - 1][j] + c;
            } else {
                d[i][j] = min(d[i - 1][j], d[i][j - 1]) + c;
            }
        }
    }
    string r = "";
    int i = n - 1, j = n - 1;
    while (i > 0 || j > 0) {
        if (i == 0) {
            r += 'R';
            j--;
        } else if (j == 0) {
            r += 'D';
            i--;
        } else if (d[i - 1][j] < d[i][j - 1]) {
            r += 'D';
            i--;
        } else {
            r += 'R';
            j--;
        }
    }
    reverse(r.begin(), r.end());
    return mp(d[n - 1][n - 1], r);
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];


    pair<int, string> r = min(f(2), f(5));
    if (r.F != 0) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!a[i][j]) {
                    cout << "1\n";
                    cout << string(i, 'D');
                    cout << string(j, 'R');
                    cout << string(n - i - 1, 'D');
                    cout << string(n - j - 1, 'R') << endl;
                    return;
                }
            }
        }
    }
    cout << r.F << endl << r.S << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
