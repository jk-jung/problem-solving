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
    cin >> n >> k;
    vector<string> v(n);
    map<string, int> s;
    int cc = 0;
    for (auto &x: v)cin >> x, s[x] = cc++;

    int r = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            string x;
            for (int t = 0; t < k; t++) {
                char a = v[i][t];
                char b = v[j][t];
                if (a > b)swap(a, b);
                if (a == b) x += a;
                else {
                    if (a == 'E' && b == 'T') x += 'S';
                    if (a == 'E' && b == 'S') x += 'T';
                    if (a == 'S' && b == 'T') x += 'E';
                }
            }
            if (s.count(x) && s[x] > j) r++;
        }
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
