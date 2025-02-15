def count_divisors(a, b)
  r = {}
  b.times.each do |x|
      r[x + 1] = a / (x + 1)
  end
  r
end