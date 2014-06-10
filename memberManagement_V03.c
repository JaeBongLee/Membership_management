#include "management.h"

/*int deletePerson()
{
char num[12];
int select;
printf("찾을 학생의 학번을 입력하세요:");
scanf("%s", num);
for (int i = 0; i < n; i++)
{
if (strcmp(num, Person[i].personNum) == 0)
{
printf("학 번 : %s\n",Person[i].personNum);
printf("이 름 : %s\n",Person[i].personName);
printf("주 소 : %s\n",Person[i].personAdress);
printf("전화번호: %s\n", Person[i].phoneNum);

printf("이 학생의 정보를 지우시겠습니까?");
printf("(YES : 1 NO :0):");
scanf("%d", &select);

if (select == 1)
{
for (int j = i; i < n; j++)
{
Person[i].personAdress = Person[i + 1].personAdress;
}
}
}
}
}*/
int askForMoreAct()
{
	int ask;

	printf("\n어떤 행동을 추가로 하실건가요?(Yes : 1 or No : 0):");
	
	while (1)
	{
		fflush(stdin);
		scanf_s("%d", &ask);

		if (ask != 0 && ask != 1)
		{
			printf("잘못된 입력입니다. 다시 입력하세요.\n");
			printf("\n어떤 행동을 추가로 하실건가요?(Yes : 1 or No : 0):");
		}
		else if (ask == 1){
			return 0;
		}
		else if (ask == 0)
		{
			return 1;
		}
	}
}

int checkValidData(char * list)
{
	int i;
	int length = strlen(list);
	if (length == 0)
	{
		return 0;
	}
	if (length > MAX_PHONENUM)
	{
		return 0;
	}
	for (i=0; i < length;i++)
	{
		if (!(('0' <= Person[n].phoneNum[i] && Person[n].phoneNum[i] <= '9') || Person[n].phoneNum[i] == '-'))
			return 0;
	}
	return 1;
}

int addNewPerson()
{
	system("cls");
	printf("=============================================================================\n");

	printf("회원 번호: %d\n",checkStudentNumMax() + 1);
	Person[n].personNum = checkStudentNumMax() + 1;

	printf("회원 이름:");
	fflush(stdin);
	scanf("%s", &Person[n].personName);


	while (1)
	{
		printf("회원 주소:");
		fflush(stdin);
		scanf("%[^\n]s", &Person[n].personAdress);
		if (Person[n].personAdress[0] != '\0' && Person[n].personAdress[0] != 32)
			break;
		printf("Error! 형식에 맞지않는 정보를 입력했습니다.\n");
	}
	
	while (1)
	{
			printf("회원 핸드폰 번호:");
			fflush(stdin);
			scanf("%[^\n]", &Person[n].phoneNum);
			
			if (checkValidData(Person[n].phoneNum) == 1)
				break;
			
			printf("Error! 형식에 맞지않는 정보를 입력했습니다 (xxx-xxxx-xxxx)형식으로 입력해 주세요\n");
	}


	n++;
	return askForMoreAct();

}

int saveFile()
{
	FILE *dataWrite = fopen(ADDRESS, "wt");
	int ask;
	fputs(userDataInfo, dataWrite);
	for (int i = 0; i < n; i++){
		
		fprintf(dataWrite,"%d", Person[i].personNum);
		fputs("\t", dataWrite);
		fputs(Person[i].personName, dataWrite);
		fputs("\t", dataWrite);
		fputs(Person[i].personAdress, dataWrite);
		fputs("\t", dataWrite);
		fputs(Person[i].phoneNum, dataWrite);
		fputs("\n", dataWrite);
	}

	fclose(dataWrite);
	system("cls");

	printf("저장되었습니다.\n");
	


	return askForMoreAct();
}

int printFileData()
{

	int i;

	int ask;

	system("cls");

	printf("%s", userDataInfo);
	for (i = 0; i < n; i++)
	{
		printf("%d\t", Person[i].personNum);
		printf("%s\t", Person[i].personName);
		printf("%s\t", Person[i].personAdress);
		printf("%s\n", Person[i].phoneNum);
	}

	printf("\n어떤 행동을 추가로 하실건가요?(Yes : 1 or No : 0):");

	while (1)
	{
		fflush(stdin);
		scanf_s("%d", &ask);

		if (ask != 0 && ask != 1)
		{
			printf("잘못된 입력입니다. 다시 입력하세요.\n");
			printf("\n어떤 행동을 추가로 하실건가요?(Yes : 1 or No : 0):");
		}
		else if (ask == 1){
			return 0;
		}
		else if (ask == 0)
		{
			return 1;
		}
	}

}

int checkStudentNumMax()
{
	int max = Person[0].personNum;

	for (int i = 0; i < n; i++)
	{
		if (max < Person[i].personNum)
			max = Person[i].personNum;
	}
	return max;
}

