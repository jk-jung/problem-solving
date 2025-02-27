def unique r
  t = []
  k = []
  r.map do |x|
    y = x.gsub(/[^a-zA-Z]/i, '').downcase
    if !t.include?(y)
      t.push(y)
      k.push(x)
    end
  end
  k
end