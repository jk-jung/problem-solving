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


void solve() {
    vector<string> v;
    string a;
    int m = 0;
    while (getline(cin, a)) v.pb(a), m = max(m, (int) a.size());
    cout << string(m + 2, '*') << endl;
    int flag = 1;
    for (const string &x: v) {
        int need = m - x.size();
        int left, right;
        if (need % 2 == 0) {
            left = need / 2;
            right = need / 2;
        } else {
            left = (need + 1) / 2;
            right = need / 2;
            if (flag % 2)swap(left, right);
            flag++;
        }
        cout << '*';
        cout << string(left, ' ');
        cout << x;
        cout << string(right, ' ');
        cout << "*\n";
    }

    cout << string(m + 2, '*');
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
