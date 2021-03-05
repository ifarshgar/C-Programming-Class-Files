#ifndef C_PROGRAMMING_PERSON_H
#define C_PROGRAMMING_PERSON_H

typedef struct Person Person;
struct Person {
    int id;
    char *firstName;
    char *lastName;
    char *city;
} *person;

void savePerson(const char *fileName, Person *p, int size);
Person * loadPerson(const char *fileName, int size);
void printPerson(Person *p);
Person * getPerson(const char *fileName, int index);

#endif // C_PROGRAMMING_PERSON_H
