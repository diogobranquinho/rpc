# Calculadora RPC em C

Este projeto implementa uma calculadora simples usando RPC (Remote Procedure Call) em C. O servidor oferece operações de soma e multiplicação que podem ser acessadas remotamente pelo cliente.

## Alerta!!!!

Este exemplo não funciona mais nas versões de linux atuais. As bibliotecas tradicionais do RPC foram removidas das novas versões do Linux. Versões funcionais Ubuntu 16.04

## Pré-requisitos

Certifique-se de que o serviço RPC está instalado e funcionando no sistema operacional.

### Verificação do serviço RPC

Para verificar se o serviço RPC está ativo, utilize o seguinte comando:

```bash
rpcinfo
```

### Instalação do Serviço RPC

Caso o serviço RPC não esteja instalado, você pode instalá-lo com os seguintes comandos:

```bash
sudo apt-get update
sudo apt-get install rpcbind
```

## Compilação dos Programas

Siga a ordem abaixo para gerar os executáveis do cliente e do servidor a partir dos arquivos de código fonte.

### Geração de Stubs RPC

Primeiro, gere os stubs, o código XDR e os arquivos de cabeçalho usando `rpcgen`:

```bash
rpcgen calc.x
```

### Compilação dos Arquivos Gerados e Fontes

Compile os arquivos gerados e os arquivos de implementação do cliente e servidor:

```bash
gcc -c calc_clnt.c
gcc -c calc_svc.c
gcc -c calc_xdr.c
gcc -c rpcClient.c
gcc -c rpcServer.c
```

### Linkagem dos Objetos

Link os arquivos de objeto para criar os executáveis do cliente e do servidor:

```bash
gcc -o client calc_clnt.o calc_xdr.o rpcClient.o
gcc -o server calc_svc.o calc_xdr.o rpcServer.o
```

## Execução

Para iniciar o servidor e o cliente, siga os passos abaixo. Certifique-se de substituir `127.0.0.1` pelo endereço IP adequado se estiver em uma rede.

### Servidor

Em um terminal, execute o servidor especificando o IP:

```bash
./server 127.0.0.1
```

### Cliente

Em outro terminal ou em outro computador na mesma rede, execute o cliente também especificando o IP:

```bash
./client 127.0.0.1
```

## Estrutura do Projeto

O projeto inclui os seguintes arquivos:

- `calc.x`: Arquivo de definição do RPC.
- `rpcClient.c`: Código fonte do cliente RPC.
- `rpcServer.c`: Código fonte do servidor RPC.
- `README.md`: Instruções de instalação, compilação e execução.