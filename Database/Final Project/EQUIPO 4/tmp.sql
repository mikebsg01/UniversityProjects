SELECT sum(price) as "subtotal", (sum(price) * 1.16) as "total", orders.id as "order_id" FROM orders
INNER JOIN orders_has_saucers ON orders.id = orders_has_saucers.order_id 
INNER JOIN saucers ON orders_has_saucers.saucer_id = saucers.id
GROUP BY orders.id HAVING orders.id = 1;
