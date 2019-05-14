/*
 * carinfo.h
 *
 *  Created on: Mar 8, 2019
 *      Author: sumit
 */

#ifndef CARINFO_H_
#define CARINFO_H_

#include <stdio.h>

typedef struct secretInfo
{
	char repair[3];
	float loan;
}secret_info;

typedef struct car_info
{
	int id;
	char name [6];
	float price;
	secret_info *internal_info;
	struct car_info *next;
}car;


car *init_car(int id, char *name, float price, char *repair, float loan);


void print_inventory(car *carptr);

car *create_car_list();

car *add_car_to_list(car *head);

car *search_car(car *head, int car_id);

car *delete_car(car *head, int id);

float loan_calculation(float car_price);






#endif /* CARINFO_H_ */
