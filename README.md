# OS_SCHEDULE
Sure, here's everything you asked for to the point:


---

1. Procedure Syntax (MySQL CLI)

DELIMITER //

CREATE PROCEDURE procedure_name(IN param1 datatype, OUT param2 datatype)
BEGIN
    -- SQL statements
END //

DELIMITER ;

Example:

DELIMITER //

CREATE PROCEDURE GetUserById(IN userId INT)
BEGIN
    SELECT * FROM users WHERE id = userId;
END //

DELIMITER ;


---

2. Function Syntax (MySQL CLI)

DELIMITER //

CREATE FUNCTION function_name(param1 datatype) RETURNS return_datatype
DETERMINISTIC
BEGIN
    -- SQL statements
    RETURN some_value;
END //

DELIMITER ;

Example:

DELIMITER //

CREATE FUNCTION GetFullName(firstName VARCHAR(50), lastName VARCHAR(50))
RETURNS VARCHAR(100)
DETERMINISTIC
BEGIN
    RETURN CONCAT(firstName, ' ', lastName);
END //

DELIMITER ;


---

3. Trigger Syntax (MySQL CLI)

DELIMITER //

CREATE TRIGGER trigger_name
{BEFORE | AFTER} {INSERT | UPDATE | DELETE}
ON table_name
FOR EACH ROW
BEGIN
    -- SQL statements
END //

DELIMITER ;

Example:

DELIMITER //

CREATE TRIGGER before_user_insert
BEFORE INSERT ON users
FOR EACH ROW
BEGIN
    SET NEW.created_at = NOW();
END //

DELIMITER ;


---

4. JOIN Syntax

SELECT columns
FROM table1
JOIN table2
ON table1.column_name = table2.column_name;

Example:

SELECT users.name, orders.amount
FROM users
JOIN orders ON users.id = orders.user_id;


---

5. GROUP BY Syntax

SELECT column, AGGREGATE_FUNCTION(column)
FROM table
GROUP BY column;

Example:

SELECT department, COUNT(*) AS total
FROM employees
GROUP BY department;


---

6. ORDER BY Syntax

SELECT columns
FROM table
ORDER BY column [ASC | DESC];

Example:

SELECT name, salary
FROM employees
ORDER BY salary DESC;


---

Would you also like quick examples combining JOIN, GROUP BY, and ORDER BY together? (it’s common in real projects!)

Here's the straight answer:


---

1. See Triggers

SHOW TRIGGERS;

2. See Procedures

SHOW PROCEDURE STATUS WHERE Db = 'your_database_name';

3. See Functions

SHOW FUNCTION STATUS WHERE Db = 'your_database_name';


---

To See the Syntax (Definition) of a Specific:

Trigger:


SHOW CREATE TRIGGER trigger_name;

Procedure:


SHOW CREATE PROCEDURE procedure_name;

Function:


SHOW CREATE FUNCTION function_name;


---

Let me know if you want a ready command that lists everything together quickly!

