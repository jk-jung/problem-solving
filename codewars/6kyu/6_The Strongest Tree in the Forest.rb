class Node
  attr_accessor :r_node, :l_node

  def initialize(r_node = nil, l_node = nil)
    self.r_node = r_node
    self.l_node = l_node
  end

  def height
    h1 = self.r_node ? self.r_node.height + 1 : 0
    h2 = self.l_node ? self.l_node.height + 1: 0
    [h1, h2].max
  end
end