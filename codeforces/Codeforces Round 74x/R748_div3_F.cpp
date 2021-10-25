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

int n, A, B, r_cnt, CK;
string s;
char rr[55], rr2[55];
int d[40][40][40][100];

void go(int idx, int a, int b, int st) {
    if (idx == n) {
        if (a == 0 && b == 0 && ab(st) != n && ab(st) < r_cnt) {
            r_cnt = ab(st);
            for (int i = 0; i < n; i++)rr2[i] = rr[i];
        }
        return;
    }

    int &r = d[idx][a][b][st + 50];
    if (r == CK) return;
    r = CK;

    int x = s[idx] - '0';

    rr[idx] = 'R';
    go(idx + 1, (a * 10 + x) % A, b, st + 1);
    rr[idx] = 'B';
    go(idx + 1, a, (b * 10 + x) % B, st - 1);
}

void solve() {
    cin >> n >> A >> B;
    cin >> s;

    CK++;
    r_cnt = 1 << 10;
    go(0, 0, 0, 0);
    if (r_cnt > 1000) cout << -1 << endl;
    else {
        for (int i = 0; i < n; i++)cout << rr2[i];
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
