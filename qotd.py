import socket

def main():
    host = "192.168.9.129"
    port = 8888

    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client_socket.connect((host, port))
    print("Welcome to QOTD server!")

    # Receive the quote from the server
    quote = client_socket.recv(1024).decode()

    print("\nQuote of the Day:")
    print(quote)

    # Close the client socket
    client_socket.close()

if __name__ == "__main__":
    main()
