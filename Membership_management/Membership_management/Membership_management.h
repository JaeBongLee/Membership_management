#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define ADDRESS "./data.txt"
#define BUFFER_SIZE 256
typedef struct PERSON{
	char personNum[12];
	char personName[10];
	char personAdress[100];
	char phoneNum[30];

}person;

void choiceAct();
int readFileData();
int addNewPerson();
int deletePerson();
int saveFile();
int n = 0;

person Person[1000];