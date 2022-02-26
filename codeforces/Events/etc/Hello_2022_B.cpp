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

void solve() {
    int n;
    cin >> n;
    vi L(n), R(n), C(n);
    for (int i = 0; i < n; i++)cin >> L[i] >> R[i] >> C[i];

    int s = 0, e = 0, k = 0;
    for (int i = 0; i < n; i++) {
        if (L[i] < L[s] || (L[i] == L[s] && C[i] < C[s])) s = i;
        if (R[i] > R[e] || (R[i] == R[e] && C[i] < C[e])) e = i;

        if(R[i] - L[i] > R[k] - L[k]) k = i;
        else if(R[i] - L[i] == R[k] - L[k] && C[i] < C[k]) k = i;

        int r = C[s] + C[e];
        if(R[e] - L[s] == R[k] - L[k]) r = min(r, C[k]);
        cout << r << '\n';
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
