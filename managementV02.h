#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_PERSONNAME 10
#define MAX_PHONENUM 30
#define ADDRESS "./data.txt"
#define BUFFER_SIZE 256
typedef struct PERSON{
	int personNum;
	char personName[MAX_PERSONNAME];
	char personAdress[100];
	char phoneNum[MAX_PHONENUM];

}person;

char userDataInfo[100];

int deletePerson();
void deleteData(int i);
int rewritePerson();
void rewirteData(int i);
int searchPerson();
int checkStudentNumMax();
void choiceAct();
int readFileData();
int addNewPerson();
int deletePerson();
int saveFile();
int n = 0;
int askForMoreAct();
int checkValidData(char * list);
int printFileData();
void uploadDataToMemory();
int deletePerson();
person Person[1000];