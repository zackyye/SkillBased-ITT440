import socket
import threading
import random

# List of quotes
quotes = [
    "Don’t let yesterday take up too much of today.~ Will Rogers",
    "We need much less than we think we need.~ Maya Angelou",
    "Nothing is impossible",
    "Know that whatever you're going through, it is all temporary",
    "Whatever you are, be a good one. ~ Abraham Lincoln",
    "Don't cry because it's over, smile because it happened.",
    "If things go wrong, don’t go with them. ~ Roger Babson",
    "To be yourself in a world that is constantly trying to make you something else is the greatest accomplishment. ~ Ralph Waldo Emerson",
    "Success is not final, failure is not fatal: It is the courage to continue that counts",
    "Be the change, you wish to see"
]

def handle_client(client_socket):
    # Send a random quote to the client
    quote = random.choice(quotes)
    client_socket.sendall(quote.encode())

    # Close the client socket
    client_socket.close()

def main():
    host = "192.168.9.129"
    port = 8888

    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind((host, port))
    server_socket.listen(5)

    print("Server is listening for incoming connections...")

    while True:
        client_socket, client_address = server_socket.accept()
        print(f"Connected to {client_address}")

        # Create a new thread to handle the client
        client_thread = threading.Thread(target=handle_client, args=(client_socket,))
        client_thread.start()

if __name__ == "__main__":
    main()
