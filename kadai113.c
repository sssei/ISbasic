char* itoa10(int n, char *buf){
  if(n < 0){
    buf[0] = '-';
    buf++;
    char* tmp = itoa10(-n, buf);
    tmp--;
    return tmp; 
  }
  if(n == 0){
    buf[0] = '0';
    buf[1] = '\0';
    return buf;
  }
  int n2 = n;
  int d = 0;
  int tmp = 1;
  while(n2 > 0){
    n2 = n2 / 10;
    d++;
    tmp *= 10;
  }
  tmp = tmp / 10;
  int i;
  for(i = 0; i < d; i++){
    int t = n / tmp;
    t = t % 10;
    buf[i] = t + '0';
    tmp = tmp / 10;
  }
  buf[i] = '\0';
  return buf;
}
