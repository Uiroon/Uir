import java.awt.AWTException;
import java.awt.Color;
import java.awt.Font;
import java.awt.Rectangle;
import java.awt.Robot;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;

import javax.imageio.ImageIO;
import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;

public class Function2 extends JFrame implements ItemListener, ActionListener {
	private JPanel jp = new JPanel();
	private JPanel back = new JPanel();
	private JComboBox<String> jcb = new JComboBox<String>();
	private JLabel text = new JLabel();
	private JButton save = new JButton("上传图片");
	private String defaultPath = new String("pic/");
	private JLabel title = new JLabel("请选择人物查看其在全本中出现的密度分布图");
	private RectPainter[][] rect = null;
	private String chosenName = new String("null");

	private int i = 0;
	private int j = 0;
	private int k = 0;

	public Function2() {
		System.gc();
		rect = new RectPainter[10][Manager.num];
		jp.setLayout(null);
		Font fontButton = new Font("黑体", 0, 20);
		Font fontCB = new Font("黑体", 0, 18);
		jcb.addItem("...");
		for (i = 0; i < 10; i++) {
			jcb.addItem(Manager.name[i]);
		}
		jcb.setSize(150, 45);
		jcb.setFont(fontCB);
		jcb.setLocation(398, 42);
		jcb.addItemListener(this);
		save.setSize(150, 45);
		save.setLocation(566, 42);
		save.setFont(fontButton);
		save.setContentAreaFilled(false);
		save.setForeground(new Color(180, 1, 7));
		save.addActionListener(this);
		save.setVisible(true);
		title.setFont(fontCB);
		title.setSize(700, 45);
		title.setLocation(360, 5);
		text.setFont(fontCB);
		text.setSize(700, 45);
		text.setLocation(385, 120);
		for (i = 0; i < 10; i++) {
			for (j = 0; j < Manager.num / 10; j++) {
				rect[i][j] = new RectPainter(0, 0, 30, 70, true,
						(int) (255 - (Manager.data.get(i).get(j) - Manager.info[i][1]) * (double) (255 / ((Manager.info[i][2] - Manager.info[i][1])))),
						(int) (255 - (Manager.data.get(i).get(j) - Manager.info[i][1]) * (double) (255 / ((Manager.info[i][2] - Manager.info[i][1])))),
						(int) (255 - (Manager.data.get(i).get(j) - Manager.info[i][1]) * (double) (255 / ((Manager.info[i][2] - Manager.info[i][1])))),
						false);
				rect[i][j].setSize(30, 70);
				rect[i][j].setLocation(220 + 30 * j, 200);
				jp.add(rect[i][j]);
				rect[i][j].setVisible(false);
			}
		}
		back.setBackground(Color.GRAY);
		back.setSize(30 * Manager.num / 10 + 30, 80);
		back.setLocation(205, 195);
		jp.add(back);
		jp.add(jcb);
		jp.add(title);
		jp.add(text);
		jp.add(save);
		jp.setBackground(Color.WHITE);
		jp.setSize(1080, 720);
		jp.setLocation(0, 0);
		this.add(jp);
		this.setResizable(false);
		this.setLocation(400, 200);
		this.setSize(1080, 720);
		this.setDefaultCloseOperation(EXIT_ON_CLOSE);
		this.setTitle("《幻夜》-出现密度统计");
		this.setVisible(true);
		this.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
	}

	@Override
	public void actionPerformed(ActionEvent arg0) {
		// TODO Auto-generated method stub
		if (chosenName.equals("null")) {
			JOptionPane.showMessageDialog(null, "请重新选择", "提示", JOptionPane.INFORMATION_MESSAGE);
		} else {
			BufferedImage myImage = null;
			File f = new File(defaultPath + chosenName + "的密度图.png");
			try {
				myImage = new Robot()
						.createScreenCapture(new Rectangle(this.getX() + 190, this.getY() + 140, 700, 200));
				ImageIO.write(myImage, "png", f);
				new Upload(defaultPath + chosenName + "的密度图.png");
			} catch (AWTException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	}

	@Override
	public void itemStateChanged(ItemEvent arg0) {
		// TODO Auto-generated method stub
		if (jcb.getSelectedItem().equals("...")) {
			for (i = 0; i < 10; i++)
				for (j = 0; j < Manager.num / 10; j++)
					rect[i][j].setVisible(false);
			text.setText(null);
			chosenName = "null";
		} else {
			for (k = 0; k < 10; k++) {
				if (jcb.getSelectedItem().equals(Manager.name[k])) {
					for (i = 0; i < 10; i++)
						for (j = 0; j < Manager.num / 10; j++)
							rect[i][j].setVisible(false);
					text.setText(null);
					text.setText(Manager.name[k] + "在全文中出现的密度：");
					chosenName = Manager.name[k];
					for (i = 0; i < Manager.num / 10; i++)
						rect[k][i].setVisible(true);
				}
			}
		}
	}
}