int searchPerson()
{
	int choiceNum;
	int personNum;
	int count = 0;
	char personName[MAX_PERSONNAME];
	char phoneNum[MAX_PHONENUM];
	int i;

	printf("=============================================================================\n");
	printf("어떤 정보로 학생을 찾을 것인가요?\n\n");
	printf("1.학번\n 2.학생 이름\n 3.전화번호\n");
	
	while (1)
	{
		printf("입력:");
		fflush(stdin);
		scanf("%d", &choiceNum);
		if (choiceNum != 1 && choiceNum != 2 && choiceNum != 3 )
			printf("잘못된 입력입니다.");
		else
			break;
	}

	if (choiceNum == 1)
	{
		printf("찾을 학생의 학번을 입력하세요:");
		fflush(stdin);
		scanf("%d", &personNum);

		for (i = 0; i < n; i++)
		{
			if (personNum == Person[i].personNum)
			{
				printf("%d:", personNum);
				printf("%s\t", Person[i].personName);
				printf("%s\t", Person[i].personAdress);
				printf("%s\n", Person[i].phoneNum);
				break;
				
			}
		}
		if (i == n && personNum != Person[i-1].personNum )
			printf("찾으시는 학번의 학생은 없거나 잘못된 입력입니다.\n");
		
	}
	if (choiceNum == 2)
	{
		printf("찾으시는 학생의 이름을 입력하세요:");
		fflush(stdin);
		scanf("%s", &personName);
		for (i = 0; i < n; i++)
		{
			if (strcmp(Person[i].personName, personName) == 0)
			{
				printf("%d:", Person[i].personNum);
				printf("%s\t", Person[i].personName);
				printf("%s\t", Person[i].personAdress);
				printf("%s\n", Person[i].phoneNum);
				count++;

			}
		}
		if (i == n && count == 0)
			printf("찾으시는 학번의 학생은 없거나 잘못된 입력입니다.\n");
	}
	if (choiceNum == 3)
	{
		printf("찾으시는 학생의 전화번호를 입력하세요:");
		fflush(stdin);
		scanf("%s", &phoneNum);
		for (i = 0; i < n; i++)
		{
			if (strcmp(Person[i].phoneNum, phoneNum) == 0)
			{
				printf("%d:", Person[i].personNum);
				printf("%s\t", Person[i].personName);
				printf("%s\t", Person[i].personAdress);
				printf("%s\n", Person[i].phoneNum);
				count++;

			}
		}
		if (i == n && count == 0)
			printf("찾으시는 학번의 학생은 없거나 잘못된 입력입니다.\n");
	}
	return askForMoreAct();
}

void deleteData(int i)
{
	int deleteNum;
	
	while (1)
	{
		printf("삭제하시겠습니까?(yes : 1, no : 0)");
		fflush(stdin);
		scanf("%d", &deleteNum);
		if (deleteNum != 1 && deleteNum != 0)
			printf("잘못된 입력입니다");

		else
			break;
	}

	if (deleteNum == 1)
	{
		for (int j = i; j < n; j++)
		{
			Person[j] = Person[j+1];
		}
		n--;
	}

}

int deletePerson()
{
	int choiceNum;
	int personNum;
	int count = 0;
	char personName[MAX_PERSONNAME];
	char phoneNum[MAX_PHONENUM];
	int i;

	printf("=============================================================================\n");
	printf("어떤 정보로 학생을 찾을 것인가요?\n\n");
	printf("1.학번\n 2.학생 이름\n 3.전화번호\n");

	while (1)
	{
		printf("입력:");
		fflush(stdin);
		scanf("%d", &choiceNum);
		if (choiceNum != 1 && choiceNum != 2 && choiceNum != 3)
			printf("잘못된 입력입니다.");
		else
			break;
	}

	if (choiceNum == 1)
	{
		printf("찾을 학생의 학번을 입력하세요:");
		fflush(stdin);
		scanf("%d", &personNum);

		for (i = 0; i < n; i++)
		{
			if (personNum == Person[i].personNum)
			{
				
				printf("%d:", personNum);
				printf("%s\t", Person[i].personName);
				printf("%s\t", Person[i].personAdress);
				printf("%s\n", Person[i].phoneNum);
				deleteData(i);
				
				
				break;

			}
		}
		if (i == n && personNum != Person[i - 1].personNum)
			printf("찾으시는 학번의 학생은 없거나 잘못된 입력입니다.\n");

	}
	if (choiceNum == 2)
	{
		printf("찾으시는 학생의 이름을 입력하세요:");
		fflush(stdin);
		scanf("%s", &personName);
		for (i = 0; i < n; i++)
		{
			if (strcmp(Person[i].personName, personName) == 0)
			{
				printf("%d:", Person[i].personNum);
				printf("%s\t", Person[i].personName);
				printf("%s\t", Person[i].personAdress);
				printf("%s\n", Person[i].phoneNum);
				deleteData(i);
				count++;

			}
		}
		if (i == n && count == 0)
			printf("찾으시는 학번의 학생은 없거나 잘못된 입력입니다.\n");
	}
	if (choiceNum == 3)
	{
		printf("찾으시는 학생의 전화번호를 입력하세요:");
		fflush(stdin);
		scanf("%s", &phoneNum);
		for (i = 0; i < n; i++)
		{
			if (strcmp(Person[i].phoneNum, phoneNum) == 0)
			{
				printf("%d:", Person[i].personNum);
				printf("%s\t", Person[i].personName);
				printf("%s\t", Person[i].personAdress);
				printf("%s\n", Person[i].phoneNum);
				deleteData(i);
				count++;

			}
		}
		if (i == n && count == 0)
			printf("찾으시는 학번의 학생은 없거나 잘못된 입력입니다.\n");
	}
	return askForMoreAct();
}

