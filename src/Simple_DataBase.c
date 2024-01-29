#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
void add_item();
void Display_all_item();
void Search_item();
void Delete_item();
struct Item{
	char item_name[50], shipping_from[50];
	int item_id, quantity;
	float price;
};
int main (void){
	system("color blue");
	int choice;
	while (choice!=5){
	printf("======================DATA BASE======================");
	printf("\n	1. Add item");
	printf("\n	2. Display all item");
	printf("\n	3. Search item");
	printf("\n	4. Delete item");
	printf("\n	5. Exit :  ");
	scanf("%d", &choice);
	switch (choice){
		case 1: 
		clrscr();
		add_item();
		clrscr();
		break;
		case 2: 
		clrscr();
		Display_all_item();
		printf("\npress any key to exit\n");
		getch();
		clrscr();
		break;
		
		case 3:
		clrscr();
		Search_item();
		printf("\npress any key to exit\n");
		getch();
		clrscr();
		break;
		case 4:
		clrscr();
		Delete_item();
		printf("\npress any key to exit\n");
		getch();
		clrscr();
		break;
		case 5: 
		break; // just put break in case 5
		default : 
		clrscr();
		printf("\ninvalid option\n");
	}
	}
	return 0;
}

void add_item(){
	char another;
	FILE *fp;
	struct Item info;
	do{
	printf("======================ADD ITEM======================");
	fp=fopen("Item_info", "a");
	printf("\n	Enter item name: ");
	scanf("%s", &info.item_name);
	printf("\n	Enter item id: ");
	scanf("%d", &info.item_id);
	printf("\n	Enter item shipping address: ");
	scanf("%s", &info.shipping_from);
	printf("\n	Enter item quantity: ");
	scanf("%d", &info.quantity);
	printf("\n	Enter item price: ");
	scanf("%f", &info.price);
	if(fp==NULL){
			fprintf(stderr,"can't open file");
		}else{
			printf("\nRecord stored successfully\n");
	}
	fwrite(&info, sizeof(struct Item),1,fp);
	fclose(fp);
	printf("Do you want to add another record? (y/n): ");
	scanf("%s", &another);
	}while (another=='y' || another =='Y');
	}
void Display_all_item(){
	FILE *fp;
	struct Item info;
	fp=fopen("Item_info","r");
	printf("======================ALL ITEM======================");
	if (fp==NULL){
		fprintf(stderr,"Can't open file");
	}else{
		printf("\n\t\t  Records\n");
		printf("____________________________________________________\n");
	}
	while (fread (&info,sizeof(struct Item),1,fp)){
		/*
		struct {
		char item_name[50], shipping_from[50];
	int item_id, quantity;
	float price;
	}
		*/
		printf("\n\tItem name: %s", info.item_name);
 	   printf("\n\tid 	: %d", info.item_id);
 	   printf("\n\tshipping from	  : %s", info.shipping_from);
 	   printf("\n\tQuantity in stock   : %d", info.quantity);
 	   printf("\n\tprice	: %f", info.price);
 	   printf("\n____________________________________________________\n");
		}
		fclose (fp);
		getch( );
}
void Search_item(){
	FILE *fp;
	struct Item info;
	int id, found=0;
	fp=fopen("item_info", "r");
	printf("======================SEARCH ITEM======================");
	printf("\nEnter id no : ");
	scanf("%d", &id);
	while (fread (&info,sizeof(struct Item),1,fp)){
		if (info.item_id==id){
			found=1;
		printf("\n\tItem name: %s", info.item_name);
 	   printf("\n\tid 	: %d", info.item_id);
 	   printf("\n\tshipping from	  : %s", info.shipping_from);
 	   printf("\n\tQuantity in stock   : %d", info.quantity);
 	   printf("\n\tprice	: %f", info.price);
 	   printf("\n____________________________________________________\n");
		} if (!found){
			printf("\nrecord not found\n");
	}
		fclose (fp);
		getch( );
}

	
}
void Delete_item(){
		FILE *fp , *fp1;
	struct Item info;
	int id, found=0;
	printf("======================SEARCH ITEM======================");
	fp=fopen("item_info", "r");
	fp1=fopen("temp.txt","w");
	printf("\n Enter id no:   ");
	scanf("%d", &id);
	if (fp==NULL){
		fprintf(stderr,"can't open file");
	}
	while (fread (&info,sizeof(struct Item),1,fp)){
		if (id==info.item_id){
			found=1;
		}else {
			fwrite(&info, sizeof(struct Item),1,fp1);
		}
			
			}
			fclose(fp);
			fclose(fp1);
if (found){
	remove("item_info");
	rename("temp.txt", "item_info");
	printf("record deleted successfully");
}
	if (!found){
		printf("record not found");
	}
	getch();
}
