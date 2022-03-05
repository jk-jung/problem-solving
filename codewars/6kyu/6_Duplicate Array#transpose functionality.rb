def my_transpose(a)
  return nil if a.nil?
  raise ArgumentError if  a.class != [].class
  return [] if a.empty?


  n, m = a.length, a[0].length
  a.each { |x| raise IndexError if x.length != m  }

  m.times.map do |j|
    n.times.map { |i| a[i][j] }
  end
end