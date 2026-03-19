def center(m)
  if m.length % 2 == 1
    m = m[m.length / 2]
    if m.length % 2 == 1
      m[m.length / 2]
    end
  end
end