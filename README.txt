 ============================================ 
* ex7a_server.c - Server
*
*  Created on: Dec 24, 2017
*      Author: eliyho tsuri, Dan Narkisi
*       Login: eliyhots , danna
*		    Id: 201610672, 301680435
description:
*  Server processes:
*  getting command and arguments for do misson
*  return to the client the answer 
Compile: gcc -Wall ex7a_server.c -o ex7a_server 
Run: ex7a_server.out

Input: not input 
Output : not Output 
 ============================================ 
* ex7a.c_client - Client
*
*
*  Created on: Dec 24, 2017
*      Author: eliyho tsuri, Dan Narkisi
*       Login: eliyhots , danna
*		    Id: 201610672, 301680435
*
*  

description:
  Client processes:
*  sand to the server the operation and the argument 
*  and print the answer of the server 

 
Compile: gcc -Wall ex7a.c_client.c -o ex7a.c_client 
Run: ex7a.c_client.out

Input: not input 
Output : not Output
 ============================================  
compile this project:
rpcgen rpc_gen.x
gcc rpc_gen_svc.c server.c -lm -o server
gcc rpc_gen_clnt.c client.c -o client

run:
./server&
./client localhost "1 <string>"
./client localhost "2 <number>"
./client localhost "3 <operation (+,-,*,/) and 2 numbers>"


הערה לבודק :
לגבי האזהרות שישנן בתכנית, אין מה לעשות איתם ואותן אזהרות מופיעות גם בדוגמה המובאת בספר של יורם.

ולכן אבקש לא להוריד נקודות על כך,
תודה על ההבנה.
