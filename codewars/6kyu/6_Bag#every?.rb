class Bag
  def every?(*args, &block)
    ok = true
    if block
      each { |x| ok = ok && block.call(x)}
    else
      each { |x| ok = ok && !!x}
    end
    ok
  end
end