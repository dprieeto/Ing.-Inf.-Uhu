package libClases;

import java.util.Scanner;

public class Empresa implements Cloneable {
	
	private Cliente[] clientes;
	private int nClientes;
	
	public Empresa()
	{
		clientes = new Cliente[10];
		nClientes=0;
	}
	
	/*public Empresa(Empresa e)
	{
		clientes=e.clientes.clone();
		nClientes=e.nClientes;
	}*/

	public int getN()
	{
		return nClientes;
	}
	
	public int buscarCliente(String dni)
	{
		boolean existe=false;
		int pos=-1, i=0;
		while(i<nClientes && !existe)
		{
			if(clientes[i].getNif().equals(dni))
			{
				existe=true;
				pos=i;
			}else
				i++;
		}
		
		return pos;
	}
	
	public void alta(Cliente c)
	{
		if(nClientes==10)
		{
			Cliente[] aux = new Cliente [clientes.length+5];
			for(int i=0; i<clientes.length; i++)
				aux[i]=clientes[i];
			
			clientes=aux;
		}
		
		int existe=buscarCliente(c.getNif());
		if(existe==-1 || c==null) //No existe por lo tanto se añade
		{
			clientes[nClientes]=c;
			nClientes++;
		}
	}
	
	public void alta()
	{
		Scanner sc = new Scanner(System.in);
		
		System.out.print("DNI: ");
		String nif = sc.nextLine();
		
		if(buscarCliente(nif) == -1)
		{
			System.out.print("Nombre: ");
			String nombre = sc.nextLine();
			System.out.println("Fecha Nacimiento:");	
			Fecha fNac = Fecha.pedirFecha();
			System.out.println("Fecha Alta");
			Fecha fAlta = Fecha.pedirFecha();
			System.out.print("Minutos que habla al mes: ");
			float min = sc.nextFloat();
			System.out.print("Indique tipo de cliente (1-Movil, 2-Tarifa Plana): ");
			int tipo = sc.nextInt();
			
			if(tipo==1) //Movil
			{
				System.out.print("Precio por minuto: ");
				float precio = sc.nextFloat();
				System.out.println("Fecha fin permanencia:");
				Fecha fPermanencia = Fecha.pedirFecha();
				
				ClienteMovil cm = new ClienteMovil(nif, nombre, fNac, fAlta, fPermanencia, min, precio);
				alta(cm);
			}else //Tarifa Plana
			{
				System.out.print("Introduce nacionalidad: ");
				String nac = sc.nextLine();
				
				ClienteTarifaPlana tp = new ClienteTarifaPlana(nif, nombre, fNac, fAlta, min, nac);
				alta(tp);
			}
		}else
			System.out.print("Ya existe un Cliente con ese dni: \n" + clientes[buscarCliente(nif)].toString() + "\n\n");
	}
	
	public void baja(String nif)
	{
		int existe=buscarCliente(nif);
		
		if(existe != -1)
		{
			for(int i=existe; i<nClientes-1; i++)
				clientes[i]=clientes[i+1];
			
			nClientes--;
		}
		
		if(nClientes < clientes.length - 5){
            Cliente[] tmp = new Cliente[clientes.length-5];
            for(int i = 0; i < tmp.length; i++)
                tmp[i] = clientes[i];
            clientes = tmp;
        }
	}
	
	public void baja()
	{
		Scanner sc = new Scanner(System.in);
		
		System.out.print("Introduzca nif cliente a dar de baja: ");
		String nif = sc.nextLine();
		
		int pos=buscarCliente(nif);
		if(pos!=-1)
		{
			clientes[pos].ver();
			System.out.print("¿Seguro que desea eliminarlo (s/n)? ");
			String resp = sc.nextLine();
			
			if(resp.equals("s"))
			{
				System.out.println("El cliente " + clientes[pos].getNombre() + " con nif " + nif + " ha sido eliminado\n");
				baja(nif);
			}else
			{
				System.out.println("El cliente con nif " + nif + " no se elimina\n");
			}
		}else
			System.out.println("No existe ningun cliente con ese dni ");
	}
	
	public float factura()
	{
		float total=0;
		for(int i=0; i<nClientes; i++)
		{
			total+=clientes[i].factura();
		}
		
		return total;
	}
	
	public int nClienteMovil()
	{
		int contador=0;
		
		for(int i=0; i<nClientes; i++)
		{
			if(clientes[i].getClass()==ClienteMovil.class) //Se podría usar instanceof tambien --> clientes[i] instanceof ClienteMovil (Se puede si ClienteMovil no tiene clases derivadas)
				contador++;
		}
		
		return contador;
	}
	
	public void descuento(int dto)
	{
		for(int i=0; i<nClientes; i++)
		{
			if(clientes[i].getClass()==ClienteMovil.class)
			{
				ClienteMovil c = (ClienteMovil)clientes[i];
				c.setPrecio(c.getPrecio()-c.getPrecio()*(dto/100));
			}
		}
	}
	
	@Override
	public String toString()
	{
		String s="";
		for(int i=0; i<nClientes;i++)
			s+=clientes[i].toString() + "\n"; //el toString() no hace falta.

		return s;
	}
	
	@Override
    public Object clone(){
        Empresa obj=null;
        try{
            obj= (Empresa)super.clone();
            obj.clientes = clientes.clone();
            for(int i = 0; i < nClientes; i++)
                obj.clientes[i] = (Cliente)clientes[i].clone();
        }catch(CloneNotSupportedException ex){
            
        }
        return (Object)obj;
    }
    
 
    public void ver() {
        System.out.println(this);
    }
    
    /////////////////////////////////////////////		EXAMEN:						//////////////////////////////////
    
    //EJERCICIO 1
    public void eliminarPermanencia(float minutos)
    {
    	
    	for(int i=0;i<nClientes;i++)
    	{
    		if(clientes[i].getClass()==ClienteMovil.class)
    		{
    			ClienteMovil c=(ClienteMovil)clientes[i];
    			if(c.getMinutos()>minutos)
    			{
    				c.setFPermanencia(c.getFechaAlta());
    			}
    		}
    	}
    }
    
    
    //EJERCICIO 3
    public void bajaTPNacionalidad(String nac,int anio)
    {
    	
    	for(int i=0;i<nClientes;i++)
    	{
    		if(clientes[i].getClass()==ClienteTarifaPlana.class)
    		{
    			ClienteTarifaPlana c=(ClienteTarifaPlana)clientes[i];
    			Fecha f=(Fecha)c.getFechaAlta();
    			if(c.getNacionalidad().equals(nac) &&f.getAnio()==anio)
    			{
    				//baja(c.getNif());
    				baja(clientes[i].getNif());
    				i--;
    			}
    		}
    	}
    }
    
    
    //EJERCICIO 2
    public void listarClienteMasJoven()
    {
    	Fecha f1=(Fecha)clientes[0].getFechaNac().clone();
    	int pos=0;
    	Fecha f;
    	Cliente c[];int n=0;
    	clientes=new Cliente[0];
    	for(int i=0;i<nClientes;i++)
    	{
    		Fecha f2=(Fecha)clientes[i].getFechaNac().clone();
    		
    		if(Fecha.mayor(f2,f1))
    		{
    			f1=(Fecha)clientes[i].getFechaNac().clone();
    			pos=i;
    			
    			
    		}
    		//if(f1.equals(f2))
    		//{
    			
    		//}
    	}
    	clientes[pos].ver();
    }
    
    
}
