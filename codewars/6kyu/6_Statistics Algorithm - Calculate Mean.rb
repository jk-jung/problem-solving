def calc_mean(ary)
  if !ary.is_a?(Array)
    0
  elsif ary.empty?
    0
  else
    ary.sum / ary.length
  end
end