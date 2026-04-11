// return quarter notes per measure
// the result may end up being zero
// for invalid denomiator return -1

int find_quarter_notes(const char *x) {
    int a = 0;
    int b = 0;
    int flag = 0;
    for(int i=0;x[i];i++){
      if(x[i] == '/')flag = 1;
      else if(!flag){
        a = a * 10 + x[i] - '0';
      }else {
        b = b * 10 + x[i] - '0';
      }
    }
    int c = b;
    while(c % 2 == 0 && c > 0) c /= 2;
    if(c != 1)return -1;
    
    return a * 4 / b;
  }