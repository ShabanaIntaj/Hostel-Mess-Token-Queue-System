#include <stdio.h>
#include "queue.h"

void initializeQueue(struct Queue *q)
{
    q->front = 0;
    q->rear = -1;
}

int isEmpty(struct Queue *q)
{
    return q->rear < q->front;
}

int isFull(struct Queue *q)
{
    return q->rear == MAX - 1;
}

void enqueue(struct Queue *q, struct Student student)
{
    if (isFull(q))
    {
        printf("\nQueue is full! Cannot add more students.\n");
        return;
    }

    q->rear++;
    q->students[q->rear] = student;

    printf("\nStudent added to the queue successfully!\n");
}

struct Student dequeue(struct Queue *q)
{
    struct Student student;

    if (isEmpty(q))
    {
        printf("\nQueue is empty!\n");
        student.token = -1;
        return student;
    }

    student = q->students[q->front];
    q->front++;

    return student;
}

void displayQueue(struct Queue *q)
{
    if (isEmpty(q))
    {
        printf("\nQueue is empty!\n");
        return;
    }

    printf("\n========== MESS QUEUE ==========\n");

    for (int i = q->front; i <= q->rear; i++)
    {
        printf("\nToken Number : %d", q->students[i].token);
        printf("\nName         : %s", q->students[i].name);
        printf("\nRoll Number  : %d", q->students[i].rollNo);
        printf("\nMeal Type    : %s", q->students[i].mealType);
        printf("\nBill Amount  : Rs. %.2f", q->students[i].bill);
        printf("\n-------------------------------");
    }

    printf("\n");
}

int deleteStudentFromQueue(struct Queue *q, int rollNo)
{
    if (isEmpty(q))
    {
        return 0;
    }

    int index = searchStudentInQueue(q, rollNo);

    if (index == -1)
    {
        return 0;
    }

    for (int i = index; i < q->rear; i++)
    {
        q->students[i] = q->students[i + 1];
    }

    q->rear--;

    return 1;
}

int searchStudentInQueue(struct Queue *q, int rollNo)
{
    if (isEmpty(q))
    {
        return -1;
    }

    for (int i = q->front; i <= q->rear; i++)
    {
        if (q->students[i].rollNo == rollNo)
        {
            return i;
        }
    }

    return -1;
}

float getTotalBill(struct Queue *q)
{
    float total = 0;

    if (isEmpty(q))
    {
        return 0;
    }

    for (int i = q->front; i <= q->rear; i++)
    {
        total += q->students[i].bill;
    }

    return total;
}

int getStudentCount(struct Queue *q)
{
    if (isEmpty(q))
    {
        return 0;
    }

    return q->rear - q->front + 1;
}