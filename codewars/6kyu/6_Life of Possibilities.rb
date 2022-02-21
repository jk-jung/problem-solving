def possibilities(words)
  def comb(v)
    v = v.sort
    r = []
    for i in 1..(v.length) do
      r = r + v.combination(i).to_a
    end
    r.sort
  end

  words.map { |k, v| [k, comb(v)]}.to_h
end
