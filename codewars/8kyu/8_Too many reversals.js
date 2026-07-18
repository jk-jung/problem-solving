function whowon(s) {
    a = s.split(" hit a reversal to ")
    return a[a.length - 2]
  }