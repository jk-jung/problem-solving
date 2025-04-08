def touchdown?(a)
  pos = 0
  cur = 0
  _try = 4
  while a.length > 0
    x = a.shift
    cur += x
    pos += x
    _try -= 1
    if pos >= 100
      return true
    end

    if cur >= 10
      _try = 4
      cur = 0
    elsif _try == 0
      return false
    end
  end
  return false
end