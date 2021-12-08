#ifndef GRADES_OPERATIONS_H
#define GRADES_OPERATIONS_H
#include "StudentList.h"

int studentCounter(StudentList* list , FILE* fr , int numOfStu);
void studentCounterByApproached(StudentList* list , FILE* fr);
void studentWhoDidntTest(StudentList* list , FILE* fr);
void numOfFailures(StudentList* list , FILE* fr , int numOfStudents);
void avrageGrades(StudentList* list , FILE* fr);
void simplyTheBest(StudentList* list , FILE* fr);
void simplyNotTheBest(StudentList* list , FILE* fr);

#endif