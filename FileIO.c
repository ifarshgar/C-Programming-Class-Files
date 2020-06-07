#include <stdio.h>
#include <stdlib.h>

struct Data {
    int id;
    char *text;
} data[2];


int main()
{
    printf("Working with Files in C \n\n");

    // opening a file for writing
    FILE *input = fopen("MyData", "w");
    if(input == NULL) {
        printf("Unable to create the file 'MyData'");
        exit(1);
    }

    // an array of two instances of the Data struct
    data[0].id = 1;
    data[0].text = "first element of the struct";

    data[1].id = 2;
    data[1].text = "second element of the struct";

    // writing the struct data into the file
    for(int i=0; i<2; i++) {
        fprintf(input, "%d %d %s\n", i+1, data[i].id, data[i].text);
    }
    // close the file after writing
    fclose(input);

    printf("Data saved successfully!\n");

    // reopening the file to read the data back
    FILE *output = fopen("MyData", "r");
    if( output == NULL ) {
        printf("File not found!");
        exit(1);
    }

    // reading data from the file
    //struct Data d[2];
    int i = 0;
    int line;
    char * text;
    while( fscanf(output, "%d %d %100[^\n]", &line, &i, text) != EOF) {
        //printf("%d %d %s \n", i+1, d[i].id, d[i].text);

        printf("%d %d %s \n", line, i, text);
    }

    fclose(output);

    printf("The End!");

    printf("\n\n");
    return 0;
}