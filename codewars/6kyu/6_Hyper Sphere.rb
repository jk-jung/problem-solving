def in_sphere?(v, r)
  v.map { |x| x * x}.sum <= r * r
end