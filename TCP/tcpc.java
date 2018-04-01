import java.io.*;
import java.net.*;
public class tcpc{
		public static void main(String[] args) throws Exception{
			Socket sock=new Socket("127.0.0.1",8000);
			BufferedReader keyRead= new BufferedReader(new InputStreamReader(System.in));
			OutputStream ostream=sock.getOutputStream();
			PrintWriter pwrite=new PrintWriter(ostream,true);
			InputStream istream=sock.getInputStream();
			BufferedReader recieveRead=new BufferedReader(new InputStreamReader(istream));

			String recieveMessage,sendMessage;
			while(true){
				sendMessage=keyRead.readLine();
				pwrite.println(sendMessage);
				pwrite.flush();
				if((recieveMessage=recieveRead.readLine())!=null){
					System.out.println(recieveMessage);
				}
			}
			
		}
}