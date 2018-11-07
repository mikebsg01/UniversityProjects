---------------------- [START] INSERTS ----------------------

--- Images (Users) ---
INSERT INTO images (id, file_path, file_name, file_extension)
VALUES (1, '/public/users/img_profile', 'user_michael', 'png');

INSERT INTO images (id, file_path, file_name, file_extension)
VALUES (2, '/public/users/img_profile', 'user_luzma', 'jpg');

INSERT INTO images (id, file_path, file_name, file_extension)
VALUES (3, '/public/users/img_profile', 'user_loth', 'jpg');

INSERT INTO images (id, file_path, file_name, file_extension)
VALUES (14, '/public/users/img_profile', 'jose_gonzalez', 'png');

INSERT INTO images (id, file_path, file_name, file_extension)
VALUES (15, '/public/users/img_profile', 'roberto_gomez', 'png');

INSERT INTO images (id, file_path, file_name, file_extension)
VALUES (16, '/public/users/img_profile', 'stivi_hawking', 'png');

INSERT INTO images (id, file_path, file_name, file_extension)
VALUES (17, '/public/users/img_profile', 'anton_ego', 'jpg');

INSERT INTO images (id, file_path, file_name, file_extension)
VALUES (18, '/public/users/img_profile', 'johny_sins', 'jpg');

INSERT INTO images (id, file_path, file_name, file_extension)
VALUES (19, '/public/users/img_profile', 'alberto_einstein', 'jpg');

INSERT INTO images (id, file_path, file_name, file_extension)
VALUES (20, '/public/users/img_profile', 'benito_martinez', 'jpg');

--- Images (Saucers) ---
INSERT INTO images (id, file_path, file_name, file_extension)
VALUES (4, '/public/saucers/img_presentation', 'ensalada-navidena', 'jpg');

INSERT INTO images (id, file_path, file_name, file_extension)
VALUES (5, '/public/saucers/img_presentation', 'hamburgesa-peruana', 'jpg');

INSERT INTO images (id, file_path, file_name, file_extension)
VALUES (6, '/public/saucers/img_presentation', 'pescado-veracruzana', 'png');

INSERT INTO images (id, file_path, file_name, file_extension)
VALUES (7, '/public/saucers/img_presentation', 'carne-res-en-su-jugo', 'jpg');

INSERT INTO images (id, file_path, file_name, file_extension)
VALUES (8, '/public/saucers/img_presentation', 'fajitas-arrachera', 'png');

INSERT INTO images (id, file_path, file_name, file_extension)
VALUES (9, '/public/saucers/img_presentation', 'hotcakes', 'png');

INSERT INTO images (id, file_path, file_name, file_extension)
VALUES (10, '/public/saucers/img_presentation', 'vino-tinto-ruby-la-redonda', 'jpg');

INSERT INTO images (id, file_path, file_name, file_extension)
VALUES (11, '/public/saucers/img_presentation', 'mokaccino', 'jpg');

INSERT INTO images (id, file_path, file_name, file_extension)
VALUES (12, '/public/saucers/img_presentation', 'pasta-al-pesto', 'png');

INSERT INTO images (id, file_path, file_name, file_extension)
VALUES (13, '/public/saucers/img_presentation', 'sopa-aguacate', 'jpg');

--- Users ---
INSERT INTO users (id, is_admin, first_name, last_name, photo_id, phone_number, email, password, rfc, address) 
VALUES (1, 1, 'Michael', 'Serrato', 1, '4422332139', 'mikebsg01@gmail.com', 'hola123', 'SSMMXXXXXX123', 'Col. Los Angeles #123');

INSERT INTO users (id, is_admin, first_name, last_name, photo_id, phone_number, email, password, rfc, address) 
VALUES (2, 1, 'Luz Maria', 'Hernandez', 2, '4421312540', 'luzma@gmail.com', 'lzhz9', 'HEMMXXXXXX125', 'Col. Los Viñedos #502');

INSERT INTO users (id, is_admin, first_name, last_name, photo_id, phone_number, email, password, rfc, address) 
VALUES (3, 1, 'Loth', 'Mejia', 3, '4425338172', 'loth345@gmail.com', 'lmm345', 'MEMMXXXXXX137', 'Col. Los Laureles #4237');

INSERT INTO users (id, is_admin, first_name, last_name, photo_id, phone_number, email, password, rfc, address) 
VALUES (4, 0, 'Jose', 'Gonzalez', 14, '4421130170', 'jose.gonzalez@gmail.com', 'josegonz170', 'GOJOXXXXXX170', 'Blvd. Bernardo Quintana #3505');