void rewirteData(int i)
{
	int selectNum;
	printf("=============================================================================\n");
	printf("이 학생의 어떤 정보를 수정하실 건가요?\n");
	printf("1.취소\n 2.학생이름\n3.주소\n4.전화번호\n");

	while (1)
	{
		printf("입력:");
		fflush(stdin);
		scanf("%d", &selectNum);
		if (selectNum != 1 && selectNum != 2 && selectNum != 3 && selectNum != 4)
			printf("잘못된 입력입니다.\n");
		else
			break;
	}

	if (selectNum == 1)
	{
		return;
	}
	else if (selectNum == 2)
	{
		printf("수정 후 이름:");
		fflush(stdin);
		scanf("%s", &Person[i].personName);
	}
	else if (selectNum == 3)
	{
		while (1)
		{
			printf("회원 주소:");
			fflush(stdin);
			scanf("%[^\n]s", &Person[i].personAdress);
			if (Person[i].personAdress[0] != '\0' && Person[i].personAdress[0] != 32)
				break;
			printf("Error! 형식에 맞지않는 정보를 입력했습니다.\n");
		}

	}
	else if (selectNum == 4)
	{
		while (1)
		{
			printf("수정 후 회원 핸드폰 번호:");
			fflush(stdin);
			scanf("%[^\n]", &Person[i].phoneNum);

			if (checkValidData(Person[i].phoneNum) == 1)
				break;

			printf("Error! 형식에 맞지않는 정보를 입력했습니다 (xxx-xxxx-xxxx)형식으로 입력해 주세요\n");
		}

	}
}

int rewritePerson()
{
	int choiceNum;
	int personNum;
	int count = 0;
	char personName[MAX_PERSONNAME];
	char phoneNum[MAX_PHONENUM];
	int i;

	printf("=============================================================================\n");
	printf("어떤 정보로 학생을 찾을 것인가요?\n\n");
	printf("1.학번\n 2.학생 이름\n 3.전화번호\n");

	while (1)
	{
		printf("입력:");
		fflush(stdin);
		scanf("%d", &choiceNum);
		if (choiceNum != 1 && choiceNum != 2 && choiceNum != 3)
			printf("잘못된 입력입니다.\n");
		else
			break;
	}

	if (choiceNum == 1)
	{
		printf("찾을 학생의 학번을 입력하세요:");
		fflush(stdin);
		scanf("%d", &personNum);

		for (i = 0; i < n; i++)
		{
			if (personNum == Person[i].personNum)
			{
				int selectNum;
				printf("%d:", personNum);
				printf("%s\t", Person[i].personName);
				printf("%s\t", Person[i].personAdress);
				printf("%s\n", Person[i].phoneNum);
				rewirteData(i);
				
				break;

			}
		}
		if (i == n && personNum != Person[i-1].personNum)
			printf("찾으시는 학번의 학생은 없거나 잘못된 입력입니다.\n");

	}
	if (choiceNum == 2)
	{
		printf("찾으시는 학생의 이름을 입력하세요:");
		fflush(stdin);
		scanf("%s", &personName);
		for (i = 0; i < n; i++)
		{
			if (strcmp(Person[i].personName, personName) == 0)
			{
				int selectNum;
				printf("%d:", Person[i].personNum);
				printf("%s\t", Person[i].personName);
				printf("%s\t", Person[i].personAdress);
				printf("%s\n", Person[i].phoneNum);
				rewirteData(i);
				count++;

			}
		}
		if (i == n && count == 0)
			printf("찾으시는 학번의 학생은 없거나 잘못된 입력입니다.\n");
	}
	if (choiceNum == 3)
	{
		printf("찾으시는 학생의 전화번호를 입력하세요:");
		fflush(stdin);
		scanf("%s", &phoneNum);
		for (i = 0; i < n; i++)
		{
			if (strcmp(Person[i].phoneNum, phoneNum) == 0)
			{
				printf("%d:", Person[i].personNum);
				printf("%s\t", Person[i].personName);
				printf("%s\t", Person[i].personAdress);
				printf("%s\n", Person[i].phoneNum);
				rewirteData(i);
				count++;

			}
		}
		if (i == n && count == 0)
			printf("찾으시는 학번의 학생은 없거나 잘못된 입력입니다.\n");
	}


	return askForMoreAct();
}

