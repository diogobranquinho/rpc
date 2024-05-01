from concurrent import futures
import grpc
import calc_pb2
import calc_pb2_grpc

class CalculadoraServicer(calc_pb2_grpc.CalculadoraServicer):
    def soma(self, request, context):
        resultado = request.in1 + request.in2
        return calc_pb2.resultadoCalculo(result=resultado)

    def multiplica(self, request, context):
        resultado = request.in1 * request.in2
        return calc_pb2.resultadoCalculo(result=resultado)

def serve():
    server = grpc.server(futures.ThreadPoolExecutor(max_workers=10))
    calc_pb2_grpc.add_CalculadoraServicer_to_server(CalculadoraServicer(), server)
    server.add_insecure_port('localhost:50051')
    server.start()
    server.wait_for_termination()

if __name__ == '__main__':
    serve()
