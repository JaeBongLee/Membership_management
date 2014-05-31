#include "management.h"

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
void askForMoreAct()
{
	int ask;

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

int checkValidData(char * list)
{
	int i;
	int length = strlen(list);
	if (length == 0)
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

	printf("ȸ�� ��ȣ: %d\n",Person[n-1].personNum + 1);
	Person[n].personNum = Person[n - 1].personNum + 1;

	printf("ȸ�� �̸�:");
	fflush(stdin);
	scanf("%s", &Person[n].personName);


	while (1)
	{
		printf("ȸ�� �ּ�:");
		fflush(stdin);
		scanf("%[^\n]s", &Person[n].personAdress);
		if (Person[n].personAdress[0] != '\0' && Person[n].personAdress[0] != 32)
			break;
		printf("Error! ���Ŀ� �����ʴ� ������ �Է��߽��ϴ�.\n");
	}
	
	while (1)
	{
			printf("ȸ�� �ڵ��� ��ȣ:");
			fflush(stdin);
			scanf("%[^\n]", &Person[n].phoneNum);
			
			if (checkValidData(Person[n].phoneNum) == 1)
				break;
			
			printf("Error! ���Ŀ� �����ʴ� ������ �Է��߽��ϴ� (xxx-xxxx-xxxx)�������� �Է��� �ּ���\n");
	}


	n++;
	askForMoreAct();

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
	askForMoreAct();


	return 0;
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




		while (1){// ����ó��
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
			if (printFileData() == 1){
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

/*int cutArray(char *forCutArray, char *forSaveArray){
	/*chat������ ������ִ� �������� �ϳ��ϳ� ������ ���������� ����� person.~~~�� ī���ϱ� ���� ���� �Լ�
	�ǹ��ڳ� ������ ������ �ݺ��� �����ϴ� ���α׷�
	����ϴ� �Լ� : uploadDataToMemory
	
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
fscnaf�� ���ؼ� �˰��� �ʿ������ �Լ��Դϴ� �ФФФФФФФФ�

*/

void uploadDataToMemory()
{
	/*������ ��� �װ��� ����� �������� �������� ����� Person.~~�� �ִ� �Լ�*/
	FILE * dataRead = fopen(ADDRESS, "rt");
	int i = 0;
	if (dataRead == NULL)
	{
		puts("���Ͽ��� ����!");
		return -1;
	}
	
	fgets(userDataInfo, sizeof(userDataInfo), dataRead);// ù�ٿ� �ִ� �ѱ۵��� �о�� ���� ������ ��� �о��
	//������ ���������� 0���� �����ϴ� Person[n].~~~�� ���Ͽ� �ִ� ������ ����,������
	while (!feof(dataRead)){
		char tempBuf[BUFFER_SIZE];
		fscanf(dataRead, "%d", &Person[n].personNum);

		fscanf(dataRead, "%s", Person[n].personName);
		fgetc(dataRead);

		int j = 0;
		char ch;
		while ((ch = fgetc(dataRead)) != '\t' && ch != -1)
		{
			Person[n].personAdress[j++] = ch;
		}
		Person[n].personAdress[j] = '\0';

		fscanf(dataRead, "%s", Person[n].phoneNum);	

		n++;//�ݺ��� �� ������ n�� ����
	}n--;
	fclose(dataRead);
}
int main(void)
{
	uploadDataToMemory();
	choiceAct();
}

