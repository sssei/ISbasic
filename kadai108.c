int maxof3(int a, int b, int c){
  int tmp = maxof2(a, b);
  int tmp2 = maxof2(tmp, c);
  return tmp2;
}
