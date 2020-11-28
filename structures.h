#ifndef STRUCTURES_H
#define STRUCTURES_H

typedef struct Person Person;
struct Person {
    int id;
    char *firstName;
    char *lastName;
    char *city;
} P[2];

void save(const char *fileName);
void load(const char *fileName);
void print(const Person p);
void getPerson(const char *fileName, int index);

#endif // STRUCTURES_H
