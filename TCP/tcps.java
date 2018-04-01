import java.io.*;
import java.net.*;
public class tcps{
		public static void main(String[] args) throws Exception{
			ServerSocket sersock=new ServerSocket(8000);
			Socket sock=sersock.accept();
			BufferedReader keyRead= new BufferedReader(new InputStreamReader(System.in));
			OutputStream ostream=sock.getOutputStream();
			PrintWriter pwrite=new PrintWriter(ostream,true);
			InputStream istream=sock.getInputStream();
			BufferedReader recieveRead=new BufferedReader(new InputStreamReader(istream));

			String recieveMessage,sendMessage;
			while(true){
				if((recieveMessage=recieveRead.readLine())!=null){
					System.out.println(recieveMessage);
				}
				sendMessage=keyRead.readLine();
				pwrite.println(sendMessage);
				pwrite.flush();
			}
		}
}