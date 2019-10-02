--- Script de la base de datos (tablas, vistas, relaciones).

--- Creación de la BASE DE DATOS:
CREATE DATABASE final_project_db ENCODING 'utf8';

--- Definición de TIPOS y DOMINIOS:
CREATE TYPE enumPosition AS ENUM('GENERAL', 'ENGINEER', 'MANAGER');
CREATE DOMAIN bonus DECIMAL(7,2) CHECK(VALUE >= 30000.00 AND VALUE <= 40000.00);
CREATE DOMAIN license_plate VARCHAR(8);
CREATE DOMAIN serial_number VARCHAR(8);

--- Creación de TABLAS y RELACIONES (claves foráneas):
CREATE TABLE IF NOT EXISTS employees (
  id SERIAL PRIMARY KEY,
  name VARCHAR(45) NOT NULL,
  entry_date DATE NOT NULL,
  position enumPosition NOT NULL DEFAULT 'GENERAL'
);

CREATE TABLE IF NOT EXISTS managers (
  id SERIAL PRIMARY KEY,
  employee_id INT NOT NULL,
  start_date DATE NOT NULL,
  bonus bonus NOT NULL
);

ALTER TABLE managers 
    ADD CONSTRAINT fk_managers_employees
    FOREIGN KEY (employee_id) 
    REFERENCES employees (id);

CREATE TABLE IF NOT EXISTS vehicles (
  license_plate license_plate NOT NULL PRIMARY KEY,
  serial_number serial_number NOT NULL
);

CREATE TABLE IF NOT EXISTS manager_has_vehicle (
  manager_id INT NOT NULL,
  vehicle_license_plate license_plate NOT NULL
);

ALTER TABLE manager_has_vehicle 
    ADD CONSTRAINT fk_manager_has_vehicle_manager
    FOREIGN KEY (manager_id) 
    REFERENCES managers (id)
    ON DELETE CASCADE;

ALTER TABLE manager_has_vehicle 
    ADD CONSTRAINT fk_manager_has_vehicle_vehicle
    FOREIGN KEY (vehicle_license_plate) 
    REFERENCES vehicles (license_plate)
    ON DELETE CASCADE;

CREATE TABLE IF NOT EXISTS specialties (
  id SERIAL PRIMARY KEY,
  name VARCHAR(45) NOT NULL
);

CREATE TABLE IF NOT EXISTS categories (
  id SERIAL PRIMARY KEY,
  name VARCHAR(45) NOT NULL
);

CREATE TABLE IF NOT EXISTS engineers (
  id SERIAL PRIMARY KEY,
  employee_id INT NOT NULL,
  specialty_id INT NOT NULL,
  category_id INT NOT NULL
);

ALTER TABLE engineers 
    ADD CONSTRAINT fk_engineers_employees
    FOREIGN KEY (employee_id) 
    REFERENCES employees (id);

ALTER TABLE engineers 
    ADD CONSTRAINT fk_engineer_specialty
    FOREIGN KEY (specialty_id) 
    REFERENCES specialties (id);

ALTER TABLE engineers 
    ADD CONSTRAINT fk_engineer_category
    FOREIGN KEY (category_id) 
    REFERENCES categories (id);

CREATE TABLE IF NOT EXISTS projects (
  id SERIAL PRIMARY KEY,
  name VARCHAR(45) NOT NULL,
  start_date DATE NOT NULL
);

CREATE TABLE IF NOT EXISTS engineers_has_projects (
  id SERIAL PRIMARY KEY,
  engineer_id INT NOT NULL,
  project_id INT NOT NULL,
  assignment_date DATE NOT NULL,
  hours_per_week DECIMAL(5,2) NOT NULL
);

ALTER TABLE engineers_has_projects 
    ADD CONSTRAINT fk_engineers_has_projects_engineer
    FOREIGN KEY (engineer_id) 
    REFERENCES engineers (id);

ALTER TABLE engineers_has_projects 
    ADD CONSTRAINT fk_engineers_has_projects_project
    FOREIGN KEY (project_id) 
    REFERENCES projects (id);

CREATE TABLE IF NOT EXISTS employee_history (
  id_history SERIAL PRIMARY KEY,
  log_date DATE NOT NULL,
  employee_id INT NOT NULL,
  name VARCHAR(45) NOT NULL,
  entry_date DATE NOT NULL
);

