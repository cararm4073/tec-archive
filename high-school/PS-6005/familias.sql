use basedatos1;
CREATE TABLE familias (
    id INT NOT NULL AUTO_INCREMENT,
    nombre VARCHAR(255) NOT NULL,
    edad INT NOT NULL,
    correo VARCHAR(255) NOT NULL,
    PRIMARY KEY (`id`)
);

show databases;
show tables;
SELECT * FROM familias;


#para eliminar tablas
CREATE TABLE familias (
    id INT NOT NULL AUTO_INCREMENT,
    nombre VARCHAR(255) NOT NULL,
    edad INT NOT NULL,
    correo VARCHAR(255) NOT NULL,
    PRIMARY KEY (`id`)
);
drop table familia;
show tables;

#para eliminar database
CREATE DATABASE perro_rojo;
show databases;
drop database perro_rojo;
show databases;
	
INSERT INTO familias (nombre, edad, correo) VALUES ("Carlos", "18", "carloss@yahoo.com");
INSERT INTO familias (nombre, edad, correo) VALUES ("Fer", "17", "ferp@gmail.com");
INSERT INTO familias (nombre, edad, correo) VALUES ("María", "10", "mariaz@gmail.com");
INSERT INTO familias (nombre, edad, correo) VALUES ("Juan", "24", "juank@gmail.com");
INSERT INTO familias (nombre, edad, correo) VALUES ("Zentella", "18", "zmaria@gmail.com");
INSERT INTO familias (nombre, edad, correo) VALUES ("Oscar", "21", "oscarr@gmail.com");
INSERT INTO familias (nombre, edad, correo) VALUES ("Pablo", "19", "pablop@gmail.com");
INSERT INTO familias (nombre, edad, correo) VALUES ("Natalia", "16", "nataliar@outlook.com");
INSERT INTO familias (nombre, edad, correo) VALUES ("Ceci", "17", "cecia@gmail.com");
INSERT INTO familias (nombre, edad, correo) VALUES ("Oscar", "31", "oscars@gmail.com");
INSERT INTO familias (nombre, edad, correo) VALUES ("Marz", "79", "marzt@gmail.com");

SELECT * FROM familias;
SELECT * FROM familias where edad > 23;
SELECT * FROM familias where edad >=17;
SELECT * FROM familias where edad >=17 and email = "zmaria@gmail.com";
SELECT * FROM familias where edad >=18 or email = "nataliar@outlook.com";
SELECT * FROM familias where edad between 19 and 27;
SELECT * FROM familias where email =! "oscarr@gmail.com";
SELECT * FROM familias where email like "%gmail.com";
SELECT * FROM familias where email like "%oscar%";
SELECT * FROM familias order by edad asc;
SELECT * FROM familias order by edad desc;
SELECT max(edad) as mayor FROM familias;
SELECT min(edad) as minimo FROM familias;
SELECT id, nombre from familias;
SELECT nombre from familias;
select id, nombre as apodos FROM familias;