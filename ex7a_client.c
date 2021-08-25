/*
* ex7a.c - Client
*
*
*  Created on: Dec 24, 2017
*      Author: eliyho tsuri, Dan Narkisi
*       Login: eliyhots , danna
*		    Id: 201610672, 301680435
*
*  Client processes:
*  sand to the server the operation and the argument 
*  and print the answer of the server 
*
*/
// ------------------- Include Section -----------------------
#include <stdio.h>
#include "/usr/include/rpc/rpc.h"
#include "rpc_gen.h"
// ------------------------ Main -----------------------------
int main(int argc, char** argv)
{
	CLIENT *cl;
	int *result_nums;
	int *result_pali, not;
	char *server, *message;
	double val, *dresult;

	if (argc != 3)
	{
		fprintf(stderr, "usage: %s <host> <string>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	server = argv[1];
	message = argv[2];

	cl = clnt_create(server, REMOTE_PROG, MESSAGEVERSS, "tcp");
	if (cl == NULL)
	{
		clnt_pcreateerror(server);
		exit(EXIT_FAILURE);
	}

	if (message[0] == '1')
	{
		result_pali = my_pali_1(&message, cl);
		if (result_pali == NULL)
		{
			clnt_perror(cl, server);
			exit(EXIT_FAILURE);
		}
		if (result_pali == 0)
			puts("The string is not palindrom\n");
		else
			puts("The string is palindrom\n");
	}

	else if (message[0] == '2')
	{
		sscanf(message, "%d %lf", &not, &val);
		dresult = my_sqrt_1(&val, cl);
		if (dresult == NULL)
		{
			clnt_perror(cl, server);
			exit(EXIT_FAILURE);
		}
		printf("The squared of the number is: %f\n", (float)*dresult);
	}
	else if (message[0] == '3')
	{
		result_nums = my_oper_1(&message, cl);
		if (result_nums == NULL)
		{
			clnt_perror(cl, server);
			exit(EXIT_FAILURE);
		}
		printf("Operation of %s equals %d\n", message, *result_nums);
	}
	else if (message[0] == '0')
	{
		puts("Client end the program\n");
		exit(EXIT_SUCCESS);
	}
	clnt_destroy(cl);


	exit(EXIT_SUCCESS);
}
//---------------------------------------------------