CREATE TABLE IF NOT EXISTS manager_history (
  id_history SERIAL PRIMARY KEY,
  log_date DATE NOT NULL,
  employee_id INT NOT NULL,
  name VARCHAR(45) NOT NULL,
  entry_date DATE NOT NULL,
  start_date DATE NOT NULL,
  bonus bonus NOT NULL,
  license_plate license_plate DEFAULT NULL
);

CREATE TABLE IF NOT EXISTS engineer_history (
  id_history SERIAL PRIMARY KEY,
  log_date DATE NOT NULL,
  employee_id INT NOT NULL,
  name VARCHAR(45) NOT NULL,
  entry_date DATE NOT NULL,
  specialty VARCHAR(45) NOT NULL,
  category VARCHAR(45) NOT NULL
);

CREATE TABLE IF NOT EXISTS projects_and_engineers_history (
  id_history SERIAL PRIMARY KEY,
  log_date DATE NOT NULL,
  engineer_id INT NOT NULL,
  project_id INT NOT NULL,
  assignment_date DATE NOT NULL,
  hours_per_week DECIMAL(5,2) NOT NULL
);

--- Inserción de "DATOS INICIALES" en la base de datos:
INSERT INTO vehicles (license_plate, serial_number) 
VALUES	('AAA001', 'A12345'),
        ('AAA002', 'B12345'),
        ('AAA003', 'C12345');

INSERT INTO projects (name, start_date) 
VALUES	('PROY UNO', '2019-01-02'),
	      ('PROY DOS', '2019-03-01'),
	      ('PROY TRES', '2019-05-01'),
	      ('PROY CUATRO', '2019-07-01');

INSERT INTO specialties (name)
VALUES	('ELECTRÓNICA'),
	      ('MECATRÓNICA'),
	      ('MECÁNICA'),
	      ('INDUSTRIAL'),
	      ('SOFTWARE'),
	      ('SERVIDORES Y REDES');

INSERT INTO categories (name)
VALUES	('JUNIOR'),
	      ('SENIOR');

--- Creación de VISTAS:
CREATE VIEW v_employees AS
	SELECT id AS employee_id, name, entry_date 
  FROM employees
  WHERE position = 'GENERAL'
  ORDER BY id ASC;

CREATE VIEW v_managers AS
	SELECT employee_id, name, entry_date, start_date, bonus, license_plate
	FROM managers m
	INNER JOIN employees e
		ON e.id = m.employee_id
	LEFT JOIN manager_has_vehicle m_h_v
		ON m_h_v.manager_id = m.id
	LEFT JOIN vehicles v
		ON v.license_plate = m_h_v.vehicle_license_plate
	ORDER BY employee_id ASC;

CREATE VIEW v_engineers AS
  SELECT employee_id, emp.name, entry_date, s.name AS specialty, c.name AS category
  FROM engineers eng
  INNER JOIN employees emp
    ON emp.id = eng.employee_id
  INNER JOIN specialties s 
    ON s.id = eng.specialty_id
  INNER JOIN categories c 
    ON c.id = eng.category_id
  ORDER BY employee_id ASC;

--- Creación de PROCEDIMIENTOS ALMACENADOS y TRIGGERS:

--- Procedimiento almacenado y Trigger para la inserción de EMPLEADOS (generales):
CREATE OR REPLACE FUNCTION funcInsertEmployee() RETURNS TRIGGER AS $$
BEGIN
	INSERT INTO employees (name, entry_date, position) VALUES(NEW.name, NEW.entry_date, 'GENERAL');
	RETURN NEW;
END
$$ LANGUAGE 'plpgsql';

CREATE TRIGGER triggerInsertEmployee INSTEAD OF INSERT 
	ON v_employees
	FOR EACH ROW
	EXECUTE PROCEDURE funcInsertEmployee();

CREATE OR REPLACE FUNCTION insertEmployee(_name VARCHAR(45), _entry_date DATE) RETURNS INT AS $$
BEGIN
  BEGIN
    INSERT INTO v_employees (name, entry_date) VALUES(_name, _entry_date);
  EXCEPTION
    WHEN others THEN
      RETURN 9;
  END;

  RETURN 0;
END
$$ LANGUAGE 'plpgsql';

--- Procedimiento almacenado y Trigger para la eliminación de EMPLEADOS (generales):
CREATE OR REPLACE FUNCTION funcDeleteEmployee() RETURNS TRIGGER AS $$
BEGIN
  INSERT INTO employee_history (log_date, employee_id, name, entry_date)
    SELECT NOW()::DATE AS log_date, *
    FROM v_employees
    WHERE employee_id = OLD.employee_id FOR UPDATE;

  DELETE FROM employees WHERE id = OLD.employee_id;
	RETURN OLD;
END
$$ LANGUAGE 'plpgsql';

CREATE TRIGGER triggerDeleteEmployee INSTEAD OF DELETE 
	ON v_employees
	FOR EACH ROW
	EXECUTE PROCEDURE funcDeleteEmployee();

CREATE OR REPLACE FUNCTION deleteEmployee(_employee_id INT) RETURNS INT AS $$
BEGIN
  BEGIN
    IF NOT EXISTS(SELECT * FROM v_employees WHERE employee_id = _employee_id FOR UPDATE) THEN
      RETURN 1;
    END IF;

    DELETE FROM v_employees WHERE employee_id = _employee_id;
  EXCEPTION
    WHEN others THEN
      RETURN 9;
  END;

  RETURN 0;
END
$$ LANGUAGE 'plpgsql';

--- Procedimiento almacenado y Trigger para la inserción de GERENTES:
CREATE OR REPLACE FUNCTION funcInsertManager() RETURNS TRIGGER AS $$
DECLARE
	var_employee_id INT := 0;
BEGIN
	IF NEW.entry_date >= NEW.start_date THEN
		RAISE EXCEPTION 'La fecha de inicio de gerencia debe ser posterior o el mismo día que la fecha de ingreso como empleado.';
	END IF;

  IF NEW.employee_id IS NULL THEN
    INSERT INTO employees (name, entry_date, position) 
      VALUES (NEW.name, NEW.entry_date, 'MANAGER')
      RETURNING id INTO var_employee_id;
  ELSE
    var_employee_id := NEW.employee_id;
  END IF;

	INSERT INTO managers (employee_id, start_date, bonus)
		VALUES(var_employee_id, NEW.start_date, NEW.bonus);

	BEGIN
		IF EXISTS(SELECT * FROM v_managers WHERE license_plate = NEW.license_plate) THEN
			RAISE EXCEPTION 'El vehículo ya ha sido previamente asignado a un gerente.';
		END IF;
		
		INSERT INTO manager_has_vehicle (manager_id, vehicle_license_plate)
			SELECT id, NEW.license_plate AS license_plate
			FROM managers
			WHERE employee_id = var_employee_id FOR UPDATE;
	EXCEPTION
		WHEN undefined_column THEN
		WHEN not_null_violation THEN
	END;

	RETURN NEW;
END
$$ LANGUAGE 'plpgsql';

CREATE TRIGGER triggerInsertManager INSTEAD OF INSERT 
	ON v_managers
	FOR EACH ROW
	EXECUTE PROCEDURE funcInsertManager();

CREATE OR REPLACE FUNCTION insertManager(_name VARCHAR(45), _entry_date DATE, _start_date DATE, _bonus bonus, _license_plate license_plate) RETURNS INT AS $$
BEGIN
  BEGIN
    INSERT INTO v_managers (name, entry_date, start_date, bonus, license_plate) 
      VALUES(_name, _entry_date, _start_date, _bonus, _license_plate);
  EXCEPTION
    WHEN others THEN
      RETURN 9;
  END;

  RETURN 0;
END
$$ LANGUAGE 'plpgsql';

--- Procedimiento almacenado y Trigger para la eliminación de GERENTES:
CREATE OR REPLACE FUNCTION funcDeleteManager() RETURNS TRIGGER AS $$
BEGIN
	INSERT INTO manager_history (log_date, employee_id, name, entry_date, start_date, bonus, license_plate)
		SELECT NOW()::DATE AS log_date, * 
		FROM v_managers
		WHERE employee_id = OLD.employee_id;

	DELETE FROM managers WHERE employee_id = OLD.employee_id;
	UPDATE employees SET position = 'GENERAL' WHERE id = OLD.employee_id; 
	RETURN OLD;
END
$$ LANGUAGE 'plpgsql';

CREATE TRIGGER triggerDeleteManager INSTEAD OF DELETE 
	ON v_managers
	FOR EACH ROW
	EXECUTE PROCEDURE funcDeleteManager();

CREATE OR REPLACE FUNCTION deleteManager(_employee_id INT) RETURNS INT AS $$
BEGIN
  BEGIN
    IF NOT EXISTS(SELECT * FROM v_managers WHERE employee_id = _employee_id) THEN
      RETURN 1;
    END IF;

    DELETE FROM v_managers WHERE employee_id = _employee_id;
  EXCEPTION
    WHEN others THEN
      RETURN 9;
  END;

  RETURN 0;
END
$$ LANGUAGE 'plpgsql';

--- Procedimiento almacenado y Trigger para la inserción de INGENIEROS:
CREATE OR REPLACE FUNCTION funcInsertEngineer() RETURNS TRIGGER AS $$
DECLARE
	var_employee_id INT := 0;
  var_specialty_id INT := 0;
  var_category_id INT := 0;
BEGIN

  IF NEW.employee_id IS NULL THEN
    INSERT INTO employees (name, entry_date, position) 
      VALUES (NEW.name, NEW.entry_date, 'ENGINEER')
      RETURNING id INTO var_employee_id;
  ELSE 
    var_employee_id := NEW.employee_id;
  END IF;

  SELECT id INTO var_specialty_id FROM specialties 
  WHERE name = NEW.specialty;

  IF var_specialty_id IS NULL THEN
    RAISE EXCEPTION 'La especialidad ingresada es inválida.';
  END IF;

  SELECT id INTO var_category_id FROM categories 
  WHERE name = NEW.category;

  IF var_category_id IS NULL THEN
    RAISE EXCEPTION 'La categoría ingresada es inválida.';
  END IF;

  INSERT INTO engineers (employee_id, specialty_id, category_id)
		VALUES(var_employee_id, var_specialty_id, var_category_id);
  
  RETURN NEW;
END
$$ LANGUAGE 'plpgsql';

CREATE TRIGGER triggerInsertEngineer INSTEAD OF INSERT 
	ON v_engineers
	FOR EACH ROW
	EXECUTE PROCEDURE funcInsertEngineer();

CREATE OR REPLACE FUNCTION insertEngineer(_name VARCHAR(45), _entry_date DATE, _specialty VARCHAR(45), _category VARCHAR(45)) RETURNS INT AS $$
BEGIN
  BEGIN
    INSERT INTO v_engineers (name, entry_date, specialty, category) 
      VALUES(_name, _entry_date, _specialty, _category);
  EXCEPTION
    WHEN others THEN
      RETURN 9;
  END;

  RETURN 0;
END
$$ LANGUAGE 'plpgsql';

--- Procedimiento almacenado para ASIGNAR INGENIERO A PROYECTO: 
CREATE OR REPLACE FUNCTION assignEngineerToProject(_employee_id INT, _project_id INT, _assignment_date DATE, _hours_per_week DECIMAL(5,2)) RETURNS INT AS $$
DECLARE
  var_engineer_id INT := 0;
  var_projects_counter INT := 0;
  var_hours_per_week DECIMAL(5, 2) := 0.0;
BEGIN
  BEGIN
    IF NOT EXISTS(SELECT * FROM v_engineers WHERE employee_id = _employee_id FOR UPDATE) THEN
      RETURN 1;
    END IF;

    SELECT id INTO var_engineer_id FROM engineers WHERE employee_id = _employee_id;

    IF EXISTS(SELECT * FROM engineers_has_projects WHERE engineer_id = var_engineer_id AND project_id = _project_id) THEN
      RAISE EXCEPTION 'No es posible asignar un ingeniero al mismo proyecto más de una vez.';
    END IF;

    SELECT COUNT(DISTINCT id) INTO var_projects_counter
    FROM engineers_has_projects 
    WHERE engineer_id = var_engineer_id;

    SELECT sum(hours_per_week) INTO var_hours_per_week 
    FROM engineers_has_projects 
    WHERE engineer_id = var_engineer_id; 

    IF (var_projects_counter + 1) > 3 THEN
      RAISE EXCEPTION 'Un ingeniero no puede ser asignado a más de tres proyectos a la vez.';
    END IF;

    IF (var_hours_per_week + _hours_per_week) > 40 THEN
      RAISE EXCEPTION 'La suma total de las horas por semana asignadas al ingeniero en los diversos proyectos no debe ser mayor a 40.';
    END IF;

    INSERT INTO engineers_has_projects (engineer_id, project_id, assignment_date, hours_per_week)
      VALUES(var_engineer_id, _project_id, _assignment_date, _hours_per_week);
  EXCEPTION
    WHEN others THEN
      RETURN 9;
  END;

  RETURN 0;
END
$$ LANGUAGE 'plpgsql';

--- Procedimiento almacenado para QUITAR INGENIERO A PROYECTO: 
CREATE OR REPLACE FUNCTION removeEngineerToProject(_employee_id INT, _project_id INT) RETURNS INT AS $$
DECLARE
  var_engineer_id INT := 0;
  var_relationship_id INT := NULL;
BEGIN
  BEGIN
    IF NOT EXISTS(SELECT * FROM v_engineers WHERE employee_id = _employee_id FOR UPDATE) THEN
      RETURN 1;
    END IF;

    SELECT id INTO var_engineer_id FROM engineers WHERE employee_id = _employee_id;

    SELECT id INTO var_relationship_id 
    FROM engineers_has_projects 
    WHERE engineer_id = var_engineer_id AND project_id = _project_id FOR UPDATE;

    IF var_relationship_id IS NULL THEN
      RETURN 1;
    END IF;

    INSERT INTO projects_and_engineers_history (log_date, engineer_id, project_id, assignment_date, hours_per_week)
      SELECT NOW()::DATE AS log_date, engineer_id, project_id, assignment_date, hours_per_week
      FROM engineers_has_projects
      WHERE engineer_id = var_engineer_id AND project_id = _project_id;

    DELETE FROM engineers_has_projects WHERE id = var_relationship_id;
  EXCEPTION
    WHEN others THEN
      RETURN 9;
  END;

  RETURN 0;
END
$$ LANGUAGE 'plpgsql';

--- Procedimiento almacenado y Trigger para la eliminación de GERENTES:
CREATE OR REPLACE FUNCTION funcDeleteEngineer() RETURNS TRIGGER AS $$
DECLARE
  var_engineer_id INT := NULL;
  tmp_row record;
BEGIN
	INSERT INTO engineer_history (log_date, employee_id, name, entry_date, specialty, category)
		SELECT NOW()::DATE AS log_date, * 
		FROM v_engineers
		WHERE employee_id = OLD.employee_id FOR UPDATE;
  
  SELECT id INTO var_engineer_id FROM engineers WHERE employee_id = OLD.employee_id FOR UPDATE;
  
  FOR tmp_row IN (SELECT project_id FROM engineers_has_projects WHERE engineer_id = var_engineer_id) LOOP
    PERFORM removeEngineerToProject(OLD.employee_id, tmp_row.project_id);
  END LOOP;

	DELETE FROM engineers WHERE employee_id = OLD.employee_id;
	UPDATE employees SET position = 'GENERAL' WHERE id = OLD.employee_id; 
	RETURN OLD;
END
$$ LANGUAGE 'plpgsql';

CREATE TRIGGER triggerDeleteEngineer INSTEAD OF DELETE 
	ON v_engineers
	FOR EACH ROW
	EXECUTE PROCEDURE funcDeleteEngineer();

CREATE OR REPLACE FUNCTION deleteEngineer(_employee_id INT) RETURNS INT AS $$
BEGIN
  BEGIN
    IF NOT EXISTS(SELECT * FROM v_engineers WHERE employee_id = _employee_id FOR UPDATE) THEN
      RETURN 1;
    END IF;

    DELETE FROM v_engineers WHERE employee_id = _employee_id;
  EXCEPTION
    WHEN others THEN
      RETURN 9;
  END;

  RETURN 0;
END
$$ LANGUAGE 'plpgsql';

--- Procedimiento almacenado para la PROMOCIÓN DE UN EMPLEADO A INGENIERO:
CREATE OR REPLACE FUNCTION promoteEmployeeToEngineer(_employee_id INT, _specialty VARCHAR(45), _category VARCHAR(45)) RETURNS INT AS $$
BEGIN
  BEGIN
    IF NOT EXISTS(SELECT * FROM v_employees WHERE employee_id = _employee_id FOR UPDATE) THEN
      RETURN 1;
    END IF;

    UPDATE employees SET position = 'ENGINEER' WHERE id = _employee_id;

    INSERT INTO v_engineers (employee_id, specialty, category)
      VALUES (_employee_id, _specialty, _category);
  EXCEPTION
    WHEN others THEN
      RETURN 9;
  END;

  RETURN 0;
