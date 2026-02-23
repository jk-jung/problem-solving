class Warrior {
  constructor(n) {
    this.n = n;
  }

  name(x) {
    if (x) {
      this.n = x;
    }
    return this.n;
  }

  toString() {
    return "Hi! my name's " + this.name();
  }
}
