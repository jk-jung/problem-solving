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

struct Data {
    int a, b, c;
};

bool sf(Data &a, Data &b) {
    if (a.b != b.b) return a.b > b.b;
    return a.a > b.a;
}

bool sf2(Data &a, Data &b) {
    return a.c < b.c;
}

void solve() {
    int n;
    cin >> n;
    vector<Data> v(n);
    for (auto &x: v)cin >> x.a, x.c;

    string s;
    cin >> s;
    for (int i = 0; i < n; i++)v[i].b = s[i] - '0', v[i].c = i;

    sort(v.begin(), v.end(), sf);
    for (int i = 0; i < n; i++)v[i].a = n - i;
    sort(v.begin(), v.end(), sf2);

    for (auto x: v)cout << x.a << " ";
    cout << endl;
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
