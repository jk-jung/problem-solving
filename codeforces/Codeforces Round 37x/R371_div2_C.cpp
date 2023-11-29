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


map<string, int> cnt;

void insert(string x, int k) {
    reverse(x.begin(), x.end());
    string t;
    for (int i = 0; i < 18; i++) {
        char y = (x[i] - '0') % 2 ? '1' : '0';
        t = (i < x.size() ? y : '0') + t;
    }
    cnt[t] += k;
}


void solve() {
    int n;
    cin >> n;
    while (n--) {
        string a, x;
        cin >> a >> x;
        if (a == "+") {
            insert(x, +1);
        } else if (a == "-") {
            insert(x, -1);
        } else {
            while(x.size() < 18) x = '0' + x;
            cout << cnt[x] << endl;
        }

    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
