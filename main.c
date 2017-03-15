#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

const int METERS_TO_CM = 100;

int ferry_boat_trial(void);
void buffclear(void);

int main(int argc, char* argv[])
{
	int number_of_trials = 0;
	int i = 0;

	scanf(" %d", &number_of_trials);
	buffclear();

	for (i = 0; i < number_of_trials; i++)
	{
		printf("%d\n", ferry_boat_trial());
	}
	return 0;
}

int ferry_boat_trial(void)
{ 
	QUEUE* hQueue_Left;
	QUEUE* hQueue_Right;

	int length;
	int length_count;
	int number_of_cars;
	int crosses = 0;
	int i = 0;
	int car_length = 0;
	char car_side;

	hQueue_Left = queue_init_default();
	hQueue_Right = queue_init_default();

	scanf(" %d%d", &length, &number_of_cars);
	buffclear();
	length_count = length;
	length = length * METERS_TO_CM;
	length_count = length_count * METERS_TO_CM;

	for (i = 0; i < number_of_cars; i++)
	{
		scanf(" %d %c", &car_length, &car_side);
		buffclear();
		if (car_side == 'r' || car_side == 'R')
		{
			queue_enqueue(hQueue_Right, car_length);
		}
		else if (car_side == 'l' || car_side == 'L')
		{
			queue_enqueue(hQueue_Left, car_length);
		}
	}

	while (!queue_empty(hQueue_Left) && !queue_empty(hQueue_Right))
	{
		while (queue_front(hQueue_Left, NULL) < length)
		{
			length = length - queue_front(hQueue_Left, NULL);
			queue_service(hQueue_Left);
		}

		length = length_count;
		while (queue_front(hQueue_Right, NULL) < length)
		{
			length = length - queue_front(hQueue_Right, NULL);
			queue_service(hQueue_Right);
		}

		length = length_count;
		crosses = crosses + 2;
	}
	while (!queue_empty(hQueue_Left))
	{
		while (queue_front(hQueue_Left, NULL) < length)
		{
			length = length - queue_front(hQueue_Left, NULL);
			queue_service(hQueue_Left);
		}
		crosses++;
		if (!queue_empty(hQueue_Left))
		{
			crosses++;
		}
		length = length_count;
	}
	while (!queue_empty(hQueue_Right))
	{
		while (queue_front(hQueue_Right, NULL) < length)
		{
			length = length - queue_front(hQueue_Right, NULL);
			queue_service(hQueue_Right);
		}
		crosses++;
		crosses++;
		length = length_count;
	}
	queue_destroy(&hQueue_Left);
	queue_destroy(&hQueue_Right);
	return crosses;
}

void buffclear(void)
{
	char z;
	scanf("%c", &z);
	while (z != '\n')
	{
		scanf("%c", &z);
	}
	return;
}