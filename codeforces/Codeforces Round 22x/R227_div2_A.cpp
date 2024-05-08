#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define ab(x) (((x) < 0) ? -(x) : (x))

vi read_time() {
    string s;
    cin >> s;
    int h = stoi(s.substr(0, 2));
    int m = stoi(s.substr(3, 2));
    return {h, m};
}

void solve() {
    vi a = read_time();
    vi b = read_time();
    int h = a[0] - b[0];
    int m = a[1] - b[1];
    if (m < 0) {
        m += 60;
        h--;
    }
    if (h < 0) {
        h += 24;
    }
    printf("%02d:%02d\n", h, m);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
