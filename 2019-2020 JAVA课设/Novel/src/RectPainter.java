import java.awt.Color;
import java.awt.Graphics;

import javax.swing.JPanel;
public class RectPainter extends JPanel {
	private int x;
	private int y;
	private int width;
	private int height;
	private boolean raised;
	private int R;
	private int G;
	private int B;
	private boolean style;
	public RectPainter(int x1, int y1, int width1, int height1, boolean raised1 ,int R1,int G1,int B1,boolean style1)
	{
		x=x1;
		y=y1;
		width=width1;
		height=height1;
		raised=raised1;
		R=R1;
		G=G1;
		B=B1;
		style=style1;
	}
	@Override
	public void paint(Graphics g){
		//super.paint(g);
		if(style) {
			g.setColor(new Color(R,G,B));
			g.fill3DRect(x,y,width,height,raised);
		}else {
			g.setColor(new Color(R,G,B));
			g.fillRect(x,y,width,height);
		}
	}
}
