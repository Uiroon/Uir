import java.awt.AWTException;
import java.awt.Color;
import java.awt.Font;
import java.awt.Rectangle;
import java.awt.Robot;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import java.util.Comparator;
import java.util.Set;
import java.util.TreeMap;

import javax.imageio.ImageIO;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

public class Function1 extends JFrame implements ActionListener {
	private int max;
	private RectPainter[] rect = new RectPainter[10];
	private JPanel jp = new JPanel();
	private JLabel[] JName = new JLabel[10];
	private JLabel[] JSum = new JLabel[10];
	private JLabel text = new JLabel("以下为所有人物在全文中大约出现的次数");
	private JButton save = new JButton("上传图片");
	private String defaultPath = new String("pic/");
	private JButton sort = new JButton("排序");
	private boolean isSort = false;
	private TreeMap<Integer, Integer> m = new TreeMap<Integer, Integer>(new Comparator<Integer>() {
		@Override
		public int compare(Integer a, Integer b) {
			return b - a;
		}
	});
	private Set<Integer> keySet = null;

	public Function1() {
		System.gc();
		max = Manager.info[0][0];
		jp.setLayout(null);
		for (int i = 1; i < 10; i++) {
			if (Manager.info[i][0] > max)
				max = Manager.info[i][0];
		}
		Font fontButton = new Font("黑体", 0, 20);
		Font fontCB = new Font("黑体", 0, 18);
		Font fontName = new Font("宋体", 0, 14);
		save.setSize(150, 45);
		save.setLocation(580, 42);
		save.setFont(fontButton);
		save.setContentAreaFilled(false);
		save.setForeground(new Color(180, 1, 7));
		save.addActionListener(this);
		save.setVisible(true);
		sort.setSize(150, 45);
		sort.setLocation(380, 42);
		sort.setFont(fontButton);
		sort.setContentAreaFilled(false);
		sort.setForeground(new Color(180, 1, 7));
		sort.addActionListener(this);
		sort.setVisible(true);
		text.setFont(fontCB);
		text.setSize(700, 45);
		text.setLocation(385, 120);
		jp.add(sort);
		jp.add(text);
		jp.add(save);
		jp.setBackground(Color.WHITE);
		jp.setSize(1080, 720);
		jp.setLocation(0, 0);
		for (int i = 0; i < 10; i++) {
			rect[i] = new RectPainter(0, 0, 70, 400 * (Manager.info[i][0]) / max, true, 184, 21, 53, true);
			rect[i].setSize(70, 400 * (Manager.info[i][0]) / max);
			rect[i].setLocation(40 + 100 * i, 220 + 400 - 400 * (Manager.info[i][0]) / max);
			jp.add(rect[i]);
			rect[i].setVisible(true);

			JSum[i] = new JLabel(new String(Integer.toString(Manager.info[i][0])));
			JSum[i].setSize(70, 42);
			JSum[i].setFont(fontName);
			JSum[i].setLocation(56 + 100 * i, 182 + 400 - 400 * (Manager.info[i][0]) / max);
			jp.add(JSum[i]);
			JSum[i].setVisible(true);

			JName[i] = new JLabel(Manager.name[i]);
			JName[i].setSize(70, 42);
			JName[i].setFont(fontName);
			JName[i].setLocation(44 + 100 * i, 620);
			jp.add(JName[i]);
			JName[i].setVisible(true);
		}
		this.add(jp);
		this.setResizable(false);
		this.setLocation(400, 200);
		this.setSize(1080, 720);
		this.setDefaultCloseOperation(EXIT_ON_CLOSE);
		this.setTitle("《幻夜》-存在感排名");
		this.setVisible(true);
		this.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);

	}

	@Override
	public void actionPerformed(ActionEvent e) {
		// TODO Auto-generated method stub

		if (e.getSource() == save) {
			String saveName = new String("小说中所有人物出现次数柱状图-未排序.png");
			if (isSort) {
				saveName = "小说中所有人物出现次数柱状图-已排序.png";
			}
			BufferedImage myImage = null;
			File f = new File(defaultPath + saveName);
			try {
				myImage = new Robot().createScreenCapture(new Rectangle(this.getX() + 5, this.getY() + 140, 1070, 550));
				ImageIO.write(myImage, "png", f);
				new Upload(defaultPath + saveName);
			} catch (AWTException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			} catch (IOException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}
		} else if (e.getSource().equals(sort)) {
			isSort = true;
			for (int i = 0; i < 10; i++) {
				m.put(Manager.info[i][0], i);
			}
			keySet = m.keySet();
			int j = 0;
			for (Object key : keySet) {
				rect[m.get(key)].setLocation(40 + 100 * j, 220 + 400 - 400 * (Manager.info[m.get(key)][0]) / max);
				JSum[m.get(key)].setLocation(56 + 100 * j, 182 + 400 - 400 * (Manager.info[m.get(key)][0]) / max);
				JName[m.get(key)].setLocation(44 + 100 * j, 620);
				j++;
			}
		}
	}

}
