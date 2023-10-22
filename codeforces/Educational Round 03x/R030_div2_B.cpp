#include <cstring>
#include <cstdio>
#include <cmath>
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
    string s;
    cin >> n >> s;
    map<int, int> c;
    for (int i = 0, st = 0; i < n; i++) {
        if (s[i] == '1')st++;
        else st--;
        c[st] = i;
    }
    int r = 0;
    for (int i = 0, st = 0; i < n; i++) {
        if (s[i] == '1')st++;
        else st--;
        if (s[i] == '1' && c.count(st - 1)) r = max(r, c[st - 1] - i + 1);
        else if (s[i] == '0' && c.count(st + 1)) r = max(r, c[st + 1] - i + 1);
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
