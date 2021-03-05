#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct StudentInfo{
   char studentNo[5];
   char name[10];
   int grade;
} s[10];

char * toLower(char *str) {
    int n = strlen(str);
    char *lower = (char *) malloc(n+1 * sizeof(char));

    for(int i=0; i<strlen(str); i++)
        lower[i] = tolower(str[i]);
    lower[n] = '\0';

    return lower;
}

void binary_search(char *target, int size){
   int low = 0;
   int high = size;

   int mid;
   while (low <= high){
       mid = (high + low)/2;
       if(strcmp(s[mid].studentNo,target)==0){
           printf("\nNo.  ---- Name ---- Grades\n");
           printf("%s ---- %s ---- %d",s[mid].studentNo, s[mid].name, s[mid].grade);
           return;
       }
       if(strcmp(s[mid].studentNo,target) > 0){
           high = high - 1;
       }
       else{
           low = mid + 1;
       }
   }
   printf("\nStudent not found!!");
}

void linear_search(char *student_name, int size) {
   int i;

   student_name = toLower(student_name);

   for(i=0;i<=size;i++){
       char *ls = toLower(s[i].name);
       if(strcmp(ls, student_name)==0){
           printf("\nNo.  ---- Name ---- Grades\n");
           printf("%s ---- %s ---- %d",s[i].studentNo, s[i].name, s[i].grade);
           return;
       }
   }
   printf("\n Student not found!!");

}

  /*



    // print everything
    for(int i=0; i<cnt; i++) {
        printf("%s %s %d\n", s[i].studentNo, s[i].name, s[i].grade);
    }
}