void choiceAct()
{
	while (1)
	{

		int selectNum = 0;//맨 처음 화면에서 어떤 행동을 할 것인지 저장하는 변수

		system("cls");
		fflush(stdin);

		printf("\n\n어떤 행동을 하실건가요?\n\n");
		printf("=============================================================================\n");
		printf("1.회원 보기\n");
		printf("2.회원 등록하기\n");
		printf("3.회원 삭제하기\n");
		printf("4.회원 수정하기\n");
		printf("5.저장하기\n");
		printf("6.회원 검색하기\n");
		printf("7.종료하기\n\n");
		printf("=============================================================================\n");
		printf("\n입력:");




		while (1){// 예외처리
			scanf_s("%d", &selectNum);

			if (selectNum < 1 || selectNum >7){
				printf("잘못된 숫자를 입력하셨습니다. 다시 입력하세요.\n");
				printf("\n입력:");
			}
			else
				break;

		}
		if (selectNum == 1)
		{
			if (printFileData() == 1){
				system("cls");
				printf("\n프로그램을 종료합니다.\n\n");
				break;
			}
		}
		else if (selectNum == 2)
		{
			if (addNewPerson() == 1){
				system("cls");
				printf("\n프로그램을 종료합니다.\n\n");
				break;
			}
		}

		else if (selectNum == 3)
		{
			system("cls");
			if (deletePerson() == 1){
				system("cls");
				printf("\n프로그램을 종료합니다.\n\n");
				break;
			}
		}

		else if (selectNum == 4)
		{
			system("cls");
			if (rewritePerson() == 1){
				system("cls");
				printf("\n프로그램을 종료합니다.\n\n");
				break;
			}
		}

		else if (selectNum == 5)
		{
			if (saveFile() == 1){
				system("cls");
				printf("\n프로그램을 종료합니다.\n\n");
				break;
			}
		}
		else if (selectNum == 6)
		{
			system("cls");
			if (searchPerson() == 1){
				system("cls");
				printf("\n프로그램을 종료합니다.\n\n");
				break;
			}
		}

		else if (selectNum == 7)
		{
			system("cls");
			printf("\n프로그램을 종료합니다.\n\n");
			break;
		}
	}

}

/*int cutArray(char *forCutArray, char *forSaveArray){
	/*chat형으로 저장되있는 정보들을 하나하나 복사해 전역변수로 선언된 person.~~~에 카피하기 위해 만든 함수
	탭문자나 개행을 만나면 반복을 종료하는 프로그램
	사용하는 함수 : uploadDataToMemory
	
	int i;
	for (i = 0; i < BUFFER_SIZE; i++)
	{
		if (forCutArray[i] == '\t' || forCutArray[i] == '\n')
		{
			break;
		}
		forSaveArray[i] = forCutArray[i];
	}

	return i + 1;
}
fscnaf에 대해서 알고나서 필요없어진 함수입니다 ㅠㅠㅠㅠㅠㅠㅠㅠㅠ

*/

void uploadDataToMemory()
{
	/*파일을 열어서 그곳에 저장된 정보들을 전역으로 선언된 Person.~~에 넣는 함수*/
	FILE * dataRead = fopen(ADDRESS, "rt");
	int i = 0;
	
	if (dataRead == NULL)
	{
		puts("파일오픈 실패!");
		return -1;
	}
	
	fgets(userDataInfo, sizeof(userDataInfo), dataRead);// 첫줄에 있는 한글들을 읽어올 때는 한줄을 모두 읽어옴
	//파일이 끝날때까지 0부터 시작하는 Person[n].~~~에 파일에 있는 내용을 복사,저장함
	while (!feof(dataRead)){
		int j = 0;
		char ch;
		char tempBuf[BUFFER_SIZE];
		fscanf(dataRead, "%d", &Person[n].personNum);

		fscanf(dataRead, "%s", Person[n].personName);
		fgetc(dataRead);

		
		while ((ch = fgetc(dataRead)) != '\t' && ch != -1)
		{
			Person[n].personAdress[j++] = ch;
		}
		Person[n].personAdress[j] = '\0';

		fscanf(dataRead, "%s", Person[n].phoneNum);	

		n++;//반복을 돌 때마다 n을 증가
	}n--;
	fclose(dataRead);
}
int main(void)
{
	uploadDataToMemory();
	choiceAct();
}

