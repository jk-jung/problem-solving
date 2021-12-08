class Mother
  @sub_classes = []

  def self.inherited(sub_class)
    @sub_classes << sub_class
  end

  def self.phone_kids
    @sub_classes.each { |x| x.phone }
  end
end