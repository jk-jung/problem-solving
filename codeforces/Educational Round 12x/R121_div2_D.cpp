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
    vi s(n + 1);
    for (int i = 0, x; i < n; i++) cin >> x, s[x]++;
    for (int i = 1; i <= n; i++)s[i] += s[i - 1];

    int r = 1 << 30;
    for (int k1 = 0; k1 < 20; k1++) {
        for (int k2 = 0; k2 < 20; k2++) {
            int s1 = 1 << k1;
            int s2 = 1 << k2;

            int idx = lower_bound(s.begin(), s.end(), s1) - s.begin();
            while (s[idx] > s1) idx--;

            int idx2 = lower_bound(s.begin() + idx, s.end(), s2 + s[idx]) - s.begin();
            while (s[idx2] > s2 + s[idx]) idx2--;

            int remain = s[n] - s[idx2], s3;
            for (s3 = 1; s3 < remain; s3 *= 2);
            int t = (s1 - s[idx]) + (s2 - s[idx2] + s[idx]) + (s3 - remain);
            r = min(r, t);
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