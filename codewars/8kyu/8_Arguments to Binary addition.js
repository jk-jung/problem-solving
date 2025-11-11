function arr2bin(a) {
  let r = 0;
  for (let x of a) {
    if (Number.isNaN(x)) return "NaN";
    if (Number.isInteger(x)) {
      r += x;
    }
  }

  flag = false;
  if (r < 0) {
    r = -r;
    flag = true;
  }
  s = "";
  while (r > 0) {
    s = (r % 2).toString() + s;
    r = Math.floor(r / 2);
  }
  if (s && flag) s = "-" + s;
  return s || "0";
}
