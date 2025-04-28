def hashlife(array)
  r = []
  while array.length > 0
    n = array.shift
    s = array.shift
    r.push('#' * n + s[n...])
  end
  r
end