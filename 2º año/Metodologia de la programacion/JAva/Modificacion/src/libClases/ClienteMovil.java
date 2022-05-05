package libClases;

public class ClienteMovil extends Cliente{
	
	private float minHablados;
	private float precioMin;
	private final Fecha fPermanencia;
	
	public ClienteMovil(String nif, String nombre, Fecha fNac, Fecha fAlta, Fecha fPerma, float min, float precio)
	{
		super(nif, nombre, fNac, fAlta);
		minHablados=min;
		precioMin=precio;
		fPermanencia=(Fecha)fPerma.clone();
	}

	/*public ClienteMovil(String nif, String nombre, Fecha fnac, Fecha fechaalta, float minutos, float precio)
	{
		this(nif, nombre, fnac, fechaalta, new Fecha(fechaalta.getDia(), fechaalta.getMes(), fechaalta.getAnio()+1 ), minutos, precio);
	}*/
	
	
	public ClienteMovil(String nif, String nombre, Fecha fNac, float min, float precio)
	{
		super(nif, nombre, fNac);
		fPermanencia=new Fecha(getFechaPorDefecto().getDia(), getFechaPorDefecto().getMes(), getFechaPorDefecto().getAnio()+1);
		precioMin=precio;
		minHablados=min;
	}
	
	public ClienteMovil(ClienteMovil c)
	{
		super(c);
		precioMin=c.precioMin;
		fPermanencia=(Fecha)c.fPermanencia.clone();
		minHablados=c.minHablados;
	}
	
	
	public float getMinutos()
	{
		return minHablados;
	}
	
	
	public float getPrecio()
	{
		return precioMin;
	}
	
	
	public Fecha getFPermanencia()
	{
		return (Fecha)fPermanencia.clone();
	}
	
	
	public void setMinutos(float m)
	{
		minHablados=m;
	}
	
	
	public void setPrecio(float p)
	{
		precioMin=p;
	}
	
	public void setFPermanencia(Fecha f)
	{
		fPermanencia.setFecha(f.getDia(), f.getMes(), f.getAnio());
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
		s+=super.toString() + " " + fPermanencia + " " + minHablados + " x " + precioMin + " --> " + factura(); 
		return s;
	}
	
	@Override
	public boolean equals(Object obj)
	{
		if(obj==null) //Si apunta a null
			return false;
		if(this.getClass()!=obj.getClass()) //Si son distinta clase
			return false;
		if(this==obj) //Si apuntan al mismo sitio
			return true;
		
		ClienteMovil c=(ClienteMovil)obj;
		
		return c.getNif().equals(this.getNif());
	}
	
	@Override
	public Object clone()
	{
		return new ClienteMovil(this);
	}
	
	@Override
	public float factura()
	{
		return precioMin*minHablados;
	}
}
