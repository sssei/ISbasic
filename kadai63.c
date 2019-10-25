#include <stdio.h>
#include <string.h>
#define SIZE 30

typedef struct list{
  int flag;
  char word[20];
  char tango[20];
} Node;

Node null;
Node dummy;

void init(){
  null.flag = -1;
  dummy.flag = 1;
}

int HashFunction(char* word){
  int i;
  int res = 0;
  for(i = 0; i < strlen(word); i++){
    res += word[i];
  }
  return res % SIZE;
}

void InsertHash(Node table[], char w[], char t[]){
  int hashValue = HashFunction(w);
  int cnt = 0;
  while(table[hashValue].flag == 0){
    if(strcmp(table[hashValue].word, w) == 0){
      break;
    }
    hashValue = (hashValue + 1) % SIZE;
    cnt++;
    if(cnt > SIZE){
      printf("OVERFLOW\n");
      return;
    }
  }
  Node tmp;
  strcpy(tmp.word, w);
  strcpy(tmp.tango, t);
  tmp.flag = 0;
  table[hashValue] = tmp;
}

void DeleteHash(Node table[], char w[]){
  int hashValue = HashFunction(w);
  int cnt = 0;
  while(1){
    if(table[hashValue].flag == -1){
      return;
    }else if(table[hashValue].flag == 1){
      hashValue = (hashValue + 1) % SIZE;
      cnt++;
    }else if(strcmp(table[hashValue].word, w) != 0){
      hashValue = (hashValue + 1) % SIZE;
      cnt++;
    }else{
      break;
    }
    if(cnt > SIZE){
      return;
    }
  }
  table[hashValue] = dummy;
}

int SearchHash(Node table[], char w[]){
  int hashValue = HashFunction(w);
  int cnt = 0;
  int res = -1;
  while(1){
    if(table[hashValue].flag == -1) break;
    if(table[hashValue].flag == 1){
      hashValue = (hashValue + 1) % SIZE;
      cnt++;
    }else if(strcmp(table[hashValue].word, w) != 0){
      hashValue = (hashValue + 1) % SIZE;
      cnt++;
    }else{
      res = hashValue;
      break;
    }
    if(cnt > SIZE){
      break;
    }
  }
  return res;
}

void Print(Node table[]){
  int i;
  for(i = 0; i < SIZE; i++){
    if(table[i].flag == -1){
      printf("null\n");
    }else if(table[i].flag == 1){
      printf("dummy\n");
    }else{
      printf("%s %s\n", table[i].word, table[i].tango); 
    }
  }
}

int main(){
  init();
  Node HashTable[SIZE];
  int i;
  for(i = 0; i < SIZE; i++){
    HashTable[i] = null;
  }
  char order[10];
  char Word[100];
  char Tango[100];
  scanf("%s", order);
  while(order[0] != 'q'){
    if(order[0] == 'i'){
      scanf("%s%s", Word, Tango);
      InsertHash(HashTable, Word, Tango);
    }else if(order[0] == 's'){
      scanf("%s", Word);
      int n = SearchHash(HashTable, Word);
      if(n == -1){
	printf("(not found)\n");
      }else{
	printf("%s\n", HashTable[n].tango);
      }
    }else{
      scanf("%s", Word);
      DeleteHash(HashTable, Word);
    }
    scanf("%s", order);
  }
  /* Print(HashTable); */
}
