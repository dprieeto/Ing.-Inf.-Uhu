----->  PRACTICA 3
--> E1:
set serveroutput on; --asegura que se visualicen los mensajes por pantalla, mejor ponerlo siempre

create or replace --se poner antes de crear procedure o function
function facturacion(idtf in TELEFONO.numero%type, anio in number) return NUMBER is
coste number(5,2);
begin

return coste;
end;