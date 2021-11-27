class BatchItemProcessor
  def initialize
    @id = nil
    @processed = []
    @should = nil
  end

  def reset
    @processed = []
  end

  def process_items(items)
    items.each do |item|
      next if !@should.nil? && !@should.call(item)
      next if @processed.select { |x| is_same(item, x) }.count > 0

      @processed.push(item)

      yield item
    end
  end

  def identify(x)
    @id = x
  end

  def should_process(&x)
    @should = x
  end

  def is_same(a, b)
    get_key(a) == get_key(b)
  end

  def get_key(a)
    @id.nil? ? a : a[@id]
  rescue
    a.send(@id)
  end

  def processed_items
    @processed
  end
end