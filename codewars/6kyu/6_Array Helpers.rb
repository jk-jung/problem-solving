class Array
  def square
    map {|x| x ** 2}
  end

  def cube
    map { |x| x ** 3}
  end

  def sum
    r = 0
    map {|x| r += x}
    r
  end

  def average
    sum / length
  end

  def even
    select { |x| x % 2 == 0}
  end

  def odd
    select { |x| x % 2 == 1}
  end
end