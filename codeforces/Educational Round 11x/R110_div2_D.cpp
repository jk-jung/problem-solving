#include <string.h>
#include <stdio.h>
#include <math.h>
#include <map>
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

int k, n;
string s;

int d[1 << 18];

void up(int i, char c) {
    s[i - 1] = c;
    while (i) {
        c = s[i - 1];
        if(i >= n) d[i] = c == '?' ? 2 : 1;
        else d[i] = c == '?' ? d[i * 2] + d[i * 2 + 1] : d[i * 2 + int(c == '0')];
        i /= 2;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> k;
    cin >> s;
    reverse(s.begin(), s.end());
    n = 1 << (k - 1);

    for (int i = n * 2 - 1; i >= 1; i--) {
        char c = s[i - 1];
        if (i >= n) d[i] = c == '?' ? 2 : 1;
        else d[i] = c == '?' ? d[i * 2] + d[i * 2 + 1] : d[i * 2 + int(c == '0')];
    }

    int q;
    cin >> q;
    while (q--) {
        int p;
        char c;
        cin >> p >> c;

        up((int) s.size() + 1 - p, c);
        cout << d[1] << endl;
    }
}
