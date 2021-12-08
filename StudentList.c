#include <stdio.h>
#include <stdlib.h>
#include "StudentList.h"

//this is creating the base list (no nodes yet)
StudentList* createList(){
    StudentList* list = (StudentList*)malloc(sizeof(StudentList));
    if(list == NULL){
        printf("didnt create list \n");
    }
    list->head = NULL;
    return list;
}

void deleteList(StudentList* list){
    StudentNode* temp;
    StudentNode* temp2;
    temp = list->head;
    while(temp != NULL){
        temp2 = temp;
        free(temp -> st);
        free(temp);
        temp = temp->next;
        temp2 = NULL;
    }
    free(list);
}

// this is printing all the nodes .
void printStudentNode(StudentNode* const student1){
        printf("%d\n", student1->st->id);
        printf("%d\n", student1->st->grade1);
        printf("%d\n", student1->st->grade2);
}

void printStudentList(StudentList* const list){
    StudentNode* temp;
    temp = list -> head;
    while(temp != NULL){
        printf("%d\n", temp->st->id);
        printf("%d\n", temp->st->grade1);
        printf("%d\n", temp->st->grade2);
        temp = temp -> next;
    }
    return;
}

void addToList(StudentList* list, Student* studentInfo){
    StudentNode* newStudentNode = (StudentNode*)malloc(sizeof(StudentNode));
    newStudentNode->st = studentInfo;
    newStudentNode->next = NULL;
    if(list -> head == NULL){
        list -> head = newStudentNode;
    }else{
        StudentNode* current;
        current = list -> head;
        while(current->next != NULL){
            current = current -> next;
        }
        current -> next = newStudentNode;
    }
    return;
}






