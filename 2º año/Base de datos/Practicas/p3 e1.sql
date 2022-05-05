----->  PRACTICA 3
--> E1:

set serveroutput on;
-- asegura que se visualicen los mensajes por pantalla, mejor ponerlo siempre

create or replace 
--se poner antes de crear procedure o function
function facturacion(idtelefono TELEFONO.numero%TYPE, anio number) return number is
	factbaja exception;
	coste number(5,2);
begin
	
	select sum((ll.duracion/60)*t.coste) into coste --//ll=llamada 
	from (mf.tarifa t inner join mf.telefono tl using(tarifa,compañia))
		inner join mf.llamada ll on ll.tf_origen=tl.numero
	where ll.tf_origen=idtelefono and extract(year from fecha_hora)=anio;

	if coste<1 then
		raise factbaja;
	end if;
	return coste;

exception
	
	when factbaja then
		dbms_output.put_line('Error: Facturacion baja');
	when NO_DATA_FOUND then 
		dbms_output.put_line('Error: no se ha encontrado el telefono');
	when OTHERS then
		dbms_output.put_line('ERROR');
END facturacion;
-- ejecutar lo siguiente en una hoja aparte:
-- call dbms_output.put_line(facturacion('654123321', 2006));


