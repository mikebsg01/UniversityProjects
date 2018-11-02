CREATE TABLE images (
    id NUMBER NOT NULL PRIMARY KEY,
    file_path VARCHAR2(250) NOT NULL,
    file_name VARCHAR2(45) NOT NULL,
    file_extension VARCHAR2(4) NOT NULL,
    created_at TIMESTAMP DEFAULT LOCALTIMESTAMP,
    updated_at TIMESTAMP DEFAULT NULL
);

CREATE TABLE users (
    id NUMBER NOT NULL PRIMARY KEY,
    is_admin NUMBER(1) DEFAULT 0,
    first_name VARCHAR2(25) NOT NULL,
    last_name VARCHAR2(25) NOT NULL,
    photo_id NUMBER NOT NULL,
    phone_number VARCHAR2(15) DEFAULT NULL,
    email VARCHAR2(80) NOT NULL,
    password VARCHAR2(120) NOT NULL,
    rfc VARCHAR(13) NOT NULL,
    address VARCHAR2(80) DEFAULT NULL,
    created_at TIMESTAMP DEFAULT LOCALTIMESTAMP,
    updated_at TIMESTAMP DEFAULT NULL,
    CONSTRAINT fk_photo_id FOREIGN KEY (photo_id) REFERENCES images (id)
);

CREATE TABLE categories (
    id NUMBER NOT NULL PRIMARY KEY,
    name VARCHAR2(45) NOT NULL,
    created_at TIMESTAMP DEFAULT LOCALTIMESTAMP,
    updated_at TIMESTAMP DEFAULT NULL
);

CREATE TABLE menus (
    id NUMBER NOT NULL PRIMARY KEY,
    name VARCHAR2(45) NOT NULL,
    created_at TIMESTAMP DEFAULT LOCALTIMESTAMP,
    updated_at TIMESTAMP DEFAULT NULL
);

CREATE TABLE available_tables (
    id NUMBER NOT NULL PRIMARY KEY,
    capacity NUMBER NOT NULL,
    created_at TIMESTAMP DEFAULT LOCALTIMESTAMP,
    updated_at TIMESTAMP DEFAULT NULL
);

CREATE TABLE orders (
    id NUMBER NOT NULL PRIMARY KEY,
    table_id NUMBER NOT NULL,
    created_at TIMESTAMP DEFAULT LOCALTIMESTAMP,
    updated_at TIMESTAMP DEFAULT NULL,
    CONSTRAINT fk_table_id FOREIGN KEY (table_id) REFERENCES available_tables (id)
);

CREATE TABLE invoices (
    id NUMBER NOT NULL PRIMARY KEY,
    subtotal DECIMAL(8, 2) NOT NULL,
    iva DECIMAL(2, 2) DEFAULT 0.16,
    total DECIMAL(8, 2) NOT NULL,
    order_id NUMBER NOT NULL,
    created_at TIMESTAMP DEFAULT LOCALTIMESTAMP,
    updated_at TIMESTAMP DEFAULT NULL,
    CONSTRAINT fk_order_id FOREIGN KEY (order_id) REFERENCES orders (id)
);

CREATE TABLE saucers (
    id NUMBER NOT NULL PRIMARY KEY,
    name VARCHAR2(45) NOT NULL,
    description VARCHAR2(250) DEFAULT NULL,
    price DECIMAL(8, 2) NOT NULL,
    category_id NUMBER NOT NULL,
    image_id NUMBER NOT NULL,
    created_at TIMESTAMP DEFAULT LOCALTIMESTAMP,
    updated_at TIMESTAMP DEFAULT NULL,
    CONSTRAINT fk_category_id FOREIGN KEY (category_id) REFERENCES categories (id),
    CONSTRAINT fk_image_id FOREIGN KEY (image_id) REFERENCES images (id)
);

CREATE TABLE menus_has_saucers (
    menu_id NUMBER NOT NULL,
    saucer_id NUMBER NOT NULL,
    created_at TIMESTAMP DEFAULT LOCALTIMESTAMP,
    updated_at TIMESTAMP DEFAULT NULL,
    CONSTRAINT fk_menu_id FOREIGN KEY (menu_id) REFERENCES menus (id),
    CONSTRAINT fk_saucer_id FOREIGN KEY (saucer_id) REFERENCES saucers (id)
);

CREATE TABLE orders_has_saucers (
    order_id NUMBER NOT NULL,
    saucer_id NUMBER NOT NULL,
    quantity NUMBER(4) DEFAULT 1,
    created_at TIMESTAMP DEFAULT LOCALTIMESTAMP,
    updated_at TIMESTAMP DEFAULT NULL,
    CONSTRAINT orders_has_saucers_fk_order_id FOREIGN KEY (order_id) REFERENCES orders (id),
    CONSTRAINT orders_has_saucers_fk_saucer_id FOREIGN KEY (saucer_id) REFERENCES saucers (id)
);
