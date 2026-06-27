def power(a, b)
    r = 1.0
    if b < 0
      (-b).times { |x| r /= a }
    else
      b.times { |x| r *= a }
    end
    r
  end