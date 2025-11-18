def describe_age(x):
 if x<18:s="kid" if x<13 else"teenager"
 else:s="adult"if x<65else"elderly"
 return"You're a(n) "+s