INSERT INTO users (id, is_admin, first_name, last_name, photo_id, phone_number, email, password, rfc, address) 
VALUES (5, 0, 'Roberto', 'Gomez Bolaños', 15, '5521150171', 'roberto_bolaños8@outlook.com', 'chespir8', 'GOBOXXXXXXZ51', 'Col. Mateo Bolaños #504');

INSERT INTO users (id, is_admin, first_name, last_name, photo_id, phone_number, email, password, rfc, address) 
VALUES (6, 0, 'Stephen', 'Hawking', 16, '5511170120', 'stivi.hawking@yahoo.com', 'blackholebaby193', 'STHAXXXXXX320', 'Col. Benito Juarez #123');

INSERT INTO users (id, is_admin, first_name, last_name, photo_id, phone_number, email, password, rfc, address) 
VALUES (7, 0, 'Anton', 'Ego', 17, '5511170120', 'usa.anton_ego1@hotmail.com', 'iloveratatouille', 'EGANXXXXXX17T', 'Col. Ferreti #2030');

INSERT INTO users (id, is_admin, first_name, last_name, photo_id, phone_number, email, password, rfc, address) 
VALUES (8, 0, 'Johnny', 'Sins', 18, '4424536186', 'usa.brei.crs@hotmail.com', 'tambiencocino', 'SIJOXXXXXXSNX', 'Col. Lomas #302');

INSERT INTO users (id, is_admin, first_name, last_name, photo_id, phone_number, email, password, rfc, address) 
VALUES (9, 0, 'Alberto', 'Einstein', 19, '4421123083', 'weaknuclearforce13@hotmail.com', 'ihatemylife,E=mc^2', 'EIALXXXXXX76D', 'Av. de la Luz #76');

INSERT INTO users (id, is_admin, first_name, last_name, photo_id, phone_number, email, password, rfc, address) 
VALUES (10, 0, 'Benito', 'Martinez', 20, '4421123085', 'lic.leopoldo@live.com', 'hearthismusic', 'BENIXXXXXXBBE', 'Col. Menchaca #107');

--- Categories ---
INSERT INTO categories (id, name)
VALUES (1, 'platillo fuerte');

INSERT INTO categories (id, name)
VALUES (2, 'ensalada');

INSERT INTO categories (id, name)
VALUES (3, 'postre');

INSERT INTO categories (id, name)
VALUES (4, 'aperitivo');

INSERT INTO categories (id, name)
VALUES (5, 'desayuno');

INSERT INTO categories (id, name)
VALUES (6, 'bebida');

INSERT INTO categories (id, name)
VALUES (7, 'bebida alcoholica');

INSERT INTO categories (id, name)
VALUES (8, 'comida rapida');

INSERT INTO categories (id, name)
VALUES (9, 'comida vegana');

INSERT INTO categories (id, name)
VALUES (10, 'sopa');

-- Menus ---
INSERT INTO menus (id, name)
VALUES (1, 'Diario');

INSERT INTO menus (id, name)
VALUES (2, 'Especial del Lunes');

INSERT INTO menus (id, name)
VALUES (3, 'Especial del Martes');

INSERT INTO menus (id, name)
VALUES (4, 'Especial del Miércoles');

INSERT INTO menus (id, name)
VALUES (5, 'Juevebes');

INSERT INTO menus (id, name)
VALUES (6, 'Beviernes');

INSERT INTO menus (id, name)
VALUES (7, 'Sabadrink');

INSERT INTO menus (id, name)
VALUES (8, 'Dominguirri Familiar');

INSERT INTO menus (id, name)
VALUES (9, 'Especial Aniversario');

INSERT INTO menus (id, name)
VALUES (10, 'Noche Elegante');

--- Available Tables ---
INSERT INTO available_tables (id, capacity)
VALUES (1, 4);

INSERT INTO available_tables (id, capacity)
VALUES (2, 4);

INSERT INTO available_tables (id, capacity)
VALUES (3, 8);

INSERT INTO available_tables (id, capacity)
VALUES (4, 8);

INSERT INTO available_tables (id, capacity)
VALUES (5, 8);

INSERT INTO available_tables (id, capacity)
VALUES (6, 6);

INSERT INTO available_tables (id, capacity)
VALUES (7, 6);

INSERT INTO available_tables (id, capacity)
VALUES (8, 2);

INSERT INTO available_tables (id, capacity)
VALUES (9, 2);

INSERT INTO available_tables (id, capacity)
VALUES (10, 2);

--- Saucers ---
INSERT INTO saucers (id, name, price, description, category_id, image_id)
VALUES (1, 'Ensalada Navideña', 100.00, 'Rica ensalada navideña con manzanas y nueces', 3, 4);

INSERT INTO saucers (id, name, price, description, category_id, image_id)
VALUES (2, 'Hamburguesa Peruana', 139.90, 'Deliciosa hamburguesa peruana con salsa criolla acompañada de ricas papas a la francesa.', 8, 5);

