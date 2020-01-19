import java.awt.Color;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.Socket;
import java.util.ArrayList;

import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;

public class Login extends JFrame implements ActionListener, ItemListener {

	public static Socket st = null;

	private JPanel jp = new JPanel();

	private JButton jbt1 = new JButton("连接服务器");
	private JButton jbt2 = new JButton("下载小说");
	private JButton jbt3 = new JButton("进入分析");
	private JButton jbt4 = new JButton("获取目录");

	private JLabel cover = new JLabel();

	//界面状态变量，用于功能使用时的进一步确认
	private boolean isConnected = false;
	private boolean isDownload = false;

	private String userName = new String("null");
	private String chosenNovel = new String("null");//选择下载的小说名
	public static String pathofCover =new String("cover.png");
	private String defaultPath = new String("novel/");//小说保存路径

	private ArrayList<String> novelName = new ArrayList<String>();//从服务器获取的所有小说名
	private JComboBox<String> jcb = new JComboBox<String>();//选择下载的小说


	public Login() {
		jp.setLayout(null);
		Font fontButton = new Font("黑体", 0, 20);
		Font fontCB = new Font("黑体", 0, 18);
		cover.setSize(1080, 496);
		cover.setLocation(0, 400);
		cover.setIcon(new ImageIcon(pathofCover));


		jcb.setSize(300, 45);
		jcb.setFont(fontCB);
		jcb.setLocation(380, 160);
		jcb.addItemListener(this);
		jcb.setVisible(false);

		// 连接服务器
		jbt1.setSize(200, 60);
		jbt1.setLocation(420, 260);
		jbt1.setFont(fontButton);
		jbt1.setContentAreaFilled(false);
		jbt1.setForeground(new Color(180, 1, 7));
		jbt1.addActionListener(this);
		jbt1.setVisible(true);

		// 下载小说
		jbt2.setSize(200, 60);
		jbt2.setLocation(420, 260);
		jbt2.setFont(fontButton);
		jbt2.setContentAreaFilled(false);
		jbt2.setForeground(new Color(180, 1, 7));
		jbt2.addActionListener(this);
		jbt2.setVisible(false);

		// 进入分析
		jbt3.setSize(200, 60);
		jbt3.setLocation(420, 260);
		jbt3.setFont(fontButton);
		jbt3.setContentAreaFilled(false);
		jbt3.setForeground(new Color(180, 1, 7));
		jbt3.addActionListener(this);
		jbt3.setVisible(false);

		// 获取目录
		jbt4.setSize(200, 60);
		jbt4.setLocation(420, 260);
		jbt4.setFont(fontButton);
		jbt4.setContentAreaFilled(false);
		jbt4.setForeground(new Color(180, 1, 7));
		jbt4.addActionListener(this);
		jbt4.setVisible(false);

		jp.add(cover);
		jp.add(jbt1);
		jp.add(jbt2);
		jp.add(jbt3);
		jp.add(jbt4);
		jp.add(jcb);
		jp.setBackground(Color.WHITE);
		this.setResizable(false);
		this.add(jp);
		this.setSize(1080, 720);
		this.setLocation(400, 200);
		this.setDefaultCloseOperation(EXIT_ON_CLOSE);
		this.setTitle("Loading");
		this.setVisible(true);
	}

	public static void main(String[] args) throws Exception {
		new Login();
	}

	@Override
	public void actionPerformed(ActionEvent e) {
		// TODO Auto-generated method stub
		if (e.getSource() == jbt1) {
			try {
				userName = JOptionPane.showInputDialog("输入用户名", "请输入用户名");
				if (userName.equals("请输入用户名")) {
					userName = "default";
				}
				st = new Socket("127.0.0.1", 9988);
				JOptionPane.showMessageDialog(null, "连接到服务器成功", "提示", JOptionPane.INFORMATION_MESSAGE);
				isConnected = true;
				OutputStream os = st.getOutputStream();
				os.write(("REQUESTFROMCLIENT#设置用户名#" + userName).getBytes());
				jbt1.setVisible(false);
				jbt4.setVisible(true);
			} catch (IOException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}
		} else if (e.getSource() == jbt2) {
			if (chosenNovel.equals("null")) {
				JOptionPane.showMessageDialog(null, "请重新选择需要下载的小说", "提示", JOptionPane.INFORMATION_MESSAGE);
			} else if (isConnected && !chosenNovel.equals("null")) {
				try {
					InputStream is = st.getInputStream();
					OutputStream os = st.getOutputStream();

					os.write(("REQUESTFROMCLIENT#获取小说#" + chosenNovel).getBytes());

					byte[] bt = new byte[1024];
					int len = is.read(bt);
					String tmp = new String(bt, 0, len);
					String[] msg = tmp.split("#");
					System.out.println(tmp);

					FileOutputStream fos = new FileOutputStream(new File(defaultPath + msg[2]));
					if (msg[0].equals("SENDFROMSERVER")) {
						long totalLenth = Long.parseLong(msg[1]);
						long lenth = 0;
						bt = new byte[1024];
						while (lenth != totalLenth) {
							len = is.read(bt);
							fos.write(bt, 0, len);
							fos.flush();
							lenth += len;
						}
						fos.close();
						isDownload = true;
						JOptionPane.showMessageDialog(null, "小说下载完成", "提示", JOptionPane.INFORMATION_MESSAGE);
						jbt2.setVisible(false);
						jbt3.setVisible(true);
					}
				} catch (IOException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}
			}
		} else if (e.getSource() == jbt3) {
			if (isConnected && isDownload) {
				try {
					this.dispose();
					new Manager(defaultPath + chosenNovel);
				} catch (Exception e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}
			}
		} else if (e.getSource() == jbt4) {
			if (isConnected) {
				try {
					InputStream is = st.getInputStream();
					OutputStream os = st.getOutputStream();

					os.write("REQUESTFROMCLIENT#获取服务器端小说目录".getBytes());

					byte[] bt = new byte[1024];
					int len = is.read(bt);
					String tmp = new String(bt, 0, len);
					String[] msg = tmp.split("#");
					System.out.println(tmp);

					if (msg[0].equals("SENDFROMSERVER")) {
						int totalLenth = Integer.parseInt(msg[1]);
						bt = new byte[1024];
						jcb.addItem("...");
						for (int i = 0; i < totalLenth; i++) {
							len = is.read(bt);
							tmp = new String(bt, 0, len);
							System.out.println(tmp);
							novelName.add(tmp);
							jcb.addItem(tmp);
						}
						JOptionPane.showMessageDialog(null, "小说目录获取完成", "提示", JOptionPane.INFORMATION_MESSAGE);
						jbt4.setVisible(false);
						jcb.setVisible(true);
						jbt2.setVisible(true);
					}
				} catch (IOException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}
			}
		}
	}

	@Override
	public void itemStateChanged(ItemEvent arg0) {
		// TODO Auto-generated method stub
		if (jcb.getSelectedItem().equals("...")) {
			chosenNovel = "null";
		} else {
			for (int i = 0; i < novelName.size(); i++) {
				if (jcb.getSelectedItem().equals(novelName.get(i))) {
					chosenNovel = novelName.get(i);
				}
			}
		}
	}
}
