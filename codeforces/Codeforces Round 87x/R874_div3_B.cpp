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

struct Data {
    int a, b, c;
};

bool sf(Data &a, Data &b) { return a.a < b.a; }

bool sf2(Data &a, Data &b) { return a.c < b.c; }


void solve() {
    int n, k;
    cin >> n >> k;
    vector<Data> v(n), t(n);
    for (int i = 0; i < n; i++)cin >> v[i].a, v[i].c = i;
    for (int i = 0; i < n; i++)cin >> t[i].a;
    sort(v.begin(), v.end(), sf);
    sort(t.begin(), t.end(), sf);
    for (int i = 0; i < n; i++)v[i].b = t[i].a;
    sort(v.begin(), v.end(), sf2);
    for (int i = 0; i < n; i++)cout << v[i].b << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
