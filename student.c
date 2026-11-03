#include <stdio.h>
#include <string.h>

struct Student
{
    int token;
    char name[50];
    int rollNo;
    char mealType[20];
    float bill;
};

void addStudent(struct Student *s, int token)
{
    s->token = token;

    printf("\nEnter Student Name: ");
    scanf(" %[^\n]", s->name);

    printf("Enter Roll Number: ");
    scanf("%d", &s->rollNo);

    printf("Enter Meal Type: ");
    scanf(" %[^\n]", s->mealType);

    printf("Enter Bill Amount: Rs. ");
    scanf("%f", &s->bill);

    printf("\nStudent added successfully!\n");
    printf("Token Number: %d\n", s->token);
}

void displayStudent(struct Student s)
{
    printf("\n--------------------------------");
    printf("\nToken Number : %d", s.token);
    printf("\nName         : %s", s.name);
    printf("\nRoll Number  : %d", s.rollNo);
    printf("\nMeal Type    : %s", s.mealType);
    printf("\nBill Amount  : Rs. %.2f", s.bill);
    printf("\n--------------------------------\n");
}

int searchStudent(struct Student students[], int count, int rollNo)
{
    for (int i = 0; i < count; i++)
    {
        if (students[i].rollNo == rollNo)
        {
            return i;
        }
    }

    return -1;
}

int deleteStudent(struct Student students[], int *count, int rollNo)
{
    int index = searchStudent(students, *count, rollNo);

    if (index == -1)
    {
        return 0;
    }

    for (int i = index; i < *count - 1; i++)
    {
        students[i] = students[i + 1];
    }

    (*count)--;

    return 1;
}

float calculateTotalBill(struct Student students[], int count)
{
    float total = 0;

    for (int i = 0; i < count; i++)
    {
        total += students[i].bill;
    }

    return total;
}