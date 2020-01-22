int mystrlen(char* a){
  int i = 0;
  while(a[i] != '\0'){
    i++;
  }
  return i;
}

char* mystrcat(char* a, char* b){
  int len1 = mystrlen(a);
  int len2 = mystrlen(b);
  int i;
  for(i = 0; i <= len2; i++){
    a[len1 + i] = b[i];
  }
  return a
}
