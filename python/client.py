import grpc
import calc_pb2
import calc_pb2_grpc

def run():
    with grpc.insecure_channel('localhost:50051') as channel:
        stub = calc_pb2_grpc.CalculadoraStub(channel)
        while True:
            print("\nEscolha a operação:")
            print("1 - Soma")
            print("2 - Multiplicação")
            print("3 - Sair")
            operacao = int(input("Opção: "))

            if operacao == 3:
                print("Encerrando cliente...")
                break
            
            num1 = int(input("Digite o primeiro número: "))
            num2 = int(input("Digite o segundo número: "))

            if operacao == 1:
                resposta = stub.soma(calc_pb2.parametrosCalculo(in1=num1, in2=num2))
                print(f"Resultado da soma: {resposta.result}")
            elif operacao == 2:
                resposta = stub.multiplica(calc_pb2.parametrosCalculo(in1=num1, in2=num2))
                print(f"Resultado da multiplicação: {resposta.result}")

if __name__ == '__main__':
    run()
