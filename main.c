#include <stdio.h>
#include <stdlib.h>
#define Size 30
#include "StudentList.h"
#include "GradesOperations.h"
int main()
{   
    int numberOfStudents = 0;
    char myPath[] = "StudentsGrades.txt";
    char reportPath[] = "Report.txt";
    int c;
    FILE* fp = fopen(myPath, "r");
    if(fp == NULL){
    printf("cannot open file\n");
    }
    StudentList* list = createList();
    while(1){
        c = fgetc(fp);
        
        if(c == EOF){
            break;
        }
    Student* studentInfo = (Student*)malloc(sizeof(Student));
    fscanf(fp ,"%d" , &(studentInfo->id));
    fscanf(fp , "%d" , &(studentInfo->grade1));
    fscanf(fp , "%d" , &(studentInfo->grade2));
    addToList(list, studentInfo);
    }
    FILE* fr = fopen(reportPath, "w");
    if(fr == NULL){
    printf("cannot open report\n");
    exit(1);
    }
    printf("Great Succsess\n");
    // printStudentList(list);
    numberOfStudents = studentCounter(list , fr , numberOfStudents);
    studentCounterByApproached(list, fr);
    studentWhoDidntTest(list , fr);
    numOfFailures(list , fr , numberOfStudents);
    avrageGrades(list , fr);
    simplyTheBest(list , fr);
    simplyNotTheBest(list , fr);
    fclose(fr);
    printStudentList(list);
    deleteList(list);
    return 0;
}
