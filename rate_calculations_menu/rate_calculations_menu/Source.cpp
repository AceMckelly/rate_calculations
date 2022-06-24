#include <stdio.h>

// Rate Calculations.cpp : Defines the entry point for the console application.
//
//This program is designed to do basic rate calculation for Beaches resorts


//This function determines the cost of a number of nights 
float cost_of_nights(int a, float b){
	float promo[365]; //This float retrieves the percentage promotion per night
	float per_off;
	float pnr[365];//This float determines the cost of each night
	float rmg = 0; //This float determines stores the cost of the number of nghtd

	//This will calculate the cost of each night and add the total 
	for (int i = 1; i <= a; i++){
		printf ("Enter the percentage promotion for night number %d \n", i);
		scanf("%lf",&promo[i]);
		per_off = (100 - promo[i]) / 100;
		pnr[i] = b * per_off;
		rmg = rmg + pnr[i];
	}
	return rmg;
}

//This function is used to remove the number of nights
float removing_nights(){
	int nights;
	float rack_rate;
	float pnrack_r;//per night rack rate
	printf("---------------Removing Nights-------------------\n");
	printf("Enter the number of nights ");
	scanf("%d",&nights);
	printf("Enter the rack rate\n");
	scanf("%lf",&rack_rate);
	pnrack_r = rack_rate / nights;
	return cost_of_nights(nights, pnrack_r);
}


//This function adds a number of nights
float adding_nights(){
	float rmg = 0;
	int added_nights;
	float rack_rate;
	float pnrack_r; //per night rack rate
	float addnights = 0;
	printf("---------------Adding Nights-------------------\n");
	printf ("Enter the current room gross");
	scanf("%lf",rmg);
	printf("Enter the number of added nights ");
	scanf("%d",&added_nights);
	printf ("Enter the new rack rate \n");
	scanf("%lf",&rack_rate);
	pnrack_r = rack_rate / added_nights;
	addnights = cost_of_nights(added_nights, pnrack_r);
	rmg = rmg + addnights;
	return rmg;
}

//This function adds or removes children to a current room gross
float children(int a){
	int no_of_children = 0;
	int nights;
	float child_rack = 135;
	float rmg;
	float child_nights = 0;
	float children_nights = 0;
	if (a == 1)
		printf("---------------Adding Children-------------------\n");
	else
		printf("---------------Removing Children-------------------\n");
	printf ("Enter the current room gross ");
	scanf("%lf",&rmg);
	printf("Enter the number of nights ");
	scanf("%d",&nights);
	printf("Enter the number of children");
	scanf("%d",&no_of_children);
	if (no_of_children == 0)
		return rmg;
	child_nights = cost_of_nights(nights, child_rack);
	children_nights = child_nights * no_of_children;
	if (a == 1)
		rmg = rmg + children_nights;
	else
		rmg = rmg - children_nights;
	return rmg;
}


//This function adds or removes adults to the current room gross
float adults(int a){
	int no_of_adults = 0;
	int nights;
	float adult_rack = 195;
	float rmg;
	float adult_nights = 0;
	float adults_nights = 0;
	if (a == 1)
		printf ("---------------Adding Adults-------------------\n");
	else
		printf("---------------Removing Adults-------------------\n");
	printf ("Enter the current room gross ");
	scanf("%lf",&rmg);
	printf ("Enter the number of nights ");
	scanf("%d",&nights);
	printf ("Enter the number of adults ");
	scanf("%d",&no_of_adults);
	if (no_of_adults == 2)
		return rmg;
	if (a == 1){
		adult_nights = cost_of_nights(nights, adult_rack);
		adults_nights = adult_nights * (no_of_adults - 2);
		rmg = rmg + adults_nights;
	}
	else if (a == 2){
		printf ("How many adults would you be removing? ");
		scanf("%d",&no_of_adults);
		adult_nights = cost_of_nights(nights, adult_rack);
		adults_nights = adult_nights * (no_of_adults);
		rmg = rmg - adults_nights;
	}
	return rmg;
}

//This function calculates the rm gross if there is a single adult in the room 2 will add adults 1 will remove adults
float sing_adult(int a){
	float rmg = 0;
	rmg = children(2);
	printf ("New room gross w\o kids %.2lf \n", rmg);
	if (a == 1){
		rmg = adults(2);
		printf("New room gross w\o extra adults %.2lf \n", rmg);
		rmg = rmg / 2;
		printf("One adult w\o sing suppliment %.2lf \n", rmg);
		rmg = rmg * 1.5;
		printf("One adult with sing suppliment %.2lf \n", rmg);
	}
	else if (a == 2){
		rmg = rmg / 1.5;
		printf("One adult w\o sing suppliment %.2lf \n", rmg);
		rmg = rmg * 2;
		printf("Cost of two adults %.2lf \n", rmg);
	}
	rmg = children(1);
	printf("New room gross with two adults and children %.2lf \n", rmg);
	if (a == 2)
		rmg = adults(1);
	return rmg;
}

float mildis(int a){
	float rmg = 0;
	float insav = 0;
	float ssgdis = 0;
	float rmnt = 0;
	float mildisc = 0;
	printf ("Enter the room gross ");
	scanf ("%lf",&rmg);
	printf ("Enter the instant savings ");
	scanf ("%lf",&insav);
	printf("Enter the Sandals Select Discount ");
	scanf("%lf",&ssgdis);
	if (a == 1){
		printf ("------------------Adding Military Discount------------------------\n");
		rmnt = rmg - (insav + ssgdis);
		mildisc = rmnt * 0.1;
		rmg = rmg - mildisc;
	}
	else{
		printf ("------------------Removing Military Discount------------------------\n");
		rmg = rmg / 0.9;
		rmg = rmg + insav + ssgdis;
	}
	return rmg;
}


int main()
{
	float rmg = 0;
	float addnights = 0;
	int choice = 0;
	printf ( "What would you like to do?\n");
	printf ( "1 Add nights\n2 Remove nights\n3 Adding children\n4 Adding adults\n5 Removing Children\n6 Removing Adults\n7 Adding Single Supplement\n8 Removing Single Supplement\n");
	printf ("9 Add Military Discount\n10 Remove Military Discount\n");
	scanf ("%d",&choice);
	switch (choice){
	case 1:
			rmg = adding_nights();
			break;
	case 2:
			rmg = removing_nights();
			break;
	case 3:
			rmg = children(1);
			break;
	case 4:
			rmg = adults(1);
			break;
	case 5:
			rmg = children(2);
			break;
	case 6:
			rmg = adults(2);
			break;
	case 7:
			rmg = sing_adult(1);
			break;
	case 8:
			rmg = sing_adult(2);
			break;
	case 9:
			rmg = mildis(1);
			break;
	case 10:
			rmg = mildis(2);
			break;
	default:
			printf("No input was recieved\n");
			getchar();
			return 0;
	}
	printf("New Room Gross %.2lf\n", rmg);
	getchar();
	return 0;
}

