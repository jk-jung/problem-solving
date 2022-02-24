# This method is called passing in an array of tuples, the employee name
# and manager name.
#
# Calling managers with an employee and manager should respond with
# true if the manager is anywhere in the orginization above the employee
# or false if the manager is not above the employee in the orginization.
managers = (org, employee, manager) ->
  cur = [employee]

  while cur.length > 0
    nxt = []
    for o in org
      [e, m] = o
      if e in cur
        nxt.push(m)
        if m == manager
          return true
    cur = nxt
  return false