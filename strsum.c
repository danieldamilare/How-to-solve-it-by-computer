#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *strsum(const char *a, const char *b)
{
    //a code that add numbers in string
  if(atoi(a) == 0 && atoi(b) == 0) return strdup("0");
  int len1, len2;
  len1 = strlen(a), len2 = strlen(b);
  int max = len1 > len2 ? len1 : len2;
  int min = len1 < len2 ? len1 : len2;
  char * return_str = (char *) malloc((max+2) * sizeof(char));
  const char * min_string;
  return_str[0] = '0';

  if(max == len1){
    memcpy(return_str+1, a, strlen(a));
    min_string = b;
  }
  else {
      memcpy(return_str+1, b, strlen(b));
      min_string = a;
  }
  
  int carry = 0;
  int j, i;
  for(i = min -1, j = max; i >= 0; i--, j--){
      int sum =  ((return_str[j]-'0') + (min_string[i] - '0') + carry);
     return_str[j] = (sum % 10) + '0';
      carry  = sum/ 10;
  }
  while(carry){
      int sum = (return_str[j]-'0') + carry;
      return_str[j] = (sum % 10) + '0';
      carry = sum /10;
      j--;
  }
  return_str[max+1] = '\0';
  for(i = 0; return_str[i] == '0'; i++)
      ;
  if(i != 0){
      char * ch = strdup(return_str+i);
      free(return_str);
      return_str = ch;
  }
  return return_str;
}

int main(void){
   char *result =  strsum("00000000000000000000000000000", "0000000000000000000000000000");
   printf("the sum of 5134 and 9999999: %s", result);
}
