import socket
import threading
import json

class LittleHollandDaemon:
    def __init__(self, config):
        self.config = config
        self.server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.server_socket.bind((self.config['host'], self.config['port']))
        self.server_socket.listen(5)
        self.connections = []

    def start(self):
        print("Daemon started, waiting for connections...")
        while True:
            client_socket, addr = self.server_socket.accept()
            print(f"Connection from {addr}")
            self.connections.append(client_socket)
            threading.Thread(target=self.handle_client, args=(client_socket,)).start()

    def handle_client(self, client_socket):
        while True:
            data = client_socket.recv(1024)
            if not data:
                break
            self.process_data(data)
        client_socket.close()

    def process_data(self, data):
        session_data = json.loads(data.decode('utf-8'))
        session_id = session_data['session_id']
        data_type = session_data['data_type']
        raw_data = session_data['raw_data']
        self.store_data(session_id, data_type, raw_data)

    def store_data(self, session_id, data_type, raw_data):
        file_name = f"{session_id}_{data_type}.bin"
        with open(file_name, 'wb') as file:
            file.write(raw_data.encode('utf-8'))
        print(f"Stored data in {file_name}")

if __name__ == "__main__":
    config = {
        'host': '0.0.0.0',
        'port': 8000
    }
    daemon = LittleHollandDaemon(config)
    daemon.start()
