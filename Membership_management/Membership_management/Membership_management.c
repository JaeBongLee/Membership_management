#include "Membership_management.h"

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

int addNewPerson()
{

	int ask;
	system("cls");
	printf("=============================================================================\n");

	printf("회원 번호:");
	fflush(stdin);
	scanf("%s", &Person[n].personNum);


	printf("회원 이름:");
	fflush(stdin);
	scanf("%s", &Person[n].personName);

	printf("회원 주소:");
	fflush(stdin);
	scanf("%[^\n]", &Person[n].personAdress);

	printf("회원 핸드폰 번호:");
	fflush(stdin);
	scanf("%[^\n]", &Person[n].phoneNum);
	n++;
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

int saveFile()
{
	FILE *dataWrite = fopen(ADDRESS, "wt");
	int ask;
	for (int i = 0; i < n; i++){
		fputs(Person[i].personNum, dataWrite);
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



	return 0;
}

int readFileData()
{

	int i;

	int ask;

	system("cls");


	for (i = 0; i < n; i++)
	{
		printf("%s\t", Person[i].personNum);
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

void choiceAct()
{
	FILE * dataRead = fopen(ADDRESS, "rt");
	char buf[BUFFER_SIZE];
	int i = 0;
	if (dataRead == NULL)
	{
		puts("파일오픈 실패!");
		return -1;
	}

	while (!feof(dataRead)){
		int temp1, temp2, temp3;
		fgets(buf, sizeof(buf), dataRead);
		temp1 = cutArray(&buf[0], &Person[n].personNum);
		temp2 = cutArray(&buf[temp1], &Person[n].personName);
		temp3 = cutArray(&buf[temp1 + temp2], &Person[n].personAdress);
		cutArray(&buf[temp1 + temp2 + temp3], &Person[n].phoneNum);
		n++;
	}
	fclose(dataRead);

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




		while (1){
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
			if (readFileData() == 1){
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

		else if (selectNum == 5)
		{
			if (saveFile() == 1){
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

int cutArray(char *forCutArray, char *forSaveArray){
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

int main(void)
{
	choiceAct();
}
