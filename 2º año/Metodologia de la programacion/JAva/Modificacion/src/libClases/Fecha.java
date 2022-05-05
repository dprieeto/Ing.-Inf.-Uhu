package libClases;

import java.util.Scanner;

public class Fecha implements Cloneable, Proceso{

	private int dia, mes, anio;
	
	public Fecha(int dia, int mes, int anio)
	{
		setFecha(dia, mes, anio);
	}
	
	public Fecha(Fecha f) //No hace falta
	{
		this(f.dia, f.mes, f.anio);
	}
	
	@Override
	public String toString()
	{
		String s="";
		if(this.dia<10)
			s=s+0;
		s=s+this.dia+"/";
		if(this.mes<10)
			s=s+0;
		s=s+this.mes+ "/" +this.anio;
		return s;
	}
	
	@Override
	public void ver()
	{
		System.out.println(this);
	}
	
	@Override
	public boolean equals(Object obj)
	{
		if(this==obj)
			return true;
		if(obj.getClass()!=this.getClass())
			return false;
		if(obj.getClass()==null)
			return false;
		
		Fecha f= (Fecha)obj;
		
		return (f.getDia()==this.dia && f.getMes()==this.mes && f.getAnio()==this.anio);
	}
	
	@Override
	public Object clone()
	{
		return new Fecha(this);
	}
	
	public final boolean bisiesto()
	{
		return anio%400 == 0 || (anio%4 == 0 && anio%100 != 0);
	}
	
	public void setFecha(int d, int m, int a)
	{
		int dMax, dMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		
		this.anio=a;
		
		if(bisiesto())
		{
			dMes[2]=29;
		}
		
		if(m>12)
		{
			this.mes=12;
		}else if(m<1)
		{
			this.mes=1;
		}else
			this.mes=m;
		
		dMax=dMes[this.mes];
		
		if(d>dMax)
		{
			this.dia=dMax;
		}else if(d<1)
		{
			this.dia=1;
		}else
			this.dia=d;
	}
	
	public final int getDia() { return this.dia; }
	
	public final int getMes() { return this.mes; }
	
	public final int getAnio() { return this.anio; }
	
	public static Fecha pedirFecha()
	{
		int dia, mes, anio;
		boolean valida=false;
		Fecha f=null;
		Scanner sc = new Scanner (System.in);
		
		do
		{
			System.out.print("Introduce Fecha (dd/mm/yyyy): ");
			String fecha = sc.next();
			String[] tokens = fecha.split("/");
			try
			{
				if(tokens.length<3)
					throw new NumberFormatException();
				
				dia=Integer.parseInt(tokens[0]);
				mes=Integer.parseInt(tokens[1]);
				anio=Integer.parseInt(tokens[2]);
				
				f = new Fecha(dia, mes, anio);
				
				if(f.dia!=dia || f.mes!=mes || f.anio!=anio)
					throw new NumberFormatException();
				
				valida=true;
				
			}catch (NumberFormatException ex)
			{
				System.out.println("Fecha no valida.");
			}
		}while(valida==false);
			
		
		return f;
	}
	
	public static boolean mayor (Fecha f2, Fecha f1)
	{
		if(f1.getAnio()*100000 + f1.getMes()*100 + f1.getDia() < f2.getAnio()*100000 + f2.getMes()*100 + f2.getDia())
			return true;
		else
			return false;
	}
	
	public Fecha diaSig()
	{
		Fecha f = (Fecha)clone();
		f.dia++;
		int dMes[] = {0 ,31, 28, 31, 30, 31, 30, 31, 31,30, 31, 30, 31};
		
		if(bisiesto())
			dMes[2]=29;
		
		if(f.dia>dMes[f.mes])
		{
			f.dia=1;
			f.mes++;
		}
		if(f.mes>12)
		{
			f.anio++;
			f.mes=1;
		}
		
		return f;
	}
	
	public static void main(String[] args) {
		 Fecha f1 = new Fecha(29,2,2001), f2 = new Fecha(f1), f3 = new Fecha(29,2,2004);
		 final Fecha f4=new Fecha(05,12,2023); //es constante la referencia f4
		 System.out.print("Fechas: " + f1.toString() + ", "+f2+ ", " +f3+ ", " +f4+ "\n");
		 f1=new Fecha(31,12,2016); //31/12/2016
		 f4.setFecha(28, 2, 2008); //pero no es constante el objeto al que apunta
		 System.out.println(f1 +" "+ f2.toString() +" " + f3 +" "+ f4+" "+ f1);
		 f1=new Fecha(f4.getDia()-10, f4.getMes(), f4.getAnio()-7); //f1=18/02/2001
		 f3=Fecha.pedirFecha(); //pide una fecha por teclado
		 f2.setFecha(10,12,2000);
		 if (f3.bisiesto() && Fecha.mayor(f2,f1))
		 System.out.print("El " + f3.getAnio() + " fue bisiesto, " + f1 + ", " + f3);
		 
		 System.out.println("FIN");
		} 
}
