import socket

def socket_server():
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as server_socket:
        server_socket.bind(("127.0.0.1", 1111))
        server_socket.listen()

        client_socket, client_addr = server_socket.accept()
        while True:
            msg = client_socket.recv(1024)
            if msg == b'exit': return
            client_socket.sendall(msg)
