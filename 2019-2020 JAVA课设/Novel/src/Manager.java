import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
public class Manager {
	public static Map<Integer, ArrayList<Integer>> data = new HashMap<Integer, ArrayList<Integer>>();
	public static int[][]info=new int[10][3];
	public static String pathOfNovel =null;
	public static String[] name =new String[10];
	public static int num=0;//С˵һ����Ϊ�˼���
	private Loader lder = new Loader();
	public Manager(String str) throws Exception{
		pathOfNovel=str;
		name[0]="ˮԭ��Ҳ";
		name[1]="�º�����";
		name[2]="�཭��һ��";
		name[3]="���¡��";
		name[4]="����Т��";
		name[5]="���ҹ���";
		name[6]=" ��  ��";
		name[7]="�� �� ب";
		name[8]="��������";
		name[9]="��Ұ��ʵ";
		ArrayList<Integer> fre0 = lder.Load(pathOfNovel, "��Ҳ");//ˮԭ��Ҳ
		info[0][0]=lder.Count(fre0);
		info[0][1]=lder.MinFre(fre0);
		info[0][2]=lder.MaxFre(fre0);
		data.put(0,fre0);
		ArrayList<Integer> fre1 = lder.Load(pathOfNovel, "����");//�º�����
		info[1][0]=lder.Count(fre1);
		info[1][1]=lder.MinFre(fre1);
		info[1][2]=lder.MaxFre(fre1);
		data.put(1,fre1);
		ArrayList<Integer> fre2 = lder.Load(pathOfNovel, "�཭");//�཭��һ��
		info[2][0]=lder.Count(fre2);
		info[2][1]=lder.MinFre(fre2);
		info[2][2]=lder.MaxFre(fre2);
		data.put(2,fre2);
		ArrayList<Integer> fre3 = lder.Load(pathOfNovel, "¡��");//���¡��
		info[3][0]=lder.Count(fre3);
		info[3][1]=lder.MinFre(fre3);
		info[3][2]=lder.MaxFre(fre3);
		data.put(3,fre3);
		ArrayList<Integer> fre4 = lder.Load(pathOfNovel, "Т��");//����Т��
		info[4][0]=lder.Count(fre4);
		info[4][1]=lder.MinFre(fre4);
		info[4][2]=lder.MaxFre(fre4);
		data.put(4,fre4);
		ArrayList<Integer> fre5 = lder.Load(pathOfNovel, "����");//���ҹ���
		info[5][0]=lder.Count(fre5);
		info[5][1]=lder.MinFre(fre5);
		info[5][2]=lder.MaxFre(fre5);
		data.put(5,fre5);
		ArrayList<Integer> fre6 = lder.Load(pathOfNovel, "����");//����
		info[6][0]=lder.Count(fre6);
		info[6][1]=lder.MinFre(fre6);
		info[6][2]=lder.MaxFre(fre6);
		data.put(6,fre6);
		ArrayList<Integer> fre7 = lder.Load(pathOfNovel, "����");//����ب
		info[7][0]=lder.Count(fre7);
		info[7][1]=lder.MinFre(fre7);
		info[7][2]=lder.MaxFre(fre7);
		data.put(7,fre7);
		ArrayList<Integer> fre8 = lder.Load(pathOfNovel, "����");//��������
		info[8][0]=lder.Count(fre8);
		info[8][1]=lder.MinFre(fre8);
		info[8][2]=lder.MaxFre(fre8);
		data.put(8,fre8);
		ArrayList<Integer> fre9 = lder.Load(pathOfNovel, "��ʵ");//��Ұ��ʵ
		info[9][0]=lder.Count(fre9);
		info[9][1]=lder.MinFre(fre9);
		info[9][2]=lder.MaxFre(fre9);
		data.put(9,fre9);
		num=lder.getNum();
		new Interface();
	}
}
