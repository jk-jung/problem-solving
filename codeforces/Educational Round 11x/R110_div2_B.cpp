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


bool sf(int a, int b) {
    if (a % 2 == 0 && b % 2 == 0)return a > b;
    if (a % 2 == 0) return true;
    if (b % 2 == 0) return false;
    return a > b;
}

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

void solve() {
    int n;
    cin >> n;
    vi v(n);
    for (int i = 0; i < n; i++)cin >> v[i];

    sort(v.begin(), v.end(), sf);
    int r = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            r += gcd(v[i], 2 * v[j]) > 1;
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
