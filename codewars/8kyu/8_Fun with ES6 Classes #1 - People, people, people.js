class Person {
  constructor(a, b, c, d) {
    this.firstName = a || "John";
    this.lastName = b || "Doe";
    this.age = c || 0;
    this.gender = d || "Male";
  }

  sayFullName() {
    return `${this.firstName} ${this.lastName}`;
  }

  static greetExtraTerrestrials(a) {
    return `Welcome to Planet Earth ${a}`;
  }
}
