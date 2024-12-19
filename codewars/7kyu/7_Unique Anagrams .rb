def anagram(words)
  r = words[0].split("").permutation.map{ |x| x.join('') } - words
  r.length > 0 ? r[0] : ''
end