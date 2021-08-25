/*
* ex7a.c - Server
*
*  Created on: Dec 24, 2017
*      Author: eliyho tsuri, Dan Narkisi
*       Login: eliyhots , danna
*		    Id: 201610672, 301680435
*
*  Server processes:
*  getting command and arguments for do misson
*  return to the client the answer
*
*/
// ------------------- Include Section -----------------------
#include <math.h>
#include <stdio.h>
#include "/usr/include/rpc/rpc.h"
#include <string.h>
#include "rpc_gen.h"
//--------------------- my_pali_1_svc ------------------------
/*
* getting string on the message and return if the string palindrom
*/
int *my_pali_1_svc(char** msg, struct svc_req *foo)
{
	static int answer;
	char *str;
	static int no = 0;
	static int yes = 1;
	sscanf(*msg, "%d %s", &no, &*str);
	printf("in the server: string = %s \n", str);

	int start = 0;
	int end = strlen(str);

	answer = no;
	while (start < end)
	{
		if (str[start] != str[end])
		{
			answer = no;
			break;
		}
		start++;
		end--;
	}
	return (&answer);
}
//--------------------- my_sqrt_1_svc ------------------------
/*
* getting number on the message and return the squared of number
*/
double *my_sqrt_1_svc(double *x, struct svc_req *foo)
{
	static double *result;

	result = x;
	printf("in the server: number = %lf \n", *x);

	*result *= *result;
	return (&*result);
}
//--------------------- my_oper_1_svc ------------------------
/*
* getting char operation and 2 numbers on the message
* and return the operation whit the two numbers
*/
int *my_oper_1_svc(char** msg, struct svc_req *foo)
{
	static int result_nums;
	int n1 = 0, n2 = 0;
	char operation = '\0';
	char not = '\0';
	sscanf(*msg, "%c %c %d %d", &not , &operation, &n1, &n2);
	printf("in the server: n1 = %d, n2 = %d\n", n1, n2);


	if (operation == '+')
		result_nums = n1 + n2;

	else if (operation == '-')
	{
		if (n1 >= n2)
			result_nums = n1 - n2;
		else
			result_nums = n2 - n1;
	}
	else if (operation == '*')
		result_nums = n1 * n2;
	else if (operation == '/')
	{
		if (n1 >= n2)
			result_nums = n1 / n2;
		else
			result_nums = n2 / n1;
	}
	return (&result_nums);
}
//----------------------------------------------
