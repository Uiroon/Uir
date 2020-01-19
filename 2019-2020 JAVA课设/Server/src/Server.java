import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;

public class Server extends Thread {
	private ServerSocket ss = null;
	private Socket s = null;
	private String userName = new String("null");
	private ArrayList<String> novelName = new ArrayList<String>();
	private String path = new String("novel");
	private String defaultPath = new String("pic/");

	public Server() {
		try {
			System.out.println("����������е�С˵Ŀ¼��");
			File library = new File(path);
			File novels[] = library.listFiles();
			for (int i = 0; i < novels.length; i++) {
				File tmp = novels[i];
				if (!tmp.isDirectory()) { // �ж��ǲ���һ���ļ���
					novelName.add(tmp.getName());
				}
			}
			for (int i = 0; i < novelName.size(); i++)
				System.out.println(novelName.get(i));
			ss = new ServerSocket(9988);
			System.out.println(ss.getLocalPort() + "�����������ɹ�");
			while (true) {
				s = ss.accept();
				System.out.println(s.getRemoteSocketAddress() + "���ӳɹ�");
				new Thread(this).start();
			}
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	@Override
	public void run() {
		try {
			while (true) {
				InputStream is = s.getInputStream();
				OutputStream os = s.getOutputStream();
				byte[] bt = new byte[1024];
				int len = is.read(bt);
				String tmp = new String(bt, 0, len);
				String msg[] = tmp.split("#");
				String request = msg[1];
				System.out.println(tmp);
				if (request.equals("��ȡС˵")) {
					File chosen = new File(path + "/" + msg[2]);
					FileInputStream fis = new FileInputStream(chosen);
					os.write(("SENDFROMSERVER#" + chosen.length() + "#" + chosen.getName()).getBytes());
					this.sleep(100);
					while ((len = fis.read(bt)) != -1) {
						os.write(bt, 0, len);
						os.flush();
					}
					fis.close();
				} else if (request.equals("����ͼƬ")) {
					FileOutputStream fos = new FileOutputStream(new File(defaultPath + msg[3]));

					long totalLenth = Long.parseLong(msg[2]);
					long lenth = 0;
					bt = new byte[1024];
					while (lenth != totalLenth) {
						len = is.read(bt);
						fos.write(bt, 0, len);
						fos.flush();
						lenth += len;
					}
					fos.close();

				} else if (request.equals("�����û���")) {
					userName = msg[2];
					System.out.println(userName + "�Ѿ�����");
				} else if (request.equals("��ȡ��������С˵Ŀ¼")) {
					os.write(("SENDFROMSERVER#" + novelName.size()).getBytes());
					this.sleep(100);
					for (int i = 0; i < novelName.size(); i++) {
						os.write(novelName.get(i).getBytes());
						this.sleep(100);
					}
				}
			}
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} finally {
			try {
				ss.close();
				s.close();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	}

	public static void main(String[] args) {
		new Server();
	}
}