package libClases;

public class Cliente implements Cloneable, Proceso {
	
	private final String nif; //dni del cliente (letra incluida) (NO puede cambiar)
	 private final int codCliente; //codigo único (y fijo) generado por la aplicación
	 private  String nombre; //nombre completo del cliente (SI se puede modificar)
	 private final Fecha fechaNac; //fecha nacimiento del cliente (NO se puede cambiar)
	 // No se puede cambiar=no tiene un set
	 private final Fecha fechaAlta; //fecha de alta del cliente (SI se puede modificar) 
	 //Si se pued ecambiar = hay q crear un void setFechaAlta
	 
	 private static final Fecha fechaAltaPorDefecto = new Fecha(1, 1, 2018); //fecha de alta por defecto ya q no se indica en el constructor
	 private static int contador=1;//para el codigo del cliente
	 
	 public Cliente (String NIF, String nom, Fecha fNac, Fecha fAlta) //constructor
	 {
		 this.nif=NIF;
		 this.nombre=nom;
		 this.fechaNac=new Fecha(fNac);
		 this.fechaAlta=new Fecha(fAlta);
		 this.codCliente=contador++;
	 }
	 
	 public Cliente (String NIF, String nom, Fecha fNac) //constructor
	 {
		this(NIF,nom,fNac,fechaAltaPorDefecto);//al no meter la fecha de alta metemos la de por defecto: /01/01/2018/ 
	 }
	 
	 public Cliente(Cliente c)
	 {
		 this(c.nif,c.nombre,c.fechaNac,c.fechaAlta);
	 }
	 
	 public final int getCodCliente(){return codCliente;}
	 
	 public final String getNombre() {return this.nombre;}
	 
	 public final String getNif() {return this.nif;}
	 
	 //public final Fecha getFechaNac() {return new Fecha(fechaNac);}//hay q pasar una copia de la fecha
	 public final Fecha getFechaNac() {return (Fecha)fechaNac.clone();}
	 
	 //public final Fecha getFechaAlta(){return new Fecha(fechaAlta);}//se pasa una copia de la fecha
	 public final Fecha getFechaAlta(){return (Fecha)fechaAlta.clone();}
	 
	 //public final static Fecha getFechaPorDefecto() {return new Fecha(fechaAltaPorDefecto);}
	 public final static Fecha getFechaPorDefecto() {return (Fecha)fechaAltaPorDefecto.clone();}
	 
	 public void setNombre(String nom)
	 {
		 this.nombre=nom;
	 }
	 
	 public void setFechaAlta(Fecha f)
	 {
		 this.fechaAlta.setFecha(f.getDia(),f.getMes(),f.getAnio());
	 }
	 
	 public static void setFechaPorDefecto(Fecha f)
	 {
		 fechaAltaPorDefecto.setFecha(f.getDia(),f.getMes(),f.getAnio());
	 }
	 public float factura()
	 {
		 throw new UnsupportedOperationException("No se puede facturar un cliente sin tarifa.");
		 //return 0;//tb vale esto		 
	 }
	 
	 @Override //sirve para forzar al compilador y para evitar errores de compilacion
	 public String toString() //devuelve una cadena con la información del cliente
	 {
		 String s="";
		 s+=this.nif+" "+this.fechaNac+": "+this.nombre+" ("+this.codCliente+" - "+this.fechaAlta+") ";
		 return s;
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
		 return new Cliente(this);
	 }
	 
	 @Override
	 public void ver()
	 {
		System.out.println(this); 
	 }
	 
	 @Override
	 public boolean equals(Object obj) //true si son iguales
	 {
			if(this==obj) //Si apuntan al mismo sitio
				return true;
			if(this.getClass()!=obj.getClass()) //Si no son del mismo tipo
				return false;
			if(obj.getClass()==null) //Si obj apunta a null
				return false;
				
			Cliente c = (Cliente)obj;
			return c.nif.equals(this.nif); //c.dni==this.dni no sirve, ya que dice si apuntan o no al mismo sitio
	      //obj instanceof Cliente -->No sirve porque si es clase Derivada de Cliente, diría true. Y no estaría bien.
	 }
	 
	 
}
