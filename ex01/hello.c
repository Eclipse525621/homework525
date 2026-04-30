#include <stdio.h>
#include <string.h>
int main() {
   printf("Hello, World!\n");
   char input[100]; 
   printf("Please input: ");
   fgets(input, sizeof(input), stdin);
   input[strcspn(input, "\n")] = '\0';
   printf("What you input is: %s\n", input);
   
   return 0;
}