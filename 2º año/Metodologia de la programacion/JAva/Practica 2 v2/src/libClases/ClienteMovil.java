package libClases;

public class ClienteMovil extends Cliente { //'extends xxx' para declarar que es una clase heredada de 'xxx'

	private float min;//cantidad de minutos hablados
	private float precio;//preccio por minuto
	private final Fecha fPermanencia;//fecha  en la que acaba el contrato, por eso final
									//si no se indica durara 1 año la permanencia
	
	
	public ClienteMovil(String nif,String nom,Fecha nac,Fecha alta,Fecha permanencia,float min,float precio)
	{
		super(nif,nom,nac,alta);//super se usa para llamar al constructor de Cliente
		this.min=min;
		this.precio=precio;
		//this.fPermanencia=new Fecha(permanencia);
		this.fPermanencia=(Fecha)permanencia.clone(); //tb vale asi
	}
	
	public ClienteMovil(String nif,String nom,Fecha nac,float min,float precio)
	{
		super(nif,nom,nac);
		this.min=min;
		this.precio=precio;
		this.fPermanencia=new Fecha(super.getFechaPorDefecto().getDia(),super.getFechaPorDefecto().getMes(),super.getFechaPorDefecto().getAnio()+1);
	}
	
	public ClienteMovil(ClienteMovil c)
	{
		super(c);
		this.precio=c.precio;
		this.min=c.min;
		this.fPermanencia=new Fecha(c.fPermanencia);
	}
	
	public Fecha getFPermanencia() {return new Fecha(fPermanencia);}
	
	public float getMinutos() {return this.min;}

	public float getPrecio() {return this.precio;}
	
	public void setMinutos(float min)
	{
		this.min=min;
	}
	
	public void setPrecio(float precio)
	{
		this.precio=precio;
	}
	
	public void setFPermanencia(Fecha f)
	{
		this.fPermanencia.setFecha(f.getDia(), f.getMes(), f.getAnio());
	}
	
	public float factura() {return this.precio*this.min;}
	
	@Override
	public void ver()
	{
		System.out.println(this);
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
	public String toString()
	{
		String s="";
		s+=super.toString()+" "+this.fPermanencia+" "+this.min+" x "+this.precio+" --> "+this.factura();
		return s;
	}
	
	
	
	
	
}
