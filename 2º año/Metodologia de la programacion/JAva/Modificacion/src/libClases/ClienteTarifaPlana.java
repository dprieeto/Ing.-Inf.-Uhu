package libClases;

public class ClienteTarifaPlana extends Cliente {
	
	private String nac;
	private float minHablados;
	
	private static float limiteMinutos=300f;
	private static float precioTarifa=20f;
	private static float EXCESO=0.15f;
	
	public ClienteTarifaPlana(String nif, String nom, Fecha fNac, Fecha fAlta, float min, String nac)
	{
		super(nif, nom, fNac, fAlta);
		minHablados=min;
		this.nac=nac;
	}
	
	public ClienteTarifaPlana(String nif, String nom, Fecha fnac, float min, String nac)
	{
		super(nif, nom, fnac);
		minHablados=min;
		this.nac=nac;
	}
	
	public ClienteTarifaPlana(ClienteTarifaPlana c)
	{
		this(c.getNif(), c.getNombre(), c.getFechaNac(), c.getFechaAlta(), c.minHablados, c.nac);
	}
	
	public String getNacionalidad()
	{
		return this.nac;
	}
	
	public float getMinutos()
	{
		return minHablados;
	}
	
	public static float getTarifa() //Precio de la tarifa
	{
		return precioTarifa;
	}
	
	public static float getLimite()
	{
		return limiteMinutos;
	}
	
	public static float getExceso()
	{
		return EXCESO;
	}
	
	public void setNacionalidad(String n)
	{
		nac=n;
	}
	
	public void setMinutos(float m)
	{
		minHablados=m;
	}
	
	public void setExceso(float e)
	{
		EXCESO=e;
	}
	
	public static void setTarifa(float min, float precio)
	{
		limiteMinutos=min;
		precioTarifa=precio;
	}
	
	@Override
	public float factura()
	{
		float importe=0;
		if(minHablados>limiteMinutos)
		{
			importe+=(minHablados-limiteMinutos)*EXCESO;
		}
		
		importe+=precioTarifa;
				
		return importe;
	}
	
	@Override
	public String toString()
	{
		String s="";
		s+=super.toString() + " " + nac + " [" + limiteMinutos + " por " + precioTarifa + "] " + minHablados + " --> " + factura();
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
