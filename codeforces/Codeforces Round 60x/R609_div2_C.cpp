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
    int n, k;
    string s, r;
    cin >> n >> k >> s;
    for (int i = 0; i < n; i++) r += s[i % k];
    bool ok = r >= s;
    if (!ok) {
        r = "";
        for (int i = k - 1; i >= 0; i--) {
            if (s[i] == '9') continue;
            s[i]++;
            for (int j = i + 1; j < k; j++)s[j] = '0';
            break;
        }
        for (int i = 0; i < n; i++) r += s[i % k];
    }
    cout << n << endl;
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
