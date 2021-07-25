#include <string.h>
#include <stdio.h>
#include <math.h>
#include <map>
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
    int n, m;
    cin >> n >> m;
    vector<int> used(n * 2), L(n), R(n);
    for (int i = 0; i < m; i++) {
        cin >> L[i] >> R[i];
        L[i]--;
        R[i]--;
        used[L[i]] = 1;
        used[R[i]] = 1;
    }
    int rest = 2 * n - 2 * m;

    for (int i = 0; i < 2 * n; i++) {
        if (used[i])continue;
        rest -= 2;
        int need = rest / 2;
        for (int k = i + 1; k < 2 * n; k++) {
            int x = k % (2 * n);
            if (used[x]) continue;
            if (need == 0) {
                used[i] = used[x] = 1;
                L[m] = i;
                R[m] = x;
                m++;
                break;
            }
            need--;
        }
    }

    int r = 0;
    for (int i = 0; i < n; i++) {
        int s1 = min(L[i], R[i]);
        int e1 = max(L[i], R[i]);
        for (int k = 0; k < i; k++) {
            int s2 = min(L[k], R[k]);
            int e2 = max(L[k], R[k]);

            if(s1 < e2 && e2 < e1) swap(s2, e2);
            if(!(s1 < s2 && s2 < e1)) continue;

            if(0 <= e2 && e2 < s1) r ++;
            else if(e1 < e2 && e2 <= 2*n-1) r++;

        }
    }
    cout << r << endl;
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