INSERT INTO saucers (id, name, price, description, category_id, image_id)
VALUES (3, 'Pescado a la Veracruzana', 188.50, 'Pescado acompañado de chiles güeros y arroz blanco.', 1, 6);

INSERT INTO saucers (id, name, price, description, category_id, image_id)
VALUES (4, 'Carne de Res en su Jugo', 259.90, 'Carne de res, frijoles, cilantro y cebolla picada.', 1, 7);

INSERT INTO saucers (id, name, price, description, category_id, image_id)
VALUES (5, 'Fajitas de Carne Arrachera', 225.00, 'Fajitas de carne arrachera con pimientos acompañadas de arroz.', 1, 8);

INSERT INTO saucers (id, name, price, description, category_id, image_id)
VALUES (6, 'Hotcakes', 64.90, 'Pila de 4 hotcakes con mantequilla (jarabe, mermelada y lechera al gusto).', 5, 9);

INSERT INTO saucers (id, name, price, description, category_id, image_id)
VALUES (7, 'Vino tinto', 350.00, 'Vino tinto ruby La Redonda.', 7, 10);

INSERT INTO saucers (id, name, price, description, category_id, image_id)
VALUES (8, 'Mokaccino', 74.90, 'Delicioso café de moca preparado con leche y expresso recién hecho.', 6, 11);

INSERT INTO saucers (id, name, price, description, category_id, image_id)
VALUES (9, 'Pasta al pesto de aguacate', 64.90, 'Pasta al pesto de aguacate adornada con tomates rojos secos y hojas de albaca.', 9, 12);

INSERT INTO saucers (id, name, price, description, category_id, image_id)
VALUES (10, 'Sopa Azteca', 134.40, 'Deliciosa sopa de tortilla de maíz con aguacate, queso y chile pasilla.', 10, 13);

--- Menus Has Saucers ---
INSERT INTO menus_has_saucers (menu_id, saucer_id)
VALUES (1, 1);

INSERT INTO menus_has_saucers (menu_id, saucer_id)
VALUES (1, 5);

INSERT INTO menus_has_saucers (menu_id, saucer_id)
VALUES (1, 6);

INSERT INTO menus_has_saucers (menu_id, saucer_id)
VALUES (1, 8);

INSERT INTO menus_has_saucers (menu_id, saucer_id)
VALUES (1, 9);

INSERT INTO menus_has_saucers (menu_id, saucer_id)
VALUES (1, 10);

INSERT INTO menus_has_saucers (menu_id, saucer_id)
VALUES (10, 7);

INSERT INTO menus_has_saucers (menu_id, saucer_id)
VALUES (4, 4);

INSERT INTO menus_has_saucers (menu_id, saucer_id)
VALUES (5, 2);

INSERT INTO menus_has_saucers (menu_id, saucer_id)
VALUES (5, 3);

--- Orders ---
INSERT INTO orders (id, table_id)
VALUES (1, 1);

INSERT INTO orders (id, table_id)
VALUES (2, 3);

INSERT INTO orders (id, table_id)
VALUES (3, 10);

INSERT INTO orders (id, table_id)
VALUES (4, 9);

INSERT INTO orders (id, table_id)
VALUES (5, 7);

INSERT INTO orders (id, table_id)
VALUES (6, 2);

INSERT INTO orders (id, table_id)
VALUES (7, 4);

INSERT INTO orders (id, table_id)
VALUES (8, 5);

INSERT INTO orders (id, table_id)
VALUES (9, 6);

INSERT INTO orders (id, table_id)
VALUES (10, 8);

--- Orders Has Saucers ---
INSERT INTO orders_has_saucers (order_id, saucer_id, quantity)
VALUES (1, 1, 1);

INSERT INTO orders_has_saucers (order_id, saucer_id, quantity)
VALUES (2, 2, 2);

INSERT INTO orders_has_saucers (order_id, saucer_id, quantity)
VALUES (3, 3, 4);

INSERT INTO orders_has_saucers (order_id, saucer_id, quantity)
VALUES (4, 6, 4);

INSERT INTO orders_has_saucers (order_id, saucer_id, quantity)
VALUES (4, 8, 4);

INSERT INTO orders_has_saucers (order_id, saucer_id, quantity)
VALUES (5, 5, 2);

INSERT INTO orders_has_saucers (order_id, saucer_id, quantity)
VALUES (5, 7, 2);

INSERT INTO orders_has_saucers (order_id, saucer_id, quantity)
VALUES (6, 9, 1);

INSERT INTO orders_has_saucers (order_id, saucer_id, quantity)
VALUES (6, 10, 1);

INSERT INTO orders_has_saucers (order_id, saucer_id, quantity)
VALUES (7, 8, 2);

