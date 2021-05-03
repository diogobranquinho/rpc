/****************************************************************/
/* rpcClient.c - client program for remote date service */
#include <stdio.h>
#include <rpc/rpc.h>
#include <stdlib.h>
#include "calc.h"

int main(int argc, char *argv[])
{
  CLIENT *con;
  char *server;

  struct in val;
  int *res;
  int op;

  if (argc != 2)
  {
    fprintf(stderr, "usage: %s hostname\n", argv[0]);
    exit(1);
  }

  server = argv[1];
  /* create client handle */
  if ((con = clnt_create(server, MEU_RPC_SERVER, CALCULADORA, "udp")) == NULL)
  {
    /* couldn't establish connection with server */
    printf("can't establish connection with host %s\n", server);
    exit(2);
  }

  do
  {
    printf("\n\r*** Menu ***\n\r");
    printf("1 - Somar\n\r");
    printf("2 - Multiplicar\n\r");
    printf("3 - Sair\n\r");
    scanf("%d", &op);

    if (op == 1)
    {
      printf("-->Somar\n\r");
      printf("Val1 ");
      scanf("%d", &val.in1);
      printf("Val2 ");
      scanf("%d", &val.in2);
      // chamando o procedimentl remoto
      res = soma_1(&val, con);
      if (res == NULL)
        printf("a conexao falhou...");
      else
        printf("Resultado=%d\n\r", *res);
    }
    else if (op == 2)
    {
      printf("-->Multiplicar\n\r");
      printf("Val1 ");
      scanf("%d", &val.in1);
      printf("Val2 ");
      scanf("%d", &val.in2);
      // chamando o procedimentl remoto
      res = mult_1(&val, con);
      if (res == NULL)
        printf("a conexao falhou...");
      else
        printf("Resultado=%d\n\r", *res);
    }
  } while (op != 3);
  clnt_destroy(con); /* done with handle */
  return 0;
}
