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

int a[1005][1005];

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            char x;
            cin >> x;
            a[i][j] = x - '0';
        }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            char x;
            cin >> x;
            x -= '0';
            a[i][j] ^= x;
        }

    for (int i = 0; i < n; i++) {
        if (a[i][0])
            for (int j = 0; j < n; j++)a[i][j] ^= 1;
    }
    for (int j = 1; j < n; j++) {
        if (a[0][j])
            for (int i = 0; i < n; i++)a[i][j] ^= 1;
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (a[i][j]) {
                cout << "NO\n";
                return;
            }
    cout << "YES\n";
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
