// uloha-8-1.cpp -- Tyzden 8 - Uloha 1
// Ondrej Selecky, 14.4.2016 07:01:39

#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <limits.h>

using namespace std;
int *letters;


int anagram(char *s, char *message, int l, int i){  
  int j;
  int diff=0;
  if (i+l>strlen(message)) return INT_MAX;
  letters = (int *) calloc(256,sizeof(int));  
  
  for (j=0;j<l;j++) {
    letters[s[j]]++;
    if (s[j] != message[j+i]) diff++;
  }
  for (j=0;j<l;j++) letters[message[j+i]]--;
  for (j=0;j<128;j++) if(letters[j]) return INT_MAX;
  return diff;  
}

int minimum(int a,int b){
  if (a>b) return b;
  else return a;
}

int main()
{
  int problems,n;
  int i,j,k,f;
  char **words;
  char *message;  
    
  int *best;
  letters = (int *) malloc(26*sizeof(int));
  
  scanf("%d", &problems);
  
  for (f=0;f<problems;f++){
    
    scanf("%d", &n);
    words = (char **) malloc(n*sizeof(char*));
    for (j=0;j<n;j++) {
      words[j] = (char *) malloc(55*sizeof(char));
      scanf("%s", words[j]);
    }
    message = (char *) malloc(55*sizeof(char));
    scanf("%s", message);
    best = (int *) malloc((strlen(message)+1)*sizeof(int));
    for (i=1;i<=strlen(message);i++) best[i]=INT_MAX;
    best[0]=0;
    for (i=1;i<=strlen(message);i++){	
      if (best[i-1]!=INT_MAX){
        for (j=0;j<n;j++){      
          k=anagram(words[j], message, strlen(words[j]), i-1);
         // printf("%d %d %d\n", i+strlen(words[j])-1,best[i+strlen(words[j])-1], k+best[i-1]);
          if(k != INT_MAX) best[i+strlen(words[j])-1] = minimum(best[i+strlen(words[j])-1],k+best[i-1]); 
        }
      }
    }
    k=best[strlen(message)];
    if (k==INT_MAX) printf("neda sa\n");
    else printf("%d\n", k);
    free(best);
    free(message);
    free(words);
  }
    
  
  return 0;
}
