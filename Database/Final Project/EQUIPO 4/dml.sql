--- Images ---
INSERT INTO images (id, file_path, file_name, file_extension)
VALUES (1, '/public/users/img_profile', 'user_michael', 'png');

--- Users ---
INSERT INTO users (id, is_admin, first_name, last_name, photo_id, phone_number, email, password, rfc, address) 
VALUES (1, 1, 'Michael', 'Serrato', 1, '4422332139', 'mikebsg01@gmail.com', 'hola123', 'SSMMXXXXXX123', 'Col. Los Angeles #123');

--- Categories ---
INSERT INTO categories (id, name)
VALUES (1, 'ensalada');

-- Menus ---
INSERT INTO menus (id, name)
VALUES (1, 'lunes');

--- Available Tables ---
INSERT INTO available_tables (id, capacity)
VALUES (1, 4);

--- Orders ---
INSERT INTO orders (id, table_id)
VALUES (1, 1);

--- Invoices ---
INSERT INTO invoices (id, subtotal, total, order_id)
VALUES (1, 100, 116, 1);

--- Saucers ---
INSERT INTO saucers (id, name, price, description, category_id, image_id)
VALUES (1, 'Ensalada Navideña', 100.00, 'Rica ensalada navideña con manzanas y nueces', 1, 1);

--- Menus Has Saucers ---
INSERT INTO menus_has_saucers (menu_id, saucer_id)
VALUES (1, 1);

--- Orders Has Saucers ---
INSERT INTO orders_has_saucers (order_id, saucer_id, quantity)
VALUES (1, 1, 1);
