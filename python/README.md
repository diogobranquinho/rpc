# Calculadora RPC em Python com gRPC

Este projeto demonstra a implementação de um serviço RPC para uma calculadora que realiza operações de soma e multiplicação. Utiliza gRPC, um framework de chamada de procedimento remoto de alto desempenho e independente de linguagem.

## Requisitos

- Python 3.6 ou superior
- gRPC Python
- Protocol Buffers

## Configuração do Ambiente

### Instalação do Python

Certifique-se de que o Python 3.6 ou superior está instalado no seu sistema. Você pode verificar a versão do Python com o seguinte comando:

```bash
python --version
```

Caso o Python não esteja instalado, você pode baixá-lo e instalá-lo a partir do [site oficial do Python](https://www.python.org/downloads/).

### Instalação de Dependências

Instale o gRPC e as ferramentas do Protocol Buffers usando o `pip`:

```bash
pip install grpcio grpcio-tools
```

## Geração de Código a partir do Arquivo `.proto`

Gere os arquivos Python necessários a partir da definição do serviço no arquivo `calc.proto` usando o seguinte comando no diretório do projeto:

```bash
python -m grpc_tools.protoc -I. --python_out=. --grpc_python_out=. calc.proto
```

Este comando produzirá `calc_pb2.py` e `calc_pb2_grpc.py`.

## Implementação do Servidor

O servidor é implementado no arquivo `server.py`. Para iniciar o servidor, execute o seguinte comando no terminal:

```bash
python server.py
```

Este servidor estará ouvindo solicitações no endereço `localhost` na porta `50051`.

## Implementação do Cliente

O cliente é implementado no arquivo `client.py`. Para interagir com o servidor, execute o seguinte comando em um novo terminal:

```bash
python client.py
```

O cliente apresentará um menu interativo para escolher entre realizar uma soma, uma multiplicação ou sair.

## Estrutura do Projeto

O projeto contém os seguintes arquivos:

- `calc.proto`: Arquivo de definição do Protocol Buffers para o serviço RPC.
- `server.py`: Implementação do servidor gRPC.
- `client.py`: Implementação do cliente gRPC que interage com o servidor.
- `README.md`: Este arquivo, que fornece instruções sobre como configurar, compilar e executar a aplicação.