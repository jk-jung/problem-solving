sc=(s,a)=>a.filter(x=>RegExp(`^${s.replace(/~/g,'.')}`,'i').test(x)).join(',');