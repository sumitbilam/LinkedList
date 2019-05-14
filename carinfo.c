#include "carinfo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//this func create isolated node and returns the node head
car *init_car(int id, char *name, float price, char *repair, float loan)
{

	car *node_head;
	node_head = (car*)malloc(sizeof (car));

	node_head ->id = id;
	strcpy(node_head->name, name);
	node_head->price = price;

	node_head->internal_info = (secret_info*)malloc(sizeof(secret_info));
	strcpy(node_head->internal_info->repair, repair);
	node_head->internal_info->loan = loan;

	node_head->next = NULL;

	return node_head;

}

void print_inventory(car *head)
{
	printf("car inventory is :\n");
	car *current = head;
	printf("ID\tName\tPRICE\t\tRepair needed\t Finance available\n");
	while(current != NULL)
	{
		printf("%d\t%s\t$%0.2f\t\t%s\t\t\t%0.2f\n ", current->id, current->name, current->price, current->internal_info->repair,
				current->internal_info->loan);
		current = current->next;
	}
	printf("\n");
}

car *create_car_list()
{
	car *head = NULL;
	car *temp = NULL;
	car *p = NULL;
	int id, num;
	char name[6];
	float price;
	char repair[3];
	float loan;

	printf("how many cars you want to add: ");
	scanf("%d", &num);
	for (int i=0; i<num; i++){
		printf("Add %d car:\n", i+1);
		printf("Enter car ID: ");
		scanf("%d", &id);
		printf("Enter car name: ");
		scanf("%s", name);
		printf("Enter car price: ");
		scanf("%f", &price);

		printf("repair needed: ");
		scanf("%s", repair);
		if(strcmp(repair, "no") == 0){
			loan = loan_calculation(price);
		}
		else {
			loan = 0.00;
		}
		getchar();
	//making n isolated node/nodes
		temp = init_car(id, name, price, repair, loan);

		//when creating very first node
		if(head == NULL){
			head = temp;
		}
		//adding item at the end of the list
		else {
			p = head;
			while (p->next != NULL){
				p = p->next;
			}
			p->next = temp;
		}
	}
    //returns the head of the list
	return head;

}

car  *search_car(car *head, int car_id)
{
	car *pos = NULL;
	pos = head;
	int found = 0;

	while(pos != NULL){
		printf("finding....\n");
		if(pos->id == car_id){
			printf("found\n");
			found = 1;
			printf("Here is the car information:\n");
			printf("car ID\t car name\t car price\t Repair\t Loan Avail\n");
			printf("%d\t %s\t     %0.2f\t %s\t %0.2f\n",pos->id, pos->name, pos->price, pos->internal_info->repair,
					pos->internal_info->loan);
			//should I return pos here
			break;
		}
		else{
			pos = pos->next;
		}
	}
	if (found == 0){
		printf("This car is not in inventory\n");
	}

	return pos;

}

car  *delete_car(car *head, int id)
{
	car *pos, *temp = NULL;

	pos = search_car(head, id);
	//temp = pos - 1; can't decrement like this, its not sequential memory like it does in case of array
	if(pos != NULL){
		temp = head;
		while (temp->next != pos){
			printf("matching temp to pos\n");
			temp = temp->next;
		}
		temp->next = pos->next;
		pos = pos->next;
	}

	return head;
}

car *add_car_to_list(car *head)
{
	car *temp, *add = NULL;
	temp = head;

	int id;
	char name[6];
	float price;
	char repair[3];
	float loan;
	if (head != NULL){
		printf("Add new car:\n");
		printf("Enter car ID: ");
		scanf("%d", &id);
		printf("Enter car name: ");
		scanf("%s", name);
		printf("Enter car price: ");
		scanf("%f", &price);

		printf("repair needed: ");
		scanf("%s", repair);
		if(strcmp(repair, "no") == 0){
		    loan = loan_calculation(price);
		}
		else {
			loan = 0.00;
		}

		add = init_car(id, name, price, repair, loan);

		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = add;
	}
	else{
		printf("list is empty\n");
	}

	return head;
}

float loan_calculation(float car_price)
{
	return car_price * (0.10) ;
}
