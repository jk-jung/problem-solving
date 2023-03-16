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


vector<string> t = {
        "RGB",
        "RBG",
        "GRB",
        "GBR",
        "BRG",
        "BGR",
};

void solve() {
    int n;
    string s, rr;
    cin >> n >> s;
    int r = 1 << 30;
    for (string x: t) {
        string tmp;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (x[i % 3] != s[i]) cnt++;
            tmp += x[i % 3];
        }
        if (cnt < r) {
            r = cnt;
            rr = tmp;
        }
    }
    cout << r << endl << rr << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
