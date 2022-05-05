--> E2:
set serveroutput on;
create or replace
procedure llamadaFacturacion(anio number) is

coste number(5,2);
cursor c_tf(anio number) is 
select distinct ll.tf_origen from mf.llamada ll
where extract(year from ll.fecha_hora)=anio;

begin

dbms_output.put_line('Nº tf        Importe');
dbms_output.put_line('--------------------');
for r_numeros  in c_tf(anio) loop
    coste:=facturacion(r_numeros.tf_origen,anio);
    dbms_output.put_line(r_numeros.tf_origen||'       '||coste);
end loop;

exception

when others then
dbms_output.put_line('Error');

end llamadaFacturacion;