#include <stdio.h>
#include "queue.h"
#include "student.h"

int main()
{
    struct Queue q;
    struct Student student;

    int choice;
    int tokenNumber = 1;
    int rollNo;
    int index;

    initializeQueue(&q);

    while (1)
    {
        printf("\n====================================");
        printf("\n       MESS TOKEN QUEUE SYSTEM");
        printf("\n====================================");
        printf("\n1. Add Student / Generate Token");
        printf("\n2. Serve Student");
        printf("\n3. Delete / Cancel Student");
        printf("\n4. Display Queue");
        printf("\n5. Search Student");
        printf("\n6. Calculate Total Bill");
        printf("\n7. Count Students");
        printf("\n8. Exit");
        printf("\n====================================");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:

                if (isFull(&q))
                {
                    printf("\nQueue is full! Cannot add more students.\n");
                    break;
                }

                addStudent(&student, tokenNumber);

                enqueue(&q, student);

                tokenNumber++;

                break;


            case 2:

                student = dequeue(&q);

                if (student.token != -1)
                {
                    printf("\n========== STUDENT SERVED ==========\n");
                    printf("Token Number : %d\n", student.token);
                    printf("Name         : %s\n", student.name);
                    printf("Roll Number  : %d\n", student.rollNo);
                    printf("Meal Type    : %s\n", student.mealType);
                    printf("Bill Amount  : Rs. %.2f\n", student.bill);
                    printf("====================================\n");
                }

                break;


            case 3:

                if (isEmpty(&q))
                {
                    printf("\nQueue is empty! No student to delete.\n");
                    break;
                }

                printf("\nEnter Roll Number to delete: ");
                scanf("%d", &rollNo);

                if (deleteStudentFromQueue(&q, rollNo))
                {
                    printf("\nStudent deleted successfully!\n");
                }
                else
                {
                    printf("\nStudent not found!\n");
                }

                break;


            case 4:

                displayQueue(&q);

                break;


            case 5:

                if (isEmpty(&q))
                {
                    printf("\nQueue is empty!\n");
                    break;
                }

                printf("\nEnter Roll Number to search: ");
                scanf("%d", &rollNo);

                index = searchStudentInQueue(&q, rollNo);

                if (index != -1)
                {
                    printf("\n========== STUDENT FOUND ==========\n");
                    displayStudent(q.students[index]);
                }
                else
                {
                    printf("\nStudent not found!\n");
                }

                break;


            case 6:

                printf("\nTotal Bill of Students in Queue: Rs. %.2f\n",
                       getTotalBill(&q));

                break;


            case 7:

                printf("\nStudents currently in queue: %d\n",
                       getStudentCount(&q));

                break;


            case 8:

                printf("\nThank you for using Mess Token Queue System!\n");
                return 0;


            default:

                printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}