END
$$ LANGUAGE 'plpgsql';

--- Procedimiento almacenado para la PROMOCIÓN DE UN EMPLEADO A GERENTE:
CREATE OR REPLACE FUNCTION promoteEmployeeToManager(_employee_id INT, _start_date DATE, _bonus bonus, _license_plate license_plate) RETURNS INT AS $$
BEGIN
  BEGIN
    IF NOT EXISTS(SELECT * FROM v_employees WHERE employee_id = _employee_id FOR UPDATE) THEN
      RETURN 1;
    END IF;

    UPDATE employees SET position = 'MANAGER' WHERE id = _employee_id;

    INSERT INTO v_managers (employee_id, start_date, bonus, license_plate) 
      VALUES(_employee_id, _start_date, _bonus, _license_plate);
  EXCEPTION
    WHEN others THEN
      RETURN 9;
  END;

  RETURN 0;
END
$$ LANGUAGE 'plpgsql';

--- Procedimiento almacenado para la PROMOCIÓN DE UN INGENIERO A GERENTE:
CREATE OR REPLACE FUNCTION promoteEngineerToManager(_employee_id INT, _start_date DATE, _bonus bonus, _license_plate license_plate) RETURNS INT AS $$
BEGIN
  BEGIN
    IF NOT EXISTS(SELECT * FROM v_engineers WHERE employee_id = _employee_id FOR UPDATE) THEN
      RETURN 1;
    END IF;

    PERFORM deleteEngineer(_employee_id);

    PERFORM promoteEmployeeToManager(_employee_id, _start_date, _bonus, _license_plate);
  EXCEPTION
    WHEN others THEN
      RETURN 9;
  END;

  RETURN 0;
END
$$ LANGUAGE 'plpgsql';

--- Procedimiento almacenado para MOVER UN INGENIERO A EMPLEADO:
CREATE OR REPLACE FUNCTION moveEngineerToEmployee(_employee_id INT) RETURNS INT AS $$
BEGIN
  BEGIN
    IF NOT EXISTS(SELECT * FROM v_engineers WHERE employee_id = _employee_id FOR UPDATE) THEN
      RETURN 1;
    END IF;

    PERFORM deleteEngineer(_employee_id);
  EXCEPTION
    WHEN others THEN
      RETURN 9;
  END;

  RETURN 0;
END
$$ LANGUAGE 'plpgsql';

--- Procedimiento almacenado para MOVER UN GERENTE A EMPLEADO:
CREATE OR REPLACE FUNCTION moveManagerToEmployee(_employee_id INT) RETURNS INT AS $$
BEGIN
  BEGIN
    IF NOT EXISTS(SELECT * FROM v_managers WHERE employee_id = _employee_id) THEN
      RETURN 1;
    END IF;

    PERFORM deleteManager(_employee_id);
  EXCEPTION
    WHEN others THEN
      RETURN 9;
  END;

  RETURN 0;
END
$$ LANGUAGE 'plpgsql';

--- Procedimiento almacenado para MOVER UN GERENTE A INGENIERO:
CREATE OR REPLACE FUNCTION moveManagerToEngineer(_employee_id INT, _specialty VARCHAR(45), _category VARCHAR(45)) RETURNS INT AS $$
BEGIN
  BEGIN
    IF NOT EXISTS(SELECT * FROM v_managers WHERE employee_id = _employee_id) THEN
      RETURN 1;
    END IF;

    PERFORM deleteManager(_employee_id);

    PERFORM promoteEmployeeToEngineer(_employee_id, _specialty, _category);
  EXCEPTION
    WHEN others THEN
      RETURN 9;
  END;

  RETURN 0;
END
$$ LANGUAGE 'plpgsql';


------ ***** OPERACIONES QUE LLAMAN A PROCEDIMIENTOS ALMACENADOS: *****

--- INSERTAR UN EMPLEADO:

/* 
Puede realizarse de las siguientes dos formas (la segunda mediante procedimiento almacenado es 
la encargada de retornar los valores numéricos dependiendo del estado de la consulta).

INSERT INTO v_employees (name, entry_date) VALUES(...);
SELECT insertEmployee(name, entry_date);
*/

SELECT insertEmployee('Michael Serrato', '2019-05-06');

