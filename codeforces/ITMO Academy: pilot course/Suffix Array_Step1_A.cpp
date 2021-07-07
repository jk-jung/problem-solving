#include <string.h>
#include <stdio.h>
#include <math.h>
#include <map>
#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;

#define mp    make_pair
#define pb    push_back
#define F     first
#define S     second
#define ab(x) (((x)<0)?-(x):(x))

class SuffixArray {
public:
    string s;

    SuffixArray(string &t) {
        s = t;
        s += char(0);

        int n = s.size();
        vector<int> ord(n);
        vector<pair<pi, int>> val(n);

        for (int k = 0; k < n * 2; k = k ? k * 2 : 1) {
            for (int i = 0; i < n; i++) {
                if (k == 0) val[i] = {{s[i], 0}, i};
                else val[i] = {{ord[i], ord[(i + k) % n]}, i};
            }
            sort(val.begin(), val.end());
            for (int i = 0, rank = 0; i < n; i++) {
                if (i > 0 && val[i - 1].F < val[i].F) rank++;
                ord[val[i].S] = rank;
            }
        }

        for (int i = 0; i < n; i++)cout << val[i].S << " ";
        cout << endl;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin >> s;
    SuffixArray sa(s);

}
