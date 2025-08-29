const isReallyNaN = (val) => {
  if (typeof val != typeof 1) return false;
  return isNaN(val);
};
