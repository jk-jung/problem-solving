def power(x, y)
  return nil if y < 0
  r = 1
  y.times { r *= x }
  r
end