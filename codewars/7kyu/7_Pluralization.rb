def pluralize(w)
  t = %w(s x z ch sh)
  return w + 'es' if w.end_with?(*t)
  return w[0...-1] + 'ies' if w.end_with?('y') and !'aeiou'.include?(w[-2])
  w + 's'
end