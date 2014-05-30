#include "Membership_management.h"

/*int deletePerson()
{
char num[12];
int select;
printf("ã�� �л��� �й��� �Է��ϼ���:");
scanf("%s", num);
for (int i = 0; i < n; i++)
{
if (strcmp(num, Person[i].personNum) == 0)
{
printf("�� �� : %s\n",Person[i].personNum);
printf("�� �� : %s\n",Person[i].personName);
printf("�� �� : %s\n",Person[i].personAdress);
printf("��ȭ��ȣ: %s\n", Person[i].phoneNum);

printf("�� �л��� ������ ����ðڽ��ϱ�?");
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

	printf("ȸ�� ��ȣ:");
	fflush(stdin);
	scanf("%s", &Person[n].personNum);


	printf("ȸ�� �̸�:");
	fflush(stdin);
	scanf("%s", &Person[n].personName);

	printf("ȸ�� �ּ�:");
	fflush(stdin);
	scanf("%[^\n]", &Person[n].personAdress);

	printf("ȸ�� �ڵ��� ��ȣ:");
	fflush(stdin);
	scanf("%[^\n]", &Person[n].phoneNum);
	n++;
	printf("\n� �ൿ�� �߰��� �Ͻǰǰ���?(Yes : 1 or No : 0):");


	while (1)
	{
		fflush(stdin);
		scanf_s("%d", &ask);

		if (ask != 0 && ask != 1)
		{
			printf("�߸��� �Է��Դϴ�. �ٽ� �Է��ϼ���.\n");
			printf("\n� �ൿ�� �߰��� �Ͻǰǰ���?(Yes : 1 or No : 0):");
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

	printf("����Ǿ����ϴ�.\n");
	printf("\n� �ൿ�� �߰��� �Ͻǰǰ���?(Yes : 1 or No : 0):");
	while (1)
	{
		fflush(stdin);
		scanf_s("%d", &ask);

		if (ask != 0 && ask != 1)
		{
			printf("�߸��� �Է��Դϴ�. �ٽ� �Է��ϼ���.\n");
			printf("\n� �ൿ�� �߰��� �Ͻǰǰ���?(Yes : 1 or No : 0):");
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

	printf("\n� �ൿ�� �߰��� �Ͻǰǰ���?(Yes : 1 or No : 0):");

	while (1)
	{
		fflush(stdin);
		scanf_s("%d", &ask);

		if (ask != 0 && ask != 1)
		{
			printf("�߸��� �Է��Դϴ�. �ٽ� �Է��ϼ���.\n");
			printf("\n� �ൿ�� �߰��� �Ͻǰǰ���?(Yes : 1 or No : 0):");
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
		puts("���Ͽ��� ����!");
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

		int selectNum = 0;//�� ó�� ȭ�鿡�� � �ൿ�� �� ������ �����ϴ� ����

		system("cls");
		fflush(stdin);
		printf("\n\n� �ൿ�� �Ͻǰǰ���?\n\n");
		printf("=============================================================================\n");
		printf("1.ȸ�� ����\n");
		printf("2.ȸ�� ����ϱ�\n");
		printf("3.ȸ�� �����ϱ�\n");
		printf("4.ȸ�� �����ϱ�\n");
		printf("5.�����ϱ�\n");
		printf("6.ȸ�� �˻��ϱ�\n");
		printf("7.�����ϱ�\n\n");
		printf("=============================================================================\n");
		printf("\n�Է�:");




		while (1){
			scanf_s("%d", &selectNum);

			if (selectNum < 1 || selectNum >7){
				printf("�߸��� ���ڸ� �Է��ϼ̽��ϴ�. �ٽ� �Է��ϼ���.\n");
				printf("\n�Է�:");
			}
			else
				break;

		}
		if (selectNum == 1)
		{
			if (readFileData() == 1){
				system("cls");
				printf("\n���α׷��� �����մϴ�.\n\n");
				break;
			}
		}
		else if (selectNum == 2)
		{
			if (addNewPerson() == 1){
				system("cls");
				printf("\n���α׷��� �����մϴ�.\n\n");
				break;
			}
		}

		else if (selectNum == 5)
		{
			if (saveFile() == 1){
				system("cls");
				printf("\n���α׷��� �����մϴ�.\n\n");
				break;
			}
		}
		else if (selectNum == 7)
		{
			system("cls");
			printf("\n���α׷��� �����մϴ�.\n\n");
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