INSERT INTO orders_has_saucers (order_id, saucer_id, quantity)
VALUES (8, 3, 1);

INSERT INTO orders_has_saucers (order_id, saucer_id, quantity)
VALUES (8, 4, 1);

INSERT INTO orders_has_saucers (order_id, saucer_id, quantity)
VALUES (8, 5, 1);

INSERT INTO orders_has_saucers (order_id, saucer_id, quantity)
VALUES (8, 7, 3);

INSERT INTO orders_has_saucers (order_id, saucer_id, quantity)
VALUES (9, 8, 2);

INSERT INTO orders_has_saucers (order_id, saucer_id, quantity)
VALUES (10, 2, 4);

--- Invoices ---
INSERT INTO invoices (id, subtotal, total, order_id)
VALUES (1, 100, 116, 1);

INSERT INTO invoices (id, subtotal, total, order_id)
VALUES (2, 139.9, 162.29, 2);

INSERT INTO invoices (id, subtotal, total, order_id)
VALUES (3, 188.5, 218.66, 3);

INSERT INTO invoices (id, subtotal, total, order_id)
VALUES (4, 139.8, 162.17, 4);

INSERT INTO invoices (id, subtotal, total, order_id)
VALUES (5, 575, 667, 5);

INSERT INTO invoices (id, subtotal, total, order_id)
VALUES (6, 199.3, 231.19, 6);

INSERT INTO invoices (id, subtotal, total, order_id)
VALUES (7, 74.9, 86.89, 7);

INSERT INTO invoices (id, subtotal, total, order_id)
VALUES (8, 1023.4, 1187.15, 8);

INSERT INTO invoices (id, subtotal, total, order_id)
VALUES (9, 74.9, 86.89, 9);

INSERT INTO invoices (id, subtotal, total, order_id)
VALUES (10, 139.9, 162.29, 10);

---------------------- INSERTS [END] ----------------------

---------------------- [START] UPDATES ----------------------

UPDATE users SET email = 'lmejia01@alumnos.uaq.mx' WHERE id = 3;

UPDATE categories SET name = 'Ensalada suprema' WHERE id = 2;

UPDATE saucers SET price = 200 WHERE id = 3;

UPDATE saucers SET name = 'Hot cakes loquillos' WHERE id = 6;

UPDATE saucers SET price = 190 WHERE id = 3;

UPDATE users SET password = 'pass1234' WHERE id = 6;

UPDATE users SET first_name = 'Benito Leopoldo' WHERE id = 10;

UPDATE saucers SET description = 'Selecta carne de res, frijoles, cilantro y cebolla picada.' WHERE id = 4;

---------------------- UPDATES [END] ----------------------

---------------------- [START] DELETES ----------------------

DELETE FROM menus_has_saucers WHERE menu_id = 3;

DELETE FROM users WHERE id = 7;

DELETE FROM orders_has_saucers WHERE order_id = 4;

DELETE FROM menus_has_saucers WHERE menu_id = 4;

DELETE FROM invoices WHERE id = 6;

DELETE FROM menus WHERE id = 3;

DELETE FROM users WHERE id = 5;

DELETE FROM orders_has_saucers WHERE order_id = 1;

---------------------- DELETES [END] ----------------------

---------------------- [START] SELECTS ----------------------

-- 1. Nombre de las categorías y total de platillos que conforman cada una:
SELECT c.name AS "NombreCategoria", COUNT(s.name) AS "TotalPlatillos" 
FROM saucers s, categories c
WHERE s.id = c.id
GROUP BY c.name;

-- 2. Nombre del platillo y ID de la mesa que lo ordenó.
SELECT saucers.name, orders.table_id FROM saucers
INNER JOIN orders_has_saucers ON saucers.id = orders_has_saucers.saucer_id
INNER JOIN orders ON orders_has_saucers.order_id = orders.id;

-- 3. Precio más alto, más bajo y precio promedio de los platillos.
SELECT MIN(price), MAX(price), AVG(price)
FROM saucers;

-- 4. Nombre del platillo, nombre de la categoría y nombre del menú donde se incluye:
SELECT saucers.name AS "NombrePlatillo", categories.name AS "NombreCategoria", menus.name AS "NombreMenu" FROM saucers 
INNER JOIN categories ON saucers.category_id = categories.id
INNER JOIN menus_has_saucers ON saucers.id = menus_has_saucers.saucer_id
INNER JOIN menus ON menus_has_saucers.menu_id = menus.id
ORDER BY saucers.name ASC;

-- 5. Subtotal, IVA y total de las cuentas con un total mayor a $1,000. Ordenado por fecha.
SELECT subtotal, iva, total
FROM invoices
WHERE total > 1000
ORDER BY created_at ASC;

---------------------- SELECTS [END] ----------------------

