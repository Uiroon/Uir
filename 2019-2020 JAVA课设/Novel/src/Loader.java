import java.io.File;
import java.io.RandomAccessFile;
import java.util.ArrayList;
public class Loader {
	private int num=0;//小说一共分为了几段
	public ArrayList<Integer> Load(String path, String name) throws Exception {
		ArrayList<Integer> info = new ArrayList<Integer>();// 创建一个ArrayList来存放每段人物出现次数
		File novel = new File(path);// 打开文件
		long pointer = 0;
		byte[] buff = new byte[28000];// 每28000字节为一段
		RandomAccessFile tmp = new RandomAccessFile(novel, "r");
		while (true) {
			int frequency = 0;
			tmp.seek(pointer);
			try {
				tmp.readFully(buff);
				String paragraph = new String(buff);
				for (int i = 0; i < paragraph.length() - name.length(); i++) {
					if (name.equals(paragraph.substring(i, i + name.length()))) {
						frequency++;
					}
				}
				num++;
				pointer += 28000;
				info.add(frequency);
			} catch (Exception e) {
				byte[]buffx=new byte[(int)(tmp.length()-pointer)];
				String paragraph = new String(buffx);
				for (int i = 0; i < paragraph.length() - name.length(); i++) {
					if (name.equals(paragraph.substring(i, i + name.length()))) {
						frequency++;
					}
				}
				num++;
				info.add(frequency);
				break;
			}
		}
		tmp.close();
		return info;
	}
	public int Count(ArrayList<Integer> al) {
		int sum=0;
		for (int i = 0; i < al.size(); i++) {
			sum+=al.get(i);
		}
		return sum;
	}
	public int MaxFre(ArrayList<Integer> maxal) {
		int max=maxal.get(0);
		for (int i = 1; i < maxal.size(); i++) {
			if(maxal.get(i)>max) max=maxal.get(i);
		}
		return max;
	}
	public int MinFre(ArrayList<Integer> minal) {
		int min=minal.get(0);
		for (int i = 1; i < minal.size(); i++) {
			if(minal.get(i)<min) min=minal.get(i);
		}
		return min;
	}
	public int getNum() {
		return num;
	}
}
