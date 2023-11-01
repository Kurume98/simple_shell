#include "main.h"
#include <stdio.h>

/**
 * main - show the legal age for marriage
 *
 * Return: 0 for success
 */
int main(void)
{
	int age;

	printf("Enter your age: ");
	scanf("%d", &age);

	if (age >= legal_marriage_age)
	{
		printf("You are of legal age to get married.\n");
	}
	else
	{
		printf("You are not of legal age to get married.\n");
	}

	return (0);
}
