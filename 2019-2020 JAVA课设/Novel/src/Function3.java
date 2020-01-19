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
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

import javax.imageio.ImageIO;
import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;

public class Function3 extends JFrame implements ItemListener, ActionListener {
	private JPanel jp = new JPanel();
	private JLabel[][] JName = new JLabel[10][9];
	private JLabel text = new JLabel();
	private JButton subsave = new JButton("上传图片");
	private JButton save = new JButton("上传图片");
	private JButton jbt = new JButton("显示猜测");
	private JComboBox<String> jcb = new JComboBox<String>();
	private String defaultPath = new String("pic/");
	private JLabel title = new JLabel("请选择人物查看其与其他人的亲密度");
	private RectPainter[][] rect = new RectPainter[10][9];
	private Map<Integer, ArrayList<Double>> freCentage = new HashMap<Integer, ArrayList<Double>>();
	private Map<Integer, ArrayList<Double>> intimacy = new HashMap<Integer, ArrayList<Double>>();
	private Map<Integer, ArrayList<Integer>> cloest = new HashMap<Integer, ArrayList<Integer>>();
	private ArrayList<String> lead = new ArrayList<String>();
	private ArrayList<String> support = new ArrayList<String>();
	private RectPainter[] rolePart = new RectPainter[10];
	private JLabel[] JNameInner = new JLabel[10];
	private String chosenName = new String("null");
	private int i = 0;
	private int j = 0;
	private int k = 0;

	public Function3() {
		System.gc();
		for (i = 0; i < 10; i++) {
			ArrayList<Double> tmpCentage = new ArrayList<Double>();
			for (j = 0; j < Manager.num / 10; j++) {
				tmpCentage.add(((double) Manager.data.get(i).get(j) / (double) Manager.info[i][0]) * 100);
			}
			freCentage.put(i, tmpCentage);
		}
		for (i = 0; i < 10; i++) {
			double count = 0;
			ArrayList<Double> tmpIntimacy = new ArrayList<Double>();
			for (j = 0; j < 10; j++) {
				count = 0;
				for (k = 0; k < Manager.num / 10; k++) {
					if (Math.abs(freCentage.get(i).get(k) - freCentage.get(j).get(k)) < 1.00
							&& freCentage.get(i).get(k) != 0 && freCentage.get(j).get(k) != 0) {
						count += 5 * (100 - Math.abs(freCentage.get(i).get(k) - freCentage.get(j).get(k)));
					} else if (Math.abs(freCentage.get(i).get(k) - freCentage.get(j).get(k)) < 2.00
							&& freCentage.get(i).get(k) != 0 && freCentage.get(j).get(k) != 0) {
						count += 3 * (100 - Math.abs(freCentage.get(i).get(k) - freCentage.get(j).get(k)));
					} else if (Math.abs(freCentage.get(i).get(k) - freCentage.get(j).get(k)) < 3.00
							&& freCentage.get(i).get(k) != 0 && freCentage.get(j).get(k) != 0) {
						count += 1 * (100 - Math.abs(freCentage.get(i).get(k) - freCentage.get(j).get(k)));
					}
				}
				tmpIntimacy.add(count);
			}
			intimacy.put(i, tmpIntimacy);
		}
		for (i = 0; i < 10; i++) {
			ArrayList<Integer> tmpclose = new ArrayList<Integer>();
			double max0 = 0;
			double max1 = 0;
			double max2 = 0;
			int index0 = 0;
			int index1 = 0;
			int index2 = 0;
			for (j = 0; j < 10; j++) {
				if (intimacy.get(i).get(j) > max0) {
					max2 = max1;
					max1 = max0;
					index2 = index1;
					index1 = index0;
					max0 = intimacy.get(i).get(j);
					index0 = j;
				} else if (intimacy.get(i).get(j) > max1 && intimacy.get(i).get(j) < max0) {
					max2 = max1;
					index2 = index1;
					max1 = intimacy.get(i).get(j);
					index1 = j;
				} else if (intimacy.get(i).get(j) > max2 && intimacy.get(i).get(j) < max1) {
					max2 = intimacy.get(i).get(j);
					index2 = j;
				}
			}
			tmpclose.add(index1);
			tmpclose.add(index2);
			cloest.put(i, tmpclose);
		}
		for (i = 0; i < 10; i++) {
			boolean flag = false;
			for (j = 0; j < 2; j++) {
				for (k = 0; k < 2; k++) {
					if (cloest.get(cloest.get(i).get(j)).get(k) == i) {
						flag = true;
					}
				}
			}
			if (flag) {
				lead.add(Manager.name[i]);
			} else {
				support.add(Manager.name[i]);
			}
		}
		jp.setLayout(null);
		Font fontButton = new Font("黑体", 0, 20);
		Font fontCB = new Font("黑体", 0, 18);
		Font fontName = new Font("宋体", 0, 14);
		jcb.addItem("...");
		for (int i = 0; i < 10; i++) {
			jcb.addItem(Manager.name[i]);
		}
		jcb.setSize(150, 45);
		jcb.setFont(fontCB);
		jcb.setLocation(398, 42);
		jcb.addItemListener(this);
		jbt.setSize(150, 45);
		jbt.setLocation(566, 42);
		jbt.setFont(fontButton);
		jbt.setContentAreaFilled(false);
		jbt.setForeground(new Color(180, 1, 7));
		jbt.addActionListener(this);
		subsave.setSize(150, 45);
		subsave.setLocation(730, 42);
		subsave.setFont(fontButton);
		subsave.setContentAreaFilled(false);
		subsave.setForeground(new Color(180, 1, 7));
		subsave.addActionListener(this);
		subsave.setVisible(true);
		save.setSize(150, 45);
		save.setLocation(730, 42);
		save.setFont(fontButton);
		save.setContentAreaFilled(false);
		save.setForeground(new Color(180, 1, 7));
		save.addActionListener(this);
		save.setVisible(false);
		title.setFont(fontCB);
		title.setSize(700, 45);
		title.setLocation(360, 5);
		text.setFont(fontCB);
		text.setSize(700, 45);
		text.setLocation(385, 120);
		jp.add(jbt);
		jp.add(jcb);
		jp.add(subsave);
		jp.add(save);
		jp.add(text);
		jp.add(title);
		jp.setBackground(Color.WHITE);
		jp.setSize(1080, 720);
		jp.setLocation(0, 0);
		for (i = 0; i < 10; i++) {
			int flag = 0;
			for (k = 0; k < 10; k++) {
				j = k;
				if (i == k) {
					flag = 1;
				} else {
					j -= flag;
					rect[i][j] = new RectPainter(0, 0, 70,
							(int) (400 * intimacy.get(i).get(k) / intimacy.get(i).get(cloest.get(i).get(0))), true, 184,
							21, 53, true);
					rect[i][j].setSize(70,
							(int) (400 * intimacy.get(i).get(k) / intimacy.get(i).get(cloest.get(i).get(0))));
					rect[i][j].setLocation(80 + 100 * j, 220 + 400
							- (int) (400 * intimacy.get(i).get(k) / intimacy.get(i).get(cloest.get(i).get(0))));
					jp.add(rect[i][j]);
					rect[i][j].setVisible(false);
					JName[i][j] = new JLabel(Manager.name[k]);
					JName[i][j].setSize(70, 42);
					JName[i][j].setFont(fontName);
					JName[i][j].setLocation(84 + 100 * j, 620);
					jp.add(JName[i][j]);
					JName[i][j].setVisible(false);
				}
			}
		}
		for (i = 0; i < 10; i++) {
			rolePart[i] = new RectPainter(0, 0, 100, 70, true, 184, 21, 53, false);
			rolePart[i].setSize(100, 70);
			JNameInner[i] = new JLabel(Manager.name[i]);
			JNameInner[i].setSize(70, 42);
			JNameInner[i].setFont(fontName);
			JNameInner[i].setForeground(Color.WHITE);
			jp.add(JNameInner[i]);
			jp.add(rolePart[i]);
			rolePart[i].setVisible(false);
			JNameInner[i].setVisible(false);
			for (j = 0; j < lead.size(); j++) {
				if (Manager.name[i] == lead.get(j)) {
					rolePart[i].setLocation(100 + 105 * j, 250);
					JNameInner[i].setLocation(114 + 105 * j, 255);
				}
			}
			for (j = 0; j < support.size(); j++) {
				if (Manager.name[i] == support.get(j)) {
					rolePart[i].setLocation(100 + 105 * j, 400);
					JNameInner[i].setLocation(114 + 105 * j, 405);
				}
			}
		}
		this.add(jp);
		this.setResizable(false);
		this.setLocation(400, 200);
		this.setSize(1080, 720);
		this.setDefaultCloseOperation(EXIT_ON_CLOSE);
		this.setTitle("《幻夜》-人物关系");
		this.setVisible(true);
		this.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
	}

