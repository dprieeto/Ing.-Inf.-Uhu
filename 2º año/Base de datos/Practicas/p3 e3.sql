--> P3 E3:

set serveroutput on;

create or replace procedure llamadas_cia(compa1 varchar,fecha date) is
    existe integer;
	no_llamada exception;
	n_llama integer;
	n_100_llama integer;
	n_llama_total integer;
	dura LLAMADA.duracion%type;
    
	cursor c_telefonos(compa1 varchar) is 
    select distinct t.numero from mf.telefono t inner join mf.compañia c on c.cif=t.compañia
	where c.nombre=compa1;

	cursor c_llamada(telefono TELEFONO.numero%TYPE) is 
    select ll.tf_origen	from mf.llamada ll 
    where telefono=ll.tf_origen and to_char(ll.fecha_hora,'dd/mm/aa')=to_char(fecha,'dd/mm/yy');
	
begin
	select count(*) into existe from mf.llamada ll
	where to_char(ll.fecha_hora, 'dd/mm/aa')=fecha;
	if existe=0 then
		raise no_llamada;
	end if;
	dbms_output.put_line('------------------------------------');
	dbms_output.put_line('Tlf. Origen   Num_LL  Num_100      %');
	dbms_output.put_line('------------------------------------');
	for r_telefonos in c_telefonos(compa1) loop
		n_llama:=0;
		n_100_llama:=0;
		for r_llamada in c_llamada(r_telefonos.numero) loop
			n_llama:=n_llama+1;
			select ll.duracion into dura from mf.llamada ll
			where ll.tf_origen=r_llamada.tf_origen;
			if dura>100 then
				n_100_llama:=n_100_llama+1;
			end if;
		end loop;
		n_llama_total:=n_llama_total+n_llama;
		dbms_output.put_line(r_telefonos.numero||'   '||n_llama||'    '||n_100_llama||'    '||n_100_llama/n_llama*100 );
	end loop;
	dbms_output.put_line('------------------------------------');
	dbms_output.put_line('Numero de LLamadas realizadas : '||n_llama_total);
exception
	when no_llamada then
		dbms_output.put_line('ERROR: no hay llamadas para la fecha introducida');
    when others then
    dbms_output.put_line('Error');

end llamadas_cia;
