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

#define M_PI acos(-1.0)

struct Data {
    long double x, y;
    int i;
};

bool angle_from_xaxis(Data &a, Data &b) {
    return atan2(a.y, a.x) < atan2(b.y, b.x);
}

long double angle_of_two_vectors(Data &a, Data &b) {
    return atan2(a.y, a.x) - atan2(b.y, b.x);
}

void solve() {
    int n;
    cin >> n;
    vector<Data> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].x >> v[i].y;
        v[i].i = i + 1;
    }
    sort(v.begin(), v.end(), angle_from_xaxis);
    long double r = 1e18;
    int a = 0, b = 0;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        long double angle = angle_of_two_vectors(v[j], v[i]);
        if (angle < 0) angle += 2 * M_PI;
        if (angle <= r) {
            r = angle;
            a = v[i].i;
            b = v[j].i;
        }
    }
    cout << a << " " << b << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
