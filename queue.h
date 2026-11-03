#ifndef QUEUE_H
#define QUEUE_H

#include "student.h"

#define MAX 100

struct Queue
{
    struct Student students[MAX];
    int front;
    int rear;
};

void initializeQueue(struct Queue *q);

int isEmpty(struct Queue *q);

int isFull(struct Queue *q);

void enqueue(struct Queue *q, struct Student student);

struct Student dequeue(struct Queue *q);

void displayQueue(struct Queue *q);

int deleteStudentFromQueue(struct Queue *q, int rollNo);

int searchStudentInQueue(struct Queue *q, int rollNo);

float getTotalBill(struct Queue *q);

int getStudentCount(struct Queue *q);

#endif