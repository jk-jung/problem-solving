def solution(array, key)
  array.sort_by { |x| x[key] }
end