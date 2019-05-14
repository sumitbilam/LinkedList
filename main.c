/*
 * main.c
 *
 *  Created on: Mar 8, 2019
 *      Author: sumit
 */

#include "carinfo.h"
#include <stdio.h>
#include <stdlib.h>



int main ()
{


	car *add = create_car_list();
	print_inventory(add);

	int car_id;

	printf("Enter the car ID you want to delete:");
	scanf("%d", &car_id);

	car *head = delete_car(add, car_id);

	printf("updated car inventory is: \n");
	print_inventory(head);

	car *add_car = add_car_to_list(head);
	print_inventory(add_car);




	return 0;
}

