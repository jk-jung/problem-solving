class Cube {
public:
  int s;

  Cube(int x = 0) { s = x; }

  void SetSide(int x) { s = x; }

  int GetSide() { return s; }
};