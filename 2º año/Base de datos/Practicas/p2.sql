-- ei-8:
select a.nombre as Asignatura, b.nombre as Profesor
from ei.asignatura a inner join ei.profesor b on a.prof=b.npr;

-- ei-9:
select m.alum
from ei.asignatura a inner join ei.matricula m using(idAsig)
where a.nombre='Bases de Datos I' and m.año=2002;

-- ei-10:
select al.nombre
from (ei.asignatura a inner join ei.matricula m using(idAsig)) 
inner join ei.alumno al on al.nAl=m.alum
where a.nombre='Algoritmos y Estructuras de Datos I' and m.feb_jun>=5 and m.año=2001;

-- ei-11:
select distinct despacho 
from ei.profesor p1 inner join ei.profesor p2 using(despacho) 
where p1.nombre<>p2.nombre;

-- ei-12:
select a.nombre
from (ei.asignatura a inner join ei.profesor p on a.prof=p.npr) inner join ei.matricula m using(idAsig) 
where p.nombre='Dolores Toscano Barriga';

-- ei-13:
select al.nombre
from (ei.matricula m inner join ei.asignatura a using(idAsig)) inner join ei.alumno al on al.nAl=m.alum
where a.nombre='Bases de Datos I' and m.año=2002 and m.dic is null and (m.feb_jun>=5 or m.sep>=5);

-- mf-5:
select * from mf.tarifa;
select * from mf.compañia;
select t.tarifa, t.coste, c.nombre --es la solucion pero no saca nada
from mf.compañia c inner join mf.tarifa t on c.cif=t.compañia
where t.descripcion like '%compañia%';

-- mf-6:
select c.nombre, tl.numero
from (mf.cliente c inner join mf.telefono tl on c.dni=tl.cliente) inner join mf.tarifa t using(tarifa,compañia)
where tl.tipo='C' and t.coste<0.2;

-- mf-7:
select tarifa, c.nombre, tl.numero, tl.puntos --tf.tarifa da error
from (mf.tarifa tf inner join mf.compañia c on tf.compañia=c.cif) inner join mf.telefono tl using(tarifa,compañia)
where extract(year from tl.f_contrato)=2006 and tl.puntos>200;

-- mf-8:
select ll.tf_origen, ll.tf_destino, tf.tipo
from (mf.llamada ll inner join mf.telefono tf on ll.tf_origen=tf.numero) inner join mf.telefono tf1 on tf1.numero=ll.tf_destino
where extract(hour from ll.fecha_hora)>=8 and extract(hour from ll.fecha_hora)<=10;


-- mf-9:

-- ei-14:
select al.nombre
from ei.alumno al
where al.lugar=(select al.lugar from ei.alumno ai where ai.nombre='Samuel Toscano Villegas')
and al.nh=(select al.nh from ei.alumno ai where ai.nombre='Beatriz Rico Vázquez');

-- ei-15:
select al.nombre --si pongo el in y el not in al reves en la subconsultas respectivamente no sale nada
from ei.alumno al
where al.nal not in (select m.alum from ei.asignatura inner join ei.matricula m  using(idAsig)
	where nombre='Bases de Datos II')
and al.nal in (select m.alum from ei.asignatura inner join ei.matricula m  using(idAsig)
	where nombre='Bases de Datos I');
    
    
-- ei-16:
select nombre
from ei.profesor
where ant<any(select p1.ant from ei.profesor p1 where p1.despacho='FC-7366' and p1.despacho<>'FC-7366');

-- ei-17:
select nombre
from ei.alumno
where nal=(select m.alum from ei.matricula m inner join ei.asignatura a using(idAsig)
            where m.sep>all(select m.feb_jun from ei.matricula m where feb_jun is not null)
            and m.año=2002 and a.nombre='Bases de Datos I');
            
-- mf-10:
select ll.duracion,to_char(ll.fecha_hora, 'dd/mm/yy') as Fecha
from mf.llamada ll
where ll.duracion>=all(select distinct duracion from mf.llamada);

-- mf-11:
select c.nombre
from (mf.cliente c inner join mf.telefono tf on c.dni=tf.cliente) inner join mf.compañia cp on cp.cif=tf.compañia
where cp.nombre='Aotra'
and tf.tarifa=(select tarifa from mf.telefono where numero='654123321');

-- mf-12:
select distinct tf.numero, to_char(tf.f_contrato, 'dd/mm/yy') as Fecha, tf.tipo --si no se pone disntic en numero se rpeite
from mf.telefono tf inner join mf.llamada ll on tf.numero=ll.tf_origen
where to_char(ll.fecha_hora, 'mm/yy')='10/06'
and ll.tf_destino not in(select t.numero from mf.telefono t inner join mf.cliente c on t.cliente=c.dni
                        where c.provincia='La Coruña');

-- mf-13:
select nombre
from mf.cliente
where dni in(select cliente from mf.telefono where tarifa='dúo')
and dni not in(select cliente from mf.telefono where tarifa='autónomos');

-- mf-14:
select c.nombre, tf.numero
from mf.cliente c inner join mf.telefono tf on c.dni=tf.cliente
where tf.numero in(
;

-- mf-15:


-- mf-16:


-- ei-18:
select despacho
from ei.profesor p
where not exists(select * from ei.asignatura a where p.nPr=a.prof);

-- ei-19:
select al.nombre
from ei.alumno al
where exists(select * from ei.matricula m where al.nAl=m.alum and (m.año=2000 or m.año=2002))
and not exists(select * from ei.matricula m where al.nAl=m.alum and m.año=2001);


-- ei-21:
select p.nombre as Profesores,a.nombre as Asignaturas
from ei.profesor p left inner join ei.asignatura a on p.nPr=a.prof;