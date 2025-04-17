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
    double a, b, c;
    cin >> a >> b >> c;
    if (a == 0 && b == 0)cout << (c == 0 ? -1 : 0);
    else if (a == 0)printf("%d\n%.10lf", 1, -c / b);
    else {
        double d = b * b - 4 * a * c;
        if (d < 0)cout << 0;
        else if (d == 0)printf("%d\n%.10lf", 1, -b / (2 * a));
        else {
            double x = (-b - sqrt(d)) / (2 * a);
            double y = (-b + sqrt(d)) / (2 * a);
            if (x > y)swap(x, y);
            cout << 2 << endl;
            printf("%.10lf\n%.10lf", x, y);
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
