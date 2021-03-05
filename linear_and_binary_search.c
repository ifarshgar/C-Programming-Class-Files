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
int main(int argc, char *argv[]) {
    int cnt = 0;

    FILE *stud_file = fopen("student.txt","r");
    if(stud_file == NULL) {
        printf("File not found!\n");
        exit(1);
    }

    char line[100];
    while(fgets(line, 100, stud_file) != NULL){
        if(strcmp(line, "\n") == 0)
            continue;

        char *token = strtok(line, " ");

        strcpy(s[cnt].studentNo, token);
        s[cnt].studentNo[4] = '\0';

        token = strtok(NULL, " ");
        strcpy(s[cnt].name, token);

        token = strtok(NULL, " ");
        s[cnt].grade = atoi(token);

        cnt++;
    }
    fclose(stud_file);

    // print everything
    for(int i=0; i<cnt; i++) {
        printf("%s %s %d\n", s[i].studentNo, s[i].name, s[i].grade);
    }

    int choice = 1;
    while( choice != 3){
       printf("\n1.Find Student by number.");
       printf("\n2.Find Student by name.");
       printf("\n3.Exit.");
       printf("\nEnter your choice from above: ");
       scanf("%d", &choice);

       if(choice == 1){
           char stud_number[5];
           printf("\nEnter student registration number: ");
           scanf("%s", stud_number);
           binary_search(stud_number, cnt);
           printf("\n=========================\n");
       }

       else if(choice == 2){
           char stud_name[10];
           printf("\nEnter student name: ");
           scanf("%s", stud_name);
           linear_search(stud_name, cnt);
           printf("\n==========================\n");
       }

       else if(choice == 3){
           printf("\nGood-bye");
       }
    }

    return 0;
}
*/