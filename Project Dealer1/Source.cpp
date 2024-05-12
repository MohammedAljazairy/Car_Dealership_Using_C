#include<stdio.h>
#include<string.h>
#include <windows.h>
#include<dos.h>
#define SIZE 100
#define SIZE_1 50


struct Cars
{
	int cc, year, price;
	char name[SIZE], model[SIZE], eng[SIZE], cat[SIZE], loc[SIZE];

};
struct Customer {

	int phone, year, day, Year;
	char first[SIZE_1], Carpurn[SIZE_1], last[SIZE_1], Carpurm[SIZE_1], month[SIZE_1];



};
int PrintMenu()
{

	int z;
	system("COLOR 4");
	printf("Hello! what kind of operation you want to perform? \n");
	printf("1- Add a new car/s or customer/s\n");
	printf("2- Remove a car or a customer \n");
	printf("3- Search for a car or custumor\n");
	scanf_s("%d", &z);
	system("cls");
	return z;

}
int countcars(struct Cars x[], int N)
{

	int count_1 = 0;
	FILE* p3;
	p3 = fopen("r.txt", "r");
	if (p3 == NULL) { printf("the file can't be open!!"); }
	else
	{
		while (fscanf(p3, "%s%s%s%d%d%s%d%s", x[count_1].name, x[count_1].model, x[count_1].eng, &x[count_1].cc, &x[count_1].year, x[count_1].cat, &x[count_1].price, x[count_1].loc) != EOF)
			count_1++;
	}
	fclose(p3);
	return count_1;
}
int countcus(struct Customer q[],int N)
{

	int count_2 = 0;
	FILE* p7;
	p7 = fopen("c.txt", "r");
	if (p7 == NULL) { printf("the file can't be open!!"); }
	else
	{
		while (fscanf(p7, "%s%s%d%s%s%d%d%s%d", q[count_2].first, q[count_2].last, &q[count_2].phone, q[count_2].Carpurn, q[count_2].Carpurm, &q[count_2].year, &q[count_2].day, q[count_2].month, &q[count_2].Year) != EOF)
			count_2++;
	}
	fclose(p7);
	return count_2;
}
void Addcar(struct Cars x[], int N, struct Cars arr[], int B) {
	int y;
	printf("Enter number of car/s you want add ");
	scanf("%d", &y);
	for (int i = 0;i < y;i++)
	{
		printf("Enter as in order: Manufactor, Model,Engine type,Engine Size,Year of production,Category, Price and location of the car %d\n", i + 1);
		scanf("%s%s%s%d%d%s%d%s", arr[i].name, arr[i].model, arr[i].eng, &arr[i].cc, &arr[i].year, arr[i].cat, &arr[i].price, arr[i].loc);
	}

	FILE* p1;
	p1 = fopen("r.txt", "a");
	if (p1 == NULL)
	{
		printf("file not found");
	}
	else {
		for (int i = 0;i < y;i++)
		{

			fprintf(p1, "%s %s  %s  %d  %d  %s  %d %s\n", arr[i].name, arr[i].model, arr[i].eng, arr[i].cc, arr[i].year, arr[i].cat, arr[i].price, arr[i].loc);

		}
	}
	fclose(p1);
}
int removecar(struct Cars x[], int N)
{
	int y, i, z, h = 0, flag = 0, uyear = 0;
	char Name[SIZE];
	if (h = countcars(x, SIZE_1) == 0)
	{
		printf("There are no Cars to delete\n");
	}
	else {
		printf("Enter the Model and Year of the car you want to remove ");
		scanf("%s%d", Name, &uyear);

		for (i = 0;i < N;i++) {
			if (strcmp(x[i].model, Name) == 0 && x[i].year == uyear)
			{
				flag = 1;
				for (z = i;z < N;z++)
					x[z] = x[z + 1];
			}

		}
		if (flag == 1) return 1;
		else return 0;
	}
}
void savefiledelcar(struct Cars x[], int N) {
	FILE* p3;
	p3 = fopen("r.txt", "w");
	if (p3 == NULL)
		printf("File couldn't be opened\n");
	else {
		for (int i = 0;i < N;i++)
			fprintf(p3, "%s %s %s %d  %d %s %d %s\n", x[i].name, x[i].model, x[i].eng, x[i].cc, x[i].year, x[i].cat, x[i].price, x[i].loc);
	}
	fclose(p3);

}
void searchcar(struct Cars x[], int N) {
	int i, check = 0;
	char Name[SIZE];
	printf("Enter car name: ");
	scanf("%s", Name);
	//system("cls");
	for (i = 0;i < N;i++) {
		if (strcmp(Name, x[i].name) == 0) {
			printf("Name: %s %s Engine: %s Engine size: %d Year of produtcion: %d Category: %s Price: %d Location :%s\n", x[i].name, x[i].model, x[i].eng, x[i].cc, x[i].year, x[i].cat, x[i].price, x[i].loc);
			check = 1;
		}
	}
	if (check == 0) {
		printf("The car is not found or maybe sold!\n");Beep(750, 800);
	}
}
void searchyear(struct Cars x[], int N) {
	int i, check = 0, Name;
	printf("Enter car Year: ");
	scanf("%d", &Name);

	for (i = 0;i < N;i++) {
		if (Name == x[i].year) {
			printf("Name: %s %s Engine: %s Engine size: %d Year of produtcion: %d Category: %s Price: %d Location: %s\n", x[i].name, x[i].model, x[i].eng, x[i].cc, x[i].year, x[i].cat, x[i].price, x[i].loc);
			check = 1;
		}
	}
	if (check == 0) {
		printf("The car is not found or maybe sold!\n");Beep(750, 800);
	}
}
void searchmodel(struct Cars x[], int N) {
	int i, check = 0;
	char Name[SIZE];
	printf("Enter the car model: ");
	scanf("%s", Name);
	//system("cls");
	for (i = 0;i < N;i++) {
		if (strcmp(Name, x[i].model) == 0) {
			printf("Name: %s %s Engine: %s Engine size: %d Year of produtcion: %d Category: %s Price: %d Location : %s\n", x[i].name, x[i].model, x[i].eng, x[i].cc, x[i].year, x[i].cat, x[i].price, x[i].loc);
			check = 1;
		}
	}
	if (check == 0) {
		printf("The car is not found or maybe sold!\n");Beep(750, 800);
	}
}
void searchcat(struct Cars x[], int N) {
	int i, check = 0;
	char Name[SIZE];
	printf("Enter the car Category: ");
	scanf("%s", Name);
	//system("cls");
	for (i = 0;i < N;i++) {
		if (strcmp(Name, x[i].cat) == 0) {
			printf("Name: %s %s Engine: %s Engine size: %d Year of produtcion: %d Category: %s Price: %d Location : %s\n", x[i].name, x[i].model, x[i].eng, x[i].cc, x[i].year, x[i].cat, x[i].price, x[i].loc);
			check = 1;
		}
	}
	if (check == 0) {
		printf("The car is not found or maybe sold!\n");Beep(750, 800);
	}
}
void Addcus(struct Customer q[], int N, struct Customer A[], int C) {
	int y;
	printf("Enter the number of customer/s you want add ");
	scanf("%d", &y);
	for (int i = 0;i < y;i++)
	{
		printf("Enter as in order: First and last name, Phone, The purchased car Name, Model, Year of production, and the Date of purcahse (d/m/y)  %d\n", i + 1);
		scanf("%s%s%011d%s%s%d%d%s%d", A[i].first, A[i].last, &A[i].phone, A[i].Carpurn, A[i].Carpurm, &A[i].year, &A[i].day, A[i].month, &A[i].Year);
	}
	FILE* p6;
	p6 = fopen("c.txt", "a");
	if (p6 == NULL)
	{
		printf("file not found");
	}
	else {
		for (int i = 0;i < y;i++)
		{

			fprintf(p6, "%s %s %011d %s %s %d %d %s %d \n", A[i].first, A[i].last, A[i].phone, A[i].Carpurn, A[i].Carpurm, A[i].year, A[i].day, A[i].month, A[i].Year);

		}
	}
	fclose(p6);
}
int removecus(struct Customer q[], int N)
{
	int y, i, z, flag_1 = 0, h = 0, telephone = 0;
	char Name[SIZE];
	if (h = countcus(q, SIZE_1) == 0)
	{
		printf("There are no Customers to delete\n");
	}
	else {
		printf("Enter the name and telephone of the customer you want to remove ");
		scanf("%s%d", Name, &telephone);

		for (i = 0;i < N;i++) {
			if (strcmp(q[i].first, Name) == 0 && q[i].phone == telephone)
			{
				flag_1 = 1;
				for (z = i;z < N;z++)
					q[z] = q[z + 1];
			}

		}
		if (flag_1 == 1) return 1;
		else return 0;
	}
}
void savefiledelcus(struct Customer q[], int N) {
	FILE* p8;
	p8 = fopen("c.txt", "w");
	if (p8 == NULL)
		printf("File couldn't be opened\n");
	else {
		for (int i = 0;i < N;i++)
			fprintf(p8, "%s %s %011d %s %s %d %d %s %d \n", q[i].first, q[i].last, q[i].phone, q[i].Carpurn, q[i].Carpurm, q[i].year, q[i].day, q[i].month, q[i].Year);
	}
	fclose(p8);

}
void searchcus(struct Customer q[], int N) {
	int i, check_3 = 0;
	char Name_1[SIZE_1];
	printf("Enter customer name: ");
	scanf("%s", Name_1);
	//system("cls");
	for (i = 0;i < N;i++) {
		if (strcmp(Name_1, q[i].first) == 0) {
			printf("Name: %s %s Telephone: %011d Car purchased: %s %s Year of production: %d The date of Purchase: %d %s ,%d\n", q[i].first, q[i].last, q[i].phone, q[i].Carpurn, q[i].Carpurm, q[i].year, q[i].day, q[i].month, q[i].Year);
			check_3 = 1;
		}
	}
	if (check_3 == 0) {
		printf("The customer is not found!\n");Beep(750, 800);
	}
}
void fullname_search(struct Customer q[], int n)
{
	int j, i, flag = 0;
	char name1[15];
	char name2[15];
	printf(" write the full name:  ");
	scanf("%s%s", name1, name2);
	for (i = 0;i < n;i++)
	{
		if (strcmp(q[i].first, name1) == 0)
		{
			if (strcmp(q[i].last, name2) == 0)
				printf("Name: % s % s Telephone : %011d Car purchased : % s % s Year of production : % d The date of Purchase : % d % s, % d\n", q[i].first, q[i].last, q[i].phone, q[i].Carpurn, q[i].Carpurm, q[i].year, q[i].day, q[i].month, q[i].Year);
			flag = 1;
		}
	}
	if (flag == 0) {
		printf("The customer is not found");
		Beep(750, 800);
	}

}
int main(void) {
	struct Cars x[SIZE];struct Cars arr[SIZE];
	struct Customer q[SIZE_1];struct Customer A[SIZE_1];
	int countnum = countcars(x, SIZE), h, p, j, countcheck = countcus(q, SIZE_1);
	printf("Number of Cars:%d\n", countnum);
	printf("Number of Customres:%d\n", countcheck);
	char ch[2];
	do {

		h = PrintMenu();

		if (h == 1) {
			printf("do you want to enter A car or a customer info ?\n");
			printf("1-Car Information\n");
			printf("2-Custumor Information\n");
			scanf("%d", &p);
			if (p == 1)
				Addcar(x, SIZE, arr, SIZE);
			if (p == 2)
				Addcus(q, SIZE_1, A, SIZE_1);

		}

		if (h == 2) {
			printf("do you want to remove a car or a customer ?\n");
			printf("1-Car \n");
			printf("2-Custumor \n");
			scanf("%d", &p);
			if (p == 1) {
				int b = removecar(x, countnum);
				if (b == 1) { printf("\nThe car data is succesfully deleted");countnum--; }
				else { printf("\nThe car data is not found"); }
				savefiledelcar(x, countnum);
			}
			if (p == 2) {
				int c = removecus(q, countcheck);
				if (c == 1) { printf("\nThe customer data is succesfully deleted");countcheck--; }
				else { printf("\nThe customer data is not found"); }
				savefiledelcus(q, countcheck);
			}

		}
		if (h == 3) {
			printf("Do you want to search the car or the custumor info?\n");
			printf("1-Car Information\n");
			printf("2-Custumor Information\n");
			scanf("%d", &p);
			if (p == 1) {
				printf("What do you want search to by ?\n");
				printf("1- Manufactor\n");
				printf("2- Model\n");
				printf("3- Year\n");
				printf("4- Category\n");
				scanf("%d", &j);
				if (j == 1) {
					countnum = countcars(x, SIZE);
					searchcar(x, countnum);
				}
				if (j == 2) {
					countnum = countcars(x, SIZE);
					searchmodel(x, countnum);

				}
				if (j == 3) {
					countnum = countcars(x, SIZE);
					searchyear(x, countnum);

				}
				if (j == 4) {
					countnum = countcars(x, SIZE);
					searchcat(x, countnum);

				}
			}
			if (p == 2) {
				printf("1-search by first name: \n");
				printf("2-search by full name : \n");
				scanf("%d", &p);
				if (p == 1)
				{
					countcheck = countcus(q, SIZE_1);
					searchcus(q, countcheck);
				}
				else if (p == 2)fullname_search(q, countcheck);


			}


		}


		else
		{

		}printf("\nDo you want to repeat the operation Y/N: ");


		scanf("%s", ch);
	} while (strcmp(ch, "y") == 0 || strcmp(ch, "Y") == 0);

	return 0;
}