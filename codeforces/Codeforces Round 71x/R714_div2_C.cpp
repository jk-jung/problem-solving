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
int mod = 1000000007;

int d[10][10][200005];
int e[10][200005];

void add(int &a, int &b) {
    a += b;
    if (a >= mod)a -= mod;
}

void solve() {
    int n, m;
    int r = 0;
    cin >> n >> m;
    while (n) {
        int a = n % 10;
        add(r, e[a][m]);
        n /= 10;
    }

    cout << r << endl;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i <= 9; i++)d[i][i][0] = 1;
    for (int i = 1; i < 200001; i++) {
        for (int x = 0; x < 10; x++) {
            for (int k = 0; k < 10; k++) {
                if (k == 9) {
                    add(d[x][0][i], d[x][9][i - 1]);
                    add(d[x][1][i], d[x][9][i - 1]);
                } else {
                    add(d[x][k + 1][i], d[x][k][i - 1]);
                }
            }
            for (int k = 0; k < 10; k++)add(e[x][i], d[x][k][i]);
        }
    }

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
