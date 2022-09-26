#include <string.h>
#include <stdio.h>
#include <math.h>
#include <cassert>
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


int b[305][305];
int c[305][305];

void solve() {
    int n, m, N;
    cin >> n >> m;
    N = n * m;
    vi a(N);

    map<int, queue<int>> ck;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        ck[a[i]].push(i);
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < N; i++)b[i / m][i % m] = a[i];

    for (int i = 0; i < n; i++) {
        for (int j = m - 1; j >= 0; j--) {
            queue<int> &q = ck[b[i][j]];
            c[i][j] = q.front();
            q.pop();
        }
    }

    int r = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < j; k++) {
                if (c[i][k] < c[i][j]) r++;
            }
        }
    }
    cout << r << '\n';
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
