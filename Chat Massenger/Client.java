import java.io.*;
import java.net.*;

public class Client {
    public static void main(String Args[]) throws Exception {
        System.out.println("Client of Chat messanger is runnig...");

        Socket sobj = new Socket("LocalHost", 2100);
        // System.out.println("Client is waiting for server to accept the request...");

        PrintStream ps = new PrintStream(sobj.getOutputStream());

        BufferedReader br1 = new BufferedReader(new InputStreamReader(sobj.getInputStream()));

        BufferedReader br2 = new BufferedReader(new InputStreamReader(System.in));

        System.out.println("Chat Massenger Started");

        String str1, str2;

        while (!(str1 = br2.readLine()).equals("end"))

        {
            ps.println(str1);

            str2 = br1.readLine();
            System.out.println("Server Says: " + str2);
            System.out.println("Enter message for server: ");

        }
        System.out.println("Theank you for using Chat messanger...");

        sobj.close();
        ps.close();
        br1.close();
        br2.close();

    }
}

// javac Client.java