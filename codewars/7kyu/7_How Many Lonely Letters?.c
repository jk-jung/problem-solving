unsigned count_lonely_letters(const char *t) {
    unsigned r = 0;
    int a[28] = {0};
    for(int i=0;t[i];i++){
      a[tolower(t[i]) - 'a'] ++;
      
    }
    for(int i=0;i<26;i++){
      if(a[i] != 1)continue;
      if(i && a[i - 1])continue;
      if(a[i + 1])continue;
      r++;
    }
    return r;
  }