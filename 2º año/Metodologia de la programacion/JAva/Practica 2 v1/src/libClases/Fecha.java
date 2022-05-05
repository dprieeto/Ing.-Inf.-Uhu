package libClases;
//import java.util.Scanner;
import java.util.*;//tb vale java.util.Scanner; solo q con el * engloba a java.util
//Scanner sirve para introducir datos x pantalla
public final class Fecha implements Cloneable, Proceso { //final=la clase no puede tener hijos
	private int dia;
	private int mes;
	private int anio;
	
	public Fecha(int dia,int mes,int anio) {
		// TODO Auto-generated constructor stub
		this.setFecha(dia, mes, anio);
	}
	public Fecha(Fecha f) {
		//this.setFecha(f.dia, f.mes, f.anio);
		this(f.dia,f.mes,f.anio);
	}
	public void setDia(int dia) {
		this.dia=dia;
	}
	public void setMes(int mes) {
		this.mes=mes;
	}
	public void setAnio(int anio){
		this.anio=anio;
	}
	public int getDia() {return dia;}
	public int getMes() {return mes;}
	public int getAnio() {return anio;}
	public boolean bisiesto() {
		/*
		if(((anio%4==0) && (anio%100!=0))||anio%400==0)
			return true;
		else
			return false;
			*/
		return anio%400 == 0 || (anio%4 == 0 && anio%100 != 0);
	}
	public void setFecha(int dia,int mes, int anio){
		int dmax,diaMes[]= {0,31,28,31,30,31,30,31,31,30,31,30,31};
		this.anio=anio;
		if(this.bisiesto())
			diaMes[2]=29;
		if(mes<1)
			this.mes=12;
		else if(mes>12)
			this.mes=1;
		else
			this.mes=mes;
		dmax=diaMes[this.mes];
		if(dia>dmax)
			this.dia=dmax;
		else if(dia<1)
			this.dia=1;
		else
			this.dia=dia;
	}
	
	public static Fecha pedirFecha(){ 
		/*
		Scanner entrada=new Scanner(System.in);
		System.out.println("Introduce el dia: ");
		int dia =entrada.nextInt();
		System.out.println("Introduce el mes: ");
		int mes=entrada.nextInt();
		System.out.println("Introduce el anio: ");
		int anio=entrada.nextInt();
		entrada.close();
		*/
		//FALTA HACER LA EXCEPCION CON TRYCATCH
		Fecha fecha=null; //objeto tipo fecha para guardar la fecha por teclado
		boolean valido=false;
		Scanner entrada=new Scanner(System.in); //para meter datos por teclado hay que usar estos siempre
		int dia,mes,anio;
		do
		{
			System.out.println("Introduce la fecha (dd/mm/aaaa): ");
			String cadena=entrada.next();//vamos a meter la fecha en forma de cadena, tbse podria hacer como arriba
			String[] tokens=cadena.split("/");//asignamos a tokens una cadena separada en tantas partes como tenga en este caso '/'
			try //para excepciones
			{
				if(tokens.length!=3)
					throw new NumberFormatException();//throw es para lanzar una excepcion
				dia=Integer.parseInt(tokens[0]);//parseInt lanza la excepcion //transforma a tipo int la primera parte de la cadena
				mes=Integer.parseInt(tokens[1]);//NumberFormatException si no
				anio=Integer.parseInt(tokens[2]);//puede convertir el string a int
				fecha=new Fecha(dia,mes,anio);
				if(fecha.getDia()!=dia||fecha.getMes()!=mes)
					throw new NumberFormatException();
				valido=true;
			}catch(NumberFormatException e)//si try falla se ejecuta catch
			{
				System.out.println("Fecha no valida.");
			}
		}while(!valido);
		entrada.close();//siempre hay q ponerlo al final
		return fecha;
	} 
	
	public static boolean mayor(Fecha f1,Fecha f2) { //devuelve true si la f1 es mayor a f2,false en caso contrario
		if(f1.anio*10000+f1.mes*100+f1.dia>f2.anio*10000+f2.mes*100+f2.dia)
			return true;
		else 
			return false; 
	}
	
	public Fecha diaSig()
	{
		//Fecha f=new Fecha(this);
		Fecha f=(Fecha)this.clone();
		f.dia++;
		int diasMes[]= {0,31,28,31,30,31,30,31,31,30,31,30,31};
		
		if(bisiesto())
		{
			diasMes[2]=29;
		}
		
		if(f.dia>diasMes[f.mes])
		{
			f.dia=1;
			f.mes++;
		}
		
		if(f.mes>12)
		{
			f.mes=1;
			f.anio++;
		}
		return f;
	}
	
	public String toString()
	{
		//dos amneras de hacerlo
		String s="";
		if(this.dia<10) s=s+0;//si es <10 quedaria s=0; y al sumar el dia ya q es menor q 10 seria s=09... etc
		s=s+this.dia+"/";
		if(mes<10)s+=0;
		s+=mes+"/"+anio;
		return s;
		//otra opcion mediante el '%02d' para devolver caracteres de forma separada como fechas y horas
		//return String.format("%02d/%02d/%02d", dia, mes, anio);
	}
	
	@Override
	public Object clone()
	{
		/*
		Object obj=null;
		try
		{
			obj=super.clone();//se llama al clone de la clase base (Object)
							  //que hace copia binaria de los atributos 
		}catch(CloneNotSupportedException ex)
		{
			System.out.println(" no se puede duplicar");
		}
		return obj;
		*/
		return new Fecha(this);
	}
	
	public boolean equals(Object obj) { //true sin son iguales
		if (this == obj) return true; //si apuntan al mismo sitio son iguales
		if (obj == null) return false;
		if (getClass() != obj.getClass())//if (!(obj instanceof Cliente))
		return false; // si los 2 no son de la misma clase no son iguales
		Fecha c = (Fecha) obj;
		return (dia==c.dia && mes==c.mes && anio==c.anio);
		}

	public void ver() {
		System.out.println(this/*.toString()*/);
		} 
	
	
	public static void main(String[] args) {
		Fecha f1 = new Fecha(29,2,2001), f2 = new Fecha(f1), f3 = new Fecha(29,2,2004); 
		final Fecha f4=new Fecha(05,12,2023); //es constante la referencia f4 
		System.out.println("Fechas: " + f1.toString() + ", "+f2+ ", " +f3+ ", " +f4+ "\n");
		f1=new Fecha(31,12,2016); //31/12/2016
		f4.setFecha(28, 2, 2008); //pero no es constante el objeto al que apunta
		System.out.println(f1 +" "+ f2.toString() +" " + f3 +" "+ f4+" "+ f1);
		f1=new Fecha(f4.getDia()-10, f4.getMes(), f4.getAnio()-7); //f1=18/02/2001
		f3=Fecha.pedirFecha(); //pide una fecha por teclado pedirFecha() tb es estatico xk lo llama con el nombre de la clase(Fecha)
		if (f3.bisiesto() && Fecha.mayor(f2,f1))//mayor es un metodo estatico xk lo llama con el nombre de la clase(Fecha)
		System.out.print("El " + f3.getAnio() + " fue bisiesto, " + f1 + ", " + f3);
	}

}

