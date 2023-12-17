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
    int n;
    cin >> n;
    int a = 0, b = 0;
    while (n--) {
        int x, y;
        cin >> x >> y;
        if (x > y)a++;
        else if (x < y)b++;
    }
    if (a == b)cout << "Friendship is magic!^^" << endl;
    else if (a > b)cout << "Mishka" << endl;
    else cout << "Chris" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
