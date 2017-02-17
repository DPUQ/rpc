import java.util.Scanner;

public class classtime {
	static String l[],h[];
	
	public static void main(String[] args) {
	 
	 int n,i=0;
	 Scanner entrada= new Scanner(System.in);
	 n=entrada.nextInt();
	 entrada.nextLine();
	 l=new String[n];
	 h=new String[n];
	 String palabra="";
	 while(i<n){
		 palabra=entrada.next();
		 l[i]=palabra;
		 palabra=entrada.next();
		 h[i]=palabra;
		 i++;
	 }
	 ordenar();
	 
	 for (int j = 0; j <n; j++) {
		System.out.println(l[j]+" "+h[j]);
	}

	}
	
	public static void ordenar(){
		int i, j;
		String aux;
        for(i=0;i<l.length-1;i++)
             for(j=0;j<l.length-i-1;j++)
            	 
            	 if(h[j+1].compareTo(h[j])==0){
            		 if(l[j+1].compareTo(l[j]) < 0){
                         aux=l[j+1];
                         l[j+1]=l[j];
                         l[j]=aux;
                         aux=h[j+1];
                         h[j+1]=h[j];
                         h[j]=aux;
                      }
            	 }else
                               	 
                  if(h[j+1].compareTo(h[j]) < 0){
                     aux=l[j+1];
                     l[j+1]=l[j];
                     l[j]=aux;
                     aux=h[j+1];
                     h[j+1]=h[j];
                     h[j]=aux;
                  }
	}

}
