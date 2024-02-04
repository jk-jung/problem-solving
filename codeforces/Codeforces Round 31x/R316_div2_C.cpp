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
    int n, m;
    string s;
    cin >> n >> m >> s;
    int p = -1;
    s += 'X';
    s = 'X' + s + 'X';
    int r = 0, cnt = 0;;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '.') {
            r++;
            if (p == -1) p = i;
        } else {
            if (p != -1) cnt++;
            p = -1;
        }
    }
    while (m--) {
        int i;
        char x;
        cin >> i >> x;
        if (s[i] == '.' && x != '.') {
            r--;
            if (s[i - 1] == '.' && s[i + 1] == '.')cnt++;
            if (s[i - 1] != '.' && s[i + 1] != '.')cnt--;
        } else if (s[i] != '.' && x == '.') {
            r++;
            if (s[i - 1] == '.' && s[i + 1] == '.')cnt--;
            if (s[i - 1] != '.' && s[i + 1] != '.')cnt++;
        }
        s[i] = x;
        cout << r - cnt << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
