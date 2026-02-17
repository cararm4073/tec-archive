-- Crear la base de datos 1 ó a
CREATE DATABASE basedatos1;
USE basedatos1;

-- Crear la tabla familia en la base de datos original
CREATE TABLE familia (
    id INT AUTO_INCREMENT PRIMARY KEY,
    nombre VARCHAR(50),
    edad INT,
    parentesco VARCHAR(50)
);

-- Insertar datos en la tabla familia
INSERT INTO familia (nombre, edad, parentesco) VALUES
('Juan', 45, 'Padre'),
('Ana', 43, 'Madre'),
('Luis', 20, 'Hermano');

-- Crear la base de datos 2 o b
CREATE DATABASE basedatos1_2;
USE basedatos1_2;

-- Crear la tabla amigos
CREATE TABLE amigos (
    id INT AUTO_INCREMENT PRIMARY KEY,
    nombre VARCHAR(50),
    edad INT,
    ciudad VARCHAR(50)
);

-- Insertar datos en la tabla amigos
INSERT INTO amigos (nombre, edad, ciudad) VALUES
('Pedro', 22, 'Ciudad A'),
('María', 21, 'Ciudad B'),
('Jorge', 23, 'Ciudad C');

-- Crear la base de datos 3 o c
CREATE DATABASE basedatos1_3;
USE basedatos1_3;

-- Crear la tabla mascotas
CREATE TABLE mascotas (
    id INT AUTO_INCREMENT PRIMARY KEY,
    nombre VARCHAR(50),
    especie VARCHAR(50),
    edad INT
);

-- Insertar datos en la tabla mascotas
INSERT INTO mascotas (nombre, especie, edad) VALUES
('Max', 'Perro', 5),
('Luna', 'Gato', 3),
('Nemo', 'Pez', 1);