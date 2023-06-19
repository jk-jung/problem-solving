a=10
lcd=lambda n,s=2,t=0:lcd(n//a,3-s,t+n%a*s+(n%a*s>9))if n else -t%a
