package libClases;

public class Cliente implements Cloneable, Proceso { //Para que funcione la parte 1 hay que quitar el abstract, ya que al ser abstract no permite la creación de objetos de la clase Cliente.

	private String nombre;
	private String dni;
	private final Fecha fechaNac;
	private final Fecha fechaAlta;
	private int codCliente;
	
	private static final Fecha fechaAltaPorDefecto = new Fecha(1, 1, 2018);
	private static int contador=1;
	
	
	public Cliente(String nif, String nombre, Fecha fNac, Fecha fAlta)
	{
		dni=nif;
		this.nombre=nombre;
		fechaNac=(Fecha)fNac.clone();
		fechaAlta=(Fecha)fAlta.clone();
		codCliente=contador++;
	}
	
	public Cliente(Cliente c)
	{
		this(c.dni, c.nombre, c.fechaNac, c.fechaAlta); //Llama al constructor de arriba
	}
	
	public Cliente (String nif, String nom, Fecha fNac)
	{
		this(nif, nom, fNac, fechaAltaPorDefecto);
	}
	
	public final int getCodCliente()
	{
		return codCliente;
	}
	
	
	public final String getNombre()
	{
		return this.nombre;
	}
	
	public final String getNif()
	{
		return this.dni;
	}
	
	public final Fecha getFechaNac()
	{
		return (Fecha)fechaNac.clone();
	}
	
	public final Fecha getFechaAlta()
	{
		return (Fecha)fechaAlta.clone();
	}
	
	public final static Fecha getFechaPorDefecto()
	{
		return (Fecha)fechaAltaPorDefecto.clone();
	}
	
	public void setNombre(String nom)
	{
		nombre=nom;
	}

	public void setNif(String nif)
	{
		dni=nif;
	}
	
	public void setFechaNac(Fecha f)
	{
		this.fechaNac.setFecha(f.getDia(), f.getMes(), f.getAnio());
	}
	
	public void setFechaAlta(Fecha f)
	{
		this.fechaAlta.setFecha(f.getDia(), f.getMes(), f.getAnio());
	}
	
	public static void setFechaPorDefecto(Fecha f)
	{
		fechaAltaPorDefecto.setFecha(f.getDia(), f.getMes(), f.getAnio());
	}
	
	@Override
	public void ver()
	{
		System.out.println(this);
	}
	
	@Override
	public String toString()
	{
		String s="";
		s+=this.dni + " " + this.fechaNac + ": " + this.nombre + " (" + codCliente + " - " + this.fechaAlta + ")"; 
		return s;
	}
	
	@Override
	public boolean equals(Object obj)
	{
		if(this==obj) //Si apuntan al mismo sitio
			return true;
		if(this.getClass()!=obj.getClass()) //Si no son del mismo tipo
			return false;
		if(obj.getClass()==null) //Si obj apunta a null
			return false;
			
		Cliente c = (Cliente)obj;
		return c.dni.equals(this.dni); //c.dni==this.dni no sirve, ya que dice si apuntan o no al mismo sitio
      //obj instanceof Cliente -->No sirve porque si es clase Derivada de Cliente, diría true. Y no estaría bien.
	}
	
	@Override
	public Object clone() 
	{
		return new Cliente(this);
	}
	
	public float factura() //Mirar luego
	{
		throw new UnsupportedOperationException("No se puede facturar un cliente sin tarifa.");
	}
}
