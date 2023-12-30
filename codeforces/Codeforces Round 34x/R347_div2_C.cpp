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
char a[555];

void solve() {
    scanf("%s", a);
    string s = a + 4;
    reverse(s.begin(), s.end());
    string t;
    ll cur = 1988;
    ll base = 10;
    for (char c: s) {
        cur ++;
        t = c + t;
        string cc = to_string(cur);
        ll z = stoll(cc.substr(0, max(0, (int)cc.size() - (int)t.size())) + t);
        while(z < cur) z +=base;
        base *= 10;
        cur = z;
    }
    cout << cur << endl;
}

int main() {
    int n;
    cin >> n;
    while (n--)
        solve();
}