--- ELIMINAR UN EMPLEADO:

/* 
Puede realizarse de las siguientes dos formas (la segunda mediante procedimiento almacenado es 
la encargada de retornar los valores numéricos dependiendo del estado de la consulta).

DELETE FROM v_employees WHERE employee_id = ...;
SELECT deleteEmployee(employee_id);
*/

SELECT deleteEmployee(1);

--- INSERTAR UN GERENTE:

/*
Las dos formas mostradas anteriormente para la inserción y borrado de los empleados generales aplica de 
igual forma para la vista de los gerentes:

INSERT INTO v_managers (name, entry_date, start_date, bonus, license_plate) VALUES(...);
SELECT insertManager(name, entry_date, start_date, bonus, license_plate);
*/

SELECT insertManager('Brandon Serrato', '2019-05-07', '2019-05-15', 38000, 'AAA002');

--- ELIMINAR UN GERENTE:

/*
DELETE FROM v_managers WHERE employee_id = ...;
SELECT deleteManager(employee_id);
*/

SELECT deleteManager(2);

--- INSERTAR UN INGENIERO:

/*
Las dos formas mostradas anteriormente para la inserción y borrado de los empleados generales aplica de 
igual forma para la vista de los gerentes:

INSERT INTO v_engineers (name, entry_date, specialty, category) VALUES(...);
SELECT insertEngineer(name, entry_date, specialty, category);
*/

SELECT insertEngineer('Pedro Sanchez', '2019-05-08', 'SERVIDORES Y REDES', 'SENIOR');

--- ELIMINAR UN INGENIERO:

/*
DELETE FROM v_engineers WHERE employee_id = ...;
SELECT deleteEngineer(employee_id);
*/

SELECT deleteEngineer(3);

-- PROMOVER UN EMPLEADO A INGENIERO:
SELECT insertEmployee('Juanito Perez', '2019-05-11');
SELECT promoteEmployeeToEngineer(4, 'SOFTWARE', 'JUNIOR');


-- PROMOVER UN EMPLEADO A GERENTE:
SELECT insertEmployee('Guadalupe Jimenez', '2019-05-11');
SELECT promoteEmployeeToManager(5, '2019-05-12', 35000, 'AAA001');

-- PROMOVER UN INGENIERO A GERENTE:

SELECT insertEngineer('Fernando Gutierrez', '2019-05-15', 'MECATRÓNICA', 'SENIOR');
SELECT promoteEngineerToManager(6, '2019-05-16', 40000, NULL);

-- MOVER UN INGENIERO A EMPLEADO:
SELECT insertEngineer('Pedro Fernandez', '2019-05-15', 'INDUSTRIAL', 'JUNIOR');
SELECT moveEngineerToEmployee(7);
SELECT * FROM employees;

-- MOVER UN GERENTE A EMPLEADO:
SELECT insertManager('Francisco Herrera', '2019-04-01', '2019-04-30', 32000, 'AAA002');
SELECT moveManagerToEmployee(8);
SELECT * FROM employees;

-- MOVER UN GERENTE A INGENIERO:
SELECT insertManager('Jorge Martinez', '2019-04-22', '2019-05-03', 32000, 'AAA002');
SELECT moveManagerToEngineer(9, 'ELECTRÓNICA', 'JUNIOR');
SELECT * FROM employees;

-- ASIGNAR INGENIERO A PROYECTO: 
SELECT insertEngineer('Roberto Morales', '2019-05-20', 'SOFTWARE', 'JUNIOR');
SELECT assignEngineerToProject(10, 2, '2019-05-22', 20); /* Return: 0 (Todo bien) */
SELECT assignEngineerToProject(10, 1, '2019-05-23', 15); /* Return: 0 (Todo bien) */
SELECT assignEngineerToProject(10, 3, '2019-05-24', 10); /* Return: 9 (Excede el número máximo de horas) */
SELECT assignEngineerToProject(10, 1, '2019-05-25', 5); /* Return: 9 (No puede ser asignado al mismo proyecto más de una vez) */

-- QUITAR INGENIERO A PROYECTO: 
SELECT removeEngineerToProject(10, 2); /* Return: 0 (Todo bien) */
SELECT * FROM projects_and_engineers_history;
SELECT removeEngineerToProject(10, 1); /* Return: 0 (Todo bien) */
SELECT * FROM projects_and_engineers_history;