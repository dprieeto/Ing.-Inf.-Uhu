package libClases;

public class ClienteTarifaPlana extends Cliente { //extends xxx para declara que es una clase heredada de xxx

	private static float limiteMinutos=300f;
	private static float exceso=0.15f;
	private static float precioTarifa=20f;
	private  String nacionalidad;
	private float min;
	
	
	public ClienteTarifaPlana(String nif,String nombre,Fecha nac,Fecha alta,float min,String nacionalidad)
	{
		super(nif,nombre,nac,alta);
		this.min=min;
		this.nacionalidad=nacionalidad;
	}
	
	public ClienteTarifaPlana(String nif,String nom,Fecha nac,float min, String nacionalidad)
	{
		super(nif,nom,nac);
		this.min=min;
		this.nacionalidad=nacionalidad;
	}
	
	public ClienteTarifaPlana(ClienteTarifaPlana c)
	{
		super(c);
		this.min=c.min;
		this.nacionalidad=c.nacionalidad;
		//this(c.getNif(), c.getNombre(), c.getFechaNac(), c.getFechaAlta(), c.minHablados, c.nac);//tb vale esto
	}
	
	public String getNacionalidad() {return this.nacionalidad;}
	
	public float getMinutos() {return this.min;}
	
	public static float getTarifa() {return precioTarifa;}
	
	public static float getExceso() {return exceso;}
	
	public static float getLimite() {return limiteMinutos;}
	
	//public float factura() {return (precioTarifa+(exceso*(min-limiteMinutos)));}
	public float factura()
	{
		float precio=0;
		if(min>limiteMinutos)
		{
			precio+=(min-limiteMinutos)*exceso;
		}
		precio+=precioTarifa;
		return precio;
	}
	
	public void setNacionalidad(String nacionalidad)
	{
		this.nacionalidad=nacionalidad;
	}
	
	public void setMinutos(float min)
	{
		this.min=min;
	}
	 
	public static void setExceso(float ex)
	{
		exceso=ex;
	}
	
	public static void setTarifa(float min,float precio)
	{
		precioTarifa=precio;
		limiteMinutos=min;
	}
	
	@Override
	public String toString()
	{
		String s="";
		s+=super.toString()+" "+this.nacionalidad+" ["+limiteMinutos+" por "+precioTarifa+"] "+this.min+" --> "+this.factura();
		return s;
	}
	
	@Override
	public Object clone()
	{
		return new ClienteTarifaPlana(this);
	}
	
	@Override
	public boolean equals(Object obj)
	{
		if(this==obj) //Si apuntan al mismo sitio
			return true;
		if(this.getClass()!=obj.getClass()) //Si son de distinto tipo --> Aqui ya comprueba que sean del mismo tipo.
			return false;
		if(obj==null) //Si obj apunta a nulo
			return false;
		
		ClienteTarifaPlana c = (ClienteTarifaPlana)obj;
		
		return c.getNif().equals(this.getNif());
	}
	
	@Override
	public void ver()
	{
		System.out.println(this);
	}
	
	
	
	
	
	
}
