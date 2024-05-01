/*
Especificacao dos procedimentos do RPC
soma - soma dois numeros
mult - multiplica dois numeros
Este arquivo eh a entrada do rpcgen
*/ 

/* struct para entradas */
struct in{
    int in1;
    int in2;
};

program MEU_RPC_SERVER {   /*Nome do Programa remoto*/
    version CALCULADORA {  /* Declaracao do numero da versao do programa*/
        int soma(in) = 1;  /* procedimento numero = 1 */
	    int mult(in) = 2;  /* procedimento numero = 2 */
    } = 1;	           /* definicao da versao do programa = 1*/
} = 0x3012225;	           /* numero do programa remoto (deve ser unico)*/
