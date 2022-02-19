class Person
  constructor: (@name) ->
  greet: (h)-> "Hello #{h}, my name is #{@name}"


class RudePerson extends Person
  constructor: (@name) ->
  greet: (h)-> "I'm #{@name}, now go away #{h}"