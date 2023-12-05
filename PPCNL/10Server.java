// NAME : HARSHAL PATIL
// ROLL NO : 44 

import java.io.*;
import java.net.*;

public class Server {
    public static void main(String[] args) {
        final int PORT = 12345;

        try (ServerSocket serverSocket = new ServerSocket(PORT)) {
            System.out.println("Server is listening on port " + PORT);

            while (true) {
                Socket clientSocket = serverSocket.accept();
                System.out.println("Client connected: " + clientSocket.getInetAddress());

                // Handle client request in a new thread
                Thread clientHandler = new Thread(() -> handleClient(clientSocket));
                clientHandler.start();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static void handleClient(Socket clientSocket) {
        try (
            PrintWriter out = new PrintWriter(clientSocket.getOutputStream(), true);
            BufferedReader in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()))
        ) {
            String clientMessage;
            while ((clientMessage = in.readLine()) != null) {
                System.out.println("Received from client: " + clientMessage);

                // Handle different functionalities
                if (clientMessage.equals("HELLO")) {
                    out.println("Server says: Hello!");
                } else if (clientMessage.equals("FILE")) {
                    // Handle file transfer (you'll need additional logic here)
                    out.println("Server: File transfer functionality not implemented.");
                } else if (clientMessage.equals("CALCULATOR")) {
                    // Handle calculator functionality
                    out.println("Server: Calculator functionality not implemented.");
                } else {
                    out.println("Server: Unknown command.");
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            try {
                clientSocket.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
}