	@Override
	public void actionPerformed(ActionEvent e) {
		// TODO Auto-generated method stub
		if (e.getSource() == subsave && chosenName.equals("null")) {
			JOptionPane.showMessageDialog(null, "请重新选择", "提示", JOptionPane.INFORMATION_MESSAGE);
		} else if (e.getSource() == subsave && !chosenName.equals("null")) {
			BufferedImage myImage = null;
			File f = new File(defaultPath + chosenName + "与其他人的亲密度.png");
			try {
				myImage = new Robot().createScreenCapture(new Rectangle(this.getX() + 5, this.getY() + 140, 1070, 550));
				ImageIO.write(myImage, "png", f);
				new Upload( defaultPath + chosenName + "与其他人的亲密度.png");
			} catch (AWTException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			} catch (IOException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}
		} else if (e.getSource() == save) {
			BufferedImage myImage = null;
			File f = new File(defaultPath + "猜测的关系.png");
			try {
				myImage = new Robot().createScreenCapture(new Rectangle(this.getX() + 5, this.getY() + 140, 1070, 550));
				ImageIO.write(myImage, "png", f);
				new Upload( defaultPath + "猜测的关系.png");
			} catch (AWTException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			} catch (IOException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}
		} else if (e.getSource() == jbt) {
			text.setText("猜测的关系为：");
			for (i = 0; i < 10; i++) {
				for (j = 0; j < 9; j++) {
					rect[i][j].setVisible(false);
					JName[i][j].setVisible(false);
				}
				rolePart[i].setVisible(true);
				JNameInner[i].setVisible(true);
			}
			subsave.setVisible(false);
			save.setVisible(true);
		}
	}

	@Override
	public void itemStateChanged(ItemEvent e) {
		// TODO Auto-generated method stub
		if (jcb.getSelectedItem().equals("...")) {
			for (i = 0; i < 10; i++) {
				rolePart[i].setVisible(false);
				JNameInner[i].setVisible(false);
				for (j = 0; j < 9; j++) {
					rect[i][j].setVisible(false);
					JName[i][j].setVisible(false);
				}
			}
			save.setVisible(false);
			subsave.setVisible(true);
			text.setText(null);
			chosenName = "null";
		} else {
			for (k = 0; k < 10; k++) {
				if (jcb.getSelectedItem().equals(Manager.name[k])) {
					for (i = 0; i < 10; i++) {
						rolePart[i].setVisible(false);
						JNameInner[i].setVisible(false);
						for (j = 0; j < 9; j++) {
							rect[i][j].setVisible(false);
							JName[i][j].setVisible(false);
						}
					}
					save.setVisible(false);
					subsave.setVisible(true);
					text.setText(null);
					text.setText(Manager.name[k] + "与其他人的亲密度：");
					chosenName = Manager.name[k];
					for (i = 0; i < 9; i++) {
						rect[k][i].setVisible(true);
						JName[k][i].setVisible(true);
					}
				}
			}
		}
	}
}
