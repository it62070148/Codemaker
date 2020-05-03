#include "main.h"


int startcharactorcircle(void) {
  //Transcode By Code_cycle
  char code_cycle[27] = {'a', 'b', 'c', 'd', 'e',
                         'f', 'g', 'h', 'i', 'j',
                         'k', 'l', 'm', 'n', 'o',
                         'p', 'q', 'r', 's', 't',
                         'u', 'v', 'w', 'x', 'y',
                         'z'};
  char code[999], transcoded[999];
  int num_rotate;
  char condition;
  condition = input_condition(); 
  num_rotate = input_num_rotate();
  printf("Input Text : ");
  scanf("\n %[^\n]s", code); 
  int len = strlen(code);

  //If decode code cycle will rotate_back by let -(num_rotate)
  if(condition == 'D')
    num_rotate = -num_rotate;
  
  //transcode one by one
  for(int i=0 ; i<len ; i++){    
    if(isalpha(code[i])){
      int index = detect_index(code[i], code_cycle); //find index of character from code_cycle
      char transcoded_char = transcoded_index(index, code_cycle, num_rotate); //character that already transcoded
      if(isupper(code[i]))
        transcoded_char = toupper(transcoded_char);
      transcoded[i] = transcoded_char;
    }else{
        transcoded[i] = code[i];
    }
  }
  
  //Out put
  if(condition == 'D')
    printf("Decoded >>>> ");
  else if(condition == 'E')
    printf("Encoded >>>> ");
  for(int i=0 ; i<len ; i++)
    printf("%c", transcoded[i]);
 
  return 0;
}
 
int detect_index(char code, char cycle[]){
  //return index of character in code_cycle
  code = tolower(code);
  for(int i=0 ; i<26 ; i++){
    if(code == cycle[i])
      return i;
  }
  return 0;
}
 
char transcoded_index(int index, char cycle[], int num_rotate){
  //return decoded index from code_cycle
  index += num_rotate; //rotate left
  index %= 26; //for 0 <= index <= 26
  if(index < 0) 
    index += 26; //rotate back
  return cycle[index];
}

char input_condition(){
  //Input condition D(Decode) or E(Encode) and check Error
  char condition;
  printf("Input 'D' for Decode _or_ 'E' for Encode : ");
  scanf(" %c", &condition);
  condition = toupper(condition);
  if(condition == 'D' || condition == 'E'){
    condition = condition;
  }else{
    printf("ERROR\n");
    condition = input_condition();
  }
  return condition;
}

int input_num_rotate(){
  //Input num for rotate code_cycle and check Error
  char num_rotate[999];
  printf("Input Integer Number for rotation of codecycle : ");
  scanf("%s", num_rotate);
  if(is_num(num_rotate) == 0){
    printf("ERROR : Input Only Interger Number\n");
    sprintf(num_rotate, "%d", input_num_rotate());
  }
  return atoi(num_rotate);
}

int is_num(char num[]){
  //is integer number or not
  if(num[0] == '-' || isdigit(num[0]))
    num[0] = num[0];
  else
    return 0;
  for(int i=1 ; i<strlen(num) ; i++){
    if(!(isdigit(num[i])))
      return 0;
  }
  return 1;
}