int mystrcmp(char* a, char* b){
  int i = 0;
  while(1){
    int buff = a[i] - b[i];
    if(a[i] == '\0'){
      return buff;
    }
    if(buff != 0){
      return buff;
    }
    i++;
  }
}
