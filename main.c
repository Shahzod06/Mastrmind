#include<stdio.h>  
#include<stdlib.h>  
#include<time.h>  
#include <string.h>  
#include <stdbool.h>  

bool is_inside(char* text, char sign){
    if(text == 0)return true;
    for( int i = 0; i < strlen(text); i++){
        if(text[i] == sign)
        return false;
    }
    return true;
}
char* kodniol(){
    char *kod = malloc(4);
    int index =0;
    while(strlen(kod) < 4){
       srand(time(0));
       char n = rand() % 8 +'0';
       if(is_inside(kod,n))
          kod[index++] =n;

    }
    return kod;
}
int Well_placed(char *text1, char *text2){
     int well = 0;
     for(int k=0; k <strlen(text1); k++){
         if(text1[k]==text2[k])
         well++;
     }
     return well; 
}

bool is_repeat(char *str){
   for(int i =0; i< strlen(str) - 1 ; i++){
     for(int j = i+1; j< strlen(str); j++){
         if(str[i]== str[j])
         return true;
     }
   }
   return false;
}

int miss_placed(char *text1, char *text2){
      int miss =0;
      for(int j=0; text1[j] != '\0' ; j++){
          if(!is_inside(text1,text2[j]) &&  text1[j] != text2[j])
          miss++;
}
return miss;
} 

bool wrong_input(char *text){
    if(strlen(text) !=4)  return true;
    int i = 0;
    while(i < strlen(text)){
        if(text[i] > '7' && text[i] < '0' || is_repeat(text))
        return true;
        i++;
    }
    return false;
}

int main () {
     
     char *secret = malloc(4);
     char *input = malloc(16);
     int roundlar_soni = 10;
     int round = 0;
     secret = kodniol();
     printf("Will you find the secret code?\n");
     printf("%s -\n",secret);
     while(round < roundlar_soni){
         printf("- - -\n Round %d \n >", round); 
         scanf("%s", input);
         if(wrong_input(input)){
             printf("wrong input !\n");
             continue;
         }

         int wp = Well_placed(secret, input);
         int mp = miss_placed(secret, input);
         if(wp == 4){
             printf("Congratz! You did it!\n ");
             break;
         }
         else {
             printf("Well placed pieces: %d\n", wp);
              printf("Misplaced pieces: %d\n", mp);
         }
         round++;
     }

     return 0;


}
