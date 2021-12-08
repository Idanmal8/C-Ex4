#include <stdio.h>
#include <stdlib.h>
#include "GradesOperations.h"
#include "StudentList.h"


    int studentCounter(StudentList* list , FILE* fr , int numOfStu){
        StudentNode* current;
        current = list -> head;
        
        if(current == NULL){
            fprintf(fr ,"There is no student in the list. %d\n" , 0);
            return numOfStu;
        }
        while(current != NULL){
            numOfStu++;
            current = current -> next;
        }
        fprintf(fr , "The number of students is: %d\n" , numOfStu);
        return numOfStu;
    }
    
    void studentCounterByApproached(StudentList* list , FILE* fr){
        StudentNode* current;
        current = list -> head;
        int counter = 0;
        if(current == NULL){
            fprintf(fr ,"There is no students that approached any test. %d\n" , 0);
            return;
        }
        while(current != NULL){
            if(current -> st -> grade1 == -1 && current -> st -> grade2 == -1){
                current = current -> next;
            }
            else if(current -> st -> grade1 == -1 || current -> st -> grade2 == -1){
                counter++;
                current = current -> next;
            }else{
                current = current -> next;
            }
        }
        fprintf(fr , "The number of students that only approached one test : %d\n" , counter);
        return;
    }
    
    void studentWhoDidntTest(StudentList* list , FILE* fr){
        StudentNode* current;
        current = list -> head;
        int counter = 0;
        while(current != NULL){
            if(current -> st -> grade1 == -1 && current -> st -> grade2 == -1){
                counter++;
                current = current -> next;
            }
            else{
                current = current -> next;
            }
          }
        fprintf(fr , "The number of students who didnt approache at all : %d\n" , counter);
        return;
    }
    
    void numOfFailures(StudentList* list , FILE* fr , int numOfStudents){
        int minGrade = 60;
        double precentgeA = 0.0;
        double precentgeB = 0.0;
        StudentNode* current;
        current = list -> head;
        int counterA = 0;
        int counterB = 0;
        while(current != NULL){
            if(current -> st -> grade1 == -1 ){
                current = current -> next;
            }
            else if(current -> st -> grade1 < minGrade){
                counterA++;
                current = current -> next;
            }
            else{
                current = current -> next;
            }
        }
        current = list -> head;
        while(current != NULL){
            if(current -> st -> grade2 == -1 ){
                current = current -> next;
            }
            else if(current -> st -> grade2 < minGrade){
                counterB++;
                current = current -> next;
            }
            else{
                current = current -> next;
            }
        }
        precentgeA = ((double)counterA / (double)numOfStudents) * 100;
        precentgeB = ((double)counterB / (double)numOfStudents) * 100;

        fprintf(fr , "The precentge of students who fail in approache A is : %.2f%%\n" , precentgeA);
        fprintf(fr , "The precentge of students who fail in approache B is: %.2f%%\n" , precentgeB);
        return;
    }
    
    
    void avrageGrades(StudentList* list , FILE* fr){
        int gradeScoreA = 0;
        int gradeScoreB = 0;
        int counterA = 0;
        int counterB = 0;
        double avarageA = 0.0;
        double avarageB = 0.0;
        StudentNode* current;
        current = list -> head;
        while(current != NULL){
            if(current -> st -> grade1 == -1 ){
                current = current -> next;
            }
            else{
            gradeScoreA += (current -> st -> grade1);
            counterA++;
            current = current -> next;
            }
        }
        current = list -> head;
        while(current != NULL){
            if(current -> st -> grade2 == -1 ){
                current = current -> next;
            }else{
            gradeScoreB += (current -> st -> grade2);
            counterB++;
            current = current -> next;
            }
        }
        avarageA = (double)gradeScoreA / counterA;
        avarageB = (double)gradeScoreB / counterB;
        fprintf(fr , "The avrage is : %.2f\n" , avarageA);
        fprintf(fr , "The avrage is : %.2f\n" , avarageB);
        return;
    }

    void simplyTheBest(StudentList* list , FILE* fr){
        int bestGrade = 0;
        int idOfTheBest = 0;
        StudentNode* current;
        current = list -> head;
        while(current != NULL){
            if(current -> st -> grade1 > bestGrade){
                bestGrade = current -> st -> grade1;
                idOfTheBest = current -> st -> id;
            }
            if(bestGrade < current -> st -> grade2){
                bestGrade = current -> st -> grade2;
                idOfTheBest = current -> st -> id;
            }
                current = current -> next;
            
        }
        fprintf(fr , "The best student is : %d , grade : %d\n" , idOfTheBest , bestGrade);
        return;
    }
    
    void simplyNotTheBest(StudentList* list , FILE* fr){
        int notTheBestGrade = 100;
        int idOfTheFailure = 0;
        StudentNode* current;
        current = list -> head;
        while(current != NULL){
            if(current -> st -> grade1 < notTheBestGrade && current -> st -> grade1 >= 0){
                notTheBestGrade = current -> st -> grade1;
                idOfTheFailure = current -> st -> id;
            }
            if(notTheBestGrade > current -> st -> grade2 && current -> st -> grade2 >= 0){
                notTheBestGrade = current -> st -> grade2;
                idOfTheFailure = current -> st -> id;
            }
            current = current -> next;
            
        }
        fprintf(fr , "The worst student is : %d , grade : %d\n" , idOfTheFailure , notTheBestGrade);
        return;
    }
    


    
    
    
    
    
    
    
    
    
    