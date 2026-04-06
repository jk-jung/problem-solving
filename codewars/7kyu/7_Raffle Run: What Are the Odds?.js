const gcd = (a, b) => (b === 0 ? a : gcd(b, a % b));

function raffleOdds(a, b) {
  let A = 1,
    B = 1;
  for (let i = 0; i < a.length; i++) {
    A *= a[i];
    B *= a[i] - b[i];
  }
  let G = gcd(A, B);

  return `${(A - B) / G}/${A / G}`;
}
