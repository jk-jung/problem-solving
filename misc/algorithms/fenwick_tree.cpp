class FenwickTree {
public:
    vector<int> d;

    void init(int n) {
        d.clear(), d.resize(2 * n + 5);
    }

    void up(int x, int v) {
        for (; x < d.size(); x |= x + 1) d[x] += v;
    }

    int read(int x) {
        int r = 0;
        for (; x >= 0; x = (x & (x + 1)) - 1)
            r += d[x];
        return r;
    }
};