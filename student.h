#ifndef STUDENT_H
#define STUDENT_H

struct Student
{
    int token;
    char name[50];
    int rollNo;
    char mealType[20];
    float bill;
};

void addStudent(struct Student *s, int token);

void displayStudent(struct Student s);

int searchStudent(struct Student students[], int count, int rollNo);

int deleteStudent(struct Student students[], int *count, int rollNo);

float calculateTotalBill(struct Student students[], int count);

#endif