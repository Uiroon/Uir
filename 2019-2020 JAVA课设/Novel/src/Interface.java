import java.awt.Color;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

public class Interface extends JFrame {

	private JPanel jp = new JPanel();
	private JLabel title = new JLabel("《幻夜》分析");
	private JButton jbt1 = new JButton("存在感排名");
	private JButton jbt2 = new JButton("出现密度统计");
	private JButton jbt3 = new JButton("人物关系");
	private JLabel cover = new JLabel();

	public Interface() {
		System.gc();
		jp.setLayout(null);
		Font fontTitle = new Font("黑体", Font.BOLD, 48);
		Font fontButton = new Font("黑体", 0, 20);
		cover.setSize(1080, 496);
		cover.setLocation(0, 400);
		cover.setIcon(new ImageIcon(Login.pathofCover));
		title.setFont(fontTitle);
		title.setSize(330, 50);
		title.setLocation(370, 40);
		jbt1.setSize(200, 60); // 人物存在感排名
		jbt1.setLocation(420, 180);
		jbt1.setFont(fontButton);
		jbt1.setContentAreaFilled(false);
		jbt1.setForeground(new Color(180, 1, 7));
		jbt1.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				new Function1();
			}
		});
		jbt2.setSize(200, 60); // 出现密度统计
		jbt2.setLocation(420, 260);
		jbt2.setFont(fontButton);
		jbt2.setContentAreaFilled(false);
		jbt2.setForeground(new Color(180, 1, 7));
		jbt2.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				new Function2();
			}
		});
		jbt3.setSize(200, 60); // 人物关系
		jbt3.setLocation(420, 340);
		jbt3.setFont(fontButton);
		jbt3.setContentAreaFilled(false);
		jbt3.setForeground(new Color(180, 1, 7));
		jbt3.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				new Function3();
			}
		});
		jp.add(title);
		jp.add(cover);
		jp.add(jbt1);
		jp.add(jbt2);
		jp.add(jbt3);
		jp.setBackground(Color.WHITE);
		this.setResizable(false);
		this.add(jp);
		this.setSize(1080, 720);
		this.setLocation(400, 200);
		this.setDefaultCloseOperation(EXIT_ON_CLOSE);
		this.setTitle("《幻夜》");
		this.setVisible(true);
	}
}
