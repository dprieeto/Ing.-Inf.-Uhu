create table COMPANIA (
cif char(9),
nombre char(20),
web char(30),
CONSTRAINT companiaClave PRIMARY KEY (cif));

create table TARIFA(
tarifa char(10),
compania char(9),
descripcion varchar(50),
coste number(3,2) NOT NULL,
CONSTRAINT tarifaClave PRIMARY KEY(tarifa,compania),
CONSTRAINT tarifaAjena FOREIGN KEY(compania)
  REFERENCES COMPANIA(cif) ON DELETE CASCADE
);

create table CLIENTE (
dni char(9),
nombre varchar(50),
f_nac date,
direccion varchar(100),
cp char(6),
ciudad varchar(50),
provincia varchar(50),
CONSTRAINT clienteClave PRIMARY KEY(dni)
);

create table TELEFONO (
numero char(9),
f_contrato date,
tipo char(1),
puntos number(6,0),
compania char(9),
tarifa char(10),
cliente char(9),
CONSTRAINT telefonoClave PRIMARY KEY (numero),
CONSTRAINT telefonoAjena1 FOREIGN KEY (tarifa,compania)
  REFERENCES TARIFA,
CONSTRAINT telefonoAjena2 FOREIGN KEY (cliente)
  REFERENCES CLIENTE(dni),
CONSTRAINT telefonoAjena3 FOREIGN KEY (compania)
  REFERENCES COMPANIA(cif),
CONSTRAINT telefonoTipo CHECK(tipo IN('T','C'))
);

create table LLAMADA(
tf_origen char(9),
tf_destino char(9),
fecha_hora timestamp,
duracion number(5,0),
CONSTRAINT llamadaClave PRIMARY KEY (tf_origen,fecha_hora),
CONSTRAINT llamadaAjena1 FOREIGN KEY (tf_origen)
  REFERENCES TELEFONO(numero),
CONSTRAINT llamadaAjena2 FOREIGN KEY(tf_destino)
  REFERENCES TELEFONO(numero),
CONSTRAINT llamadaDestUnica UNIQUE(tf_destino,fecha_hora)
);