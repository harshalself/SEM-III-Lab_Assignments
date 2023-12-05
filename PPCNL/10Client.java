// NAME : HARSHAL PATIL
// ROLL NO : 44 

import java.io.*;
import java.net.*;

public class Client {
    public static void main(String[] args) {
        final String SERVER_ADDRESS = "localhost";
        final int PORT = 12345;

        try (Socket socket = new Socket(SERVER_ADDRESS, PORT);
             PrintWriter out = new PrintWriter(socket.getOutputStream(), true);
             BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()))
        ) {
            // Example: Say Hello
            out.println("HELLO");
            System.out.println("Server response: " + in.readLine());

            // Example: File Transfer
            out.println("FILE");
            System.out.println("Server response: " + in.readLine());

            // Example: Calculator
            out.println("CALCULATOR");
            System.out.println("Server response: " + in.readLine());

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
