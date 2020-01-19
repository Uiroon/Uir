import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.OutputStream;

import javax.swing.JOptionPane;
public class Upload extends Thread{
	private String path=null;
	public Upload(String str) {
		path=str;
		new Thread(this).start();
	}
	@Override
	public void run() {
		// TODO Auto-generated method stub
		try {
			File save=new File(path);
			OutputStream os = Login.st.getOutputStream();
			byte[] bt = new byte[1024];
			int len=0;
			FileInputStream fis = new FileInputStream(path);
			os.write(("REQUESTFROMCLIENT#储存图片#"+save.length()+"#"+save.getName()).getBytes());
			this.sleep(100);

			while((len = fis.read(bt)) != -1){
				os.write(bt,0,len);
				os.flush();
			}
			fis.close();
			this.sleep(300);
			JOptionPane.showMessageDialog(null, "上传成功", "提示", JOptionPane.INFORMATION_MESSAGE);
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
