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
#include <iomanip>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

#define mp    make_pair
#define pb    push_back
#define F     first
#define S     second
#define ab(x) (((x)<0)?-(x):(x))

typedef pair<int, int> Point;

Point operator-(const Point& a, const Point& b) {
    return make_pair(a.first - b.first, a.second - b.second);
}

double dot(const Point& a, const Point& b) {
    return (double)a.first * b.first + (double)a.second * b.second;
}

double norm_sq(const Point& a) {
    return (double)a.first * a.first + (double)a.second * a.second;
}

double point_to_segment_distance(const Point& a, const Point& b, const Point& c) {
    Point ba = b - a;
    Point ca = c - a;
    Point bc = b - c;

    // Check if the projection of 'a' onto the segment falls within the segment
    if (dot(ba, bc) > 0 && dot(ca, bc) < 0) {
        double area = abs((double)ba.first * ca.second - (double)ba.second * ca.first);
        return area / sqrt(norm_sq(bc));
    }

    // Otherwise, return distance to the closer endpoint
    return min(sqrt(norm_sq(ba)), sqrt(norm_sq(ca)));
}


double distance(pi a, pi b) {
    return sqrt((double) (a.F - b.F) * (a.F - b.F) + (double) (a.S - b.S) * (a.S - b.S));
}


double circle_area(double r) {
    return r * r * acos(-1);
}

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    vector<pi> v(n);
    vector<double> t;
    for (auto &[a, b]: v) {
        cin >> a >> b;
        t.pb(distance({x, y}, {a, b}));
    }

    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        t.pb(point_to_segment_distance({x, y}, v[i], v[j]));
    }
    sort(t.begin(), t.end());

    cout << setprecision(10) << circle_area(t.back()) - circle_area(t[0]) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
