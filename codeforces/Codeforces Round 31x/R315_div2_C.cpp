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

bool is_prime(int x) {
    for (int i = 2; i * i <= x; i++)if (x % i == 0)return false;
    return true;
}

int number_of_palindrom_less_than_x(int x) {
    if(x == 2530) {
        x=x;
    }
    int r = 0;
    string s = to_string(x);
    for (int i = 0; i < s.size() - 1; i++) {
        if(i <= 1)r += 9;
        else r += 9 * pow(10, i / 2);
    }
    string a = s.substr(0, (s.size() + 1) / 2);
    string b = a;
    if (s.size() % 2)b.pop_back();
    reverse(b.begin(), b.end());
    r += stoi(a) - pow(10, a.size() - 1) + 1;
    if (a + b > s)r--;

    return r;
}

void solve() {
    int a, b;
    cin >> a >> b;

    int p = 0, r = 1;
    for (int i = 2; i <= 1179859; i++) {
        if (is_prime(i)) {
            if (p * b <= number_of_palindrom_less_than_x(i - 1) * a) {
                r = i - 1;
            }
            p++;
        }
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
