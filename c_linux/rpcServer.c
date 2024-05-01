/*********************************************************************/
/* rpcServer.c - remote procedures; called by server stub */
#include <stdio.h>
#include <stdlib.h>
#include <rpc/rpc.h>
#include "calc.h"

int *soma_1_svc(in *arg1, struct svc_req *arg2)
{
    static int res;
    printf("Uma operacao de soma foi executada\n\r");
    res = arg1->in1 + arg1->in2;
    return (&res);
}

int *mult_1_svc(in *arg1, struct svc_req *arg2)
{
    static int res;
    printf("Uma operacao de multiplicacao foi executada\n\r");
    res = arg1->in1 * arg1->in2;
    return (&res);
}
