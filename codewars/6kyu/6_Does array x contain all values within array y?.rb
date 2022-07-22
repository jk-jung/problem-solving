class Array
  def contains_all?(y)
    x = self.to_set
    y = y.to_set
    return x & y == y
  end
end