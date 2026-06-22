-- ===========================================
-- SECP3623 DATABASE PROGRAMMING – ASSIGNMENT 1
-- Hostel Management System
-- Student1: AHMAD ZIYAAD BIN MOHD ABBAS
-- Student2: Damiya Aina binti Basir Abd Shammad
-- ===========================================

-- =========================
-- TASK 1: DATABASE CREATION
-- =========================
DROP DATABASE IF EXISTS hostel_mgmt_yad;
CREATE DATABASE hostel_mgmt_yad;
USE hostel_mgmt_yad;

-- ==============================
-- 1. TABLE CREATION (DDL)
-- ==============================

-- ROOM TYPES
CREATE TABLE room_types (
    type_id INT AUTO_INCREMENT PRIMARY KEY,
    type_name VARCHAR(50) NOT NULL UNIQUE,
    rent DECIMAL(8,2) NOT NULL,
    deposit DECIMAL(8,2) NOT NULL,
    capacity INT NOT NULL
);

-- ROOMS
CREATE TABLE rooms (
    room_id INT AUTO_INCREMENT PRIMARY KEY,
    type_id INT NOT NULL,
    room_no VARCHAR(10) NOT NULL UNIQUE,
    floor_no INT NOT NULL,
    is_occupied BOOLEAN DEFAULT FALSE,
    FOREIGN KEY (type_id) REFERENCES room_types(type_id)
);

-- STUDENTS
CREATE TABLE students (
    student_id INT AUTO_INCREMENT PRIMARY KEY,
    room_id INT,
    fname VARCHAR(50) NOT NULL,
    lname VARCHAR(50),
    status ENUM('ACTIVE', 'NON_ACTIVE') NOT NULL,
    checkin_date DATE,
    email VARCHAR(100) UNIQUE,
    FOREIGN KEY (room_id) REFERENCES rooms(room_id)
);

-- MAINTENANCE
CREATE TABLE maintenance (
    maint_id INT AUTO_INCREMENT PRIMARY KEY,
    room_id INT NOT NULL,
    issue_desc VARCHAR(255) NOT NULL,
    severity ENUM('LOW', 'MEDIUM', 'HIGH') NOT NULL,
    status ENUM('OPEN', 'RESOLVED') NOT NULL,
    reported_on DATE NOT NULL,
    resolved_on DATE,
    FOREIGN KEY (room_id) REFERENCES rooms(room_id)
);

-- PAYMENTS
CREATE TABLE payments (
    payment_id INT AUTO_INCREMENT PRIMARY KEY,
    student_id INT NOT NULL,
    amount DECIMAL(8,2) NOT NULL,
    paid_on DATE NOT NULL,
    method ENUM('CASH', 'FPX', 'CARD', 'TNG') NOT NULL,
    note VARCHAR(100),
    FOREIGN KEY (student_id) REFERENCES students(student_id)
);

-- ===================================
-- 2. SCHEMA MAINTENANCE DEMONSTRATION
-- ===================================

-- Add a unique email column (if not added above)
ALTER TABLE students ADD COLUMN email2 VARCHAR(100) UNIQUE;

-- Create and safely drop a temporary test table
CREATE TABLE temp_table (test_id INT);
DROP TABLE temp_table;

-- ==============================
-- TASK 2: DATA MANIPULATION (DML)
-- ==============================

-- 1. DATA INSERTION
INSERT INTO room_types (type_name, rent, deposit, capacity) VALUES
('Single', 600.00, 300.00, 1),
('Double', 500.00, 250.00, 2),
('Premium', 850.00, 400.00, 1),
('Family', 1000.00, 500.00, 4),
('Economy', 400.00, 200.00, 2),
('Compact', 450.00, 250.00, 2),
('Executive', 950.00, 450.00, 1),
('Deluxe', 700.00, 350.00, 2),
('Suite', 1200.00, 600.00, 3),
('Student', 550.00, 300.00, 2);

INSERT INTO rooms (type_id, room_no, floor_no, is_occupied) VALUES
(1,'A101',1,FALSE),(2,'A102',1,FALSE),(3,'A103',1,FALSE),(4,'B201',2,FALSE),
(5,'B202',2,FALSE),(6,'C301',3,FALSE),(7,'C302',3,FALSE),(8,'A104',1,FALSE),
(9,'B203',2,FALSE),(10,'C303',3,FALSE);

INSERT INTO students (room_id,fname,lname,status,checkin_date,email) VALUES
(1,'Ahmad','Ziyaad','ACTIVE','2025-10-10','ahmadz@utm.my'),
(2,'Ali','Morrisane','ACTIVE','2025-10-11','alim@utm.my'),
(3,'Sara','Parker','NON_ACTIVE','2025-09-15','sarap@utm.my'),
(4,'Nur','Haliza','ACTIVE','2025-10-20','nurh@utm.my'),
(5,'Daniel','Tee','ACTIVE','2025-10-25','danielt@utm.my'),
(6,'Aiman','Bana','NON_ACTIVE','2025-08-05','aimanb@utm.my'),
(7,'Faiz','Shukri','ACTIVE','2025-10-30','faizshuk@utm.my'),
(8,'Tun','Razak','ACTIVE','2025-10-28','tunrazak@utm.my'),
(9,'Donald','Trump','NON_ACTIVE','2025-07-22','donaldt@utm.my'),
(10,'Mokhtar','Dahari','ACTIVE','2025-10-15','mokhdah@utm.my');

INSERT INTO maintenance (room_id,issue_desc,severity,status,reported_on,resolved_on) VALUES
(1,'Water leak in bathroom','MEDIUM','OPEN','2025-10-20',NULL),
(2,'Broken chair','LOW','RESOLVED','2025-09-15','2025-09-20'),
(3,'Fan not working','HIGH','OPEN','2025-10-25',NULL),
(4,'Window crack','LOW','RESOLVED','2025-08-10','2025-08-15'),
(5,'Aircond noisy','MEDIUM','OPEN','2025-10-26',NULL),
(6,'Power socket fault','HIGH','OPEN','2025-10-28',NULL),
(7,'Light bulb fused','LOW','RESOLVED','2025-08-01','2025-08-02'),
(8,'Door lock issue','MEDIUM','OPEN','2025-10-29',NULL),
(9,'Desk damage','LOW','OPEN','2025-10-27',NULL),
(10,'Ceiling leak','HIGH','RESOLVED','2025-08-15','2025-08-20');

INSERT INTO payments (student_id,amount,paid_on,method,note) VALUES
(1,500.00,'2025-10-01','CASH','October Rent'),
(2,600.00,'2025-10-02','FPX','October Rent'),
(4,1000.00,'2025-11-01','CARD','November Rent'),
(5,800.00,'2025-11-02','TNG','November Rent'),
(7,950.00,'2025-10-01','CARD','October Rent'),
(8,700.00,'2025-11-03','FPX','November Rent'),
(10,550.00,'2025-11-05','CASH','November Rent'),
(3,500.00,'2025-09-01','TNG','September Rent'),
(6,850.00,'2025-08-01','FPX','August Rent'),
(9,600.00,'2025-07-01','CARD','July Rent');

-- ======================
-- 2. UPDATE AND DELETE
-- ======================
UPDATE rooms
SET is_occupied = TRUE
WHERE room_id IN (
    SELECT DISTINCT room_id FROM students WHERE status='ACTIVE'
);

DELETE FROM maintenance
WHERE status='RESOLVED' AND reported_on < DATE_SUB(CURDATE(), INTERVAL 60 DAY);

-- ===========================
-- 3. FILTERING QUERIES
-- ===========================
-- BETWEEN
SELECT * FROM room_types WHERE rent BETWEEN 400 AND 800;

-- LIKE
SELECT * FROM students WHERE fname LIKE 'A%';

-- IN
SELECT * FROM payments WHERE method IN ('FPX','CARD');

-- AND / OR / NOT
SELECT * FROM rooms
WHERE (floor_no = 1 OR floor_no = 2) AND NOT is_occupied = FALSE;

-- ===============================
-- 4. FUNCTIONS AND EXPRESSIONS
-- ===============================
-- Aggregate
SELECT COUNT(*) AS total_room_types FROM room_types;

-- String Functions
SELECT CONCAT(UPPER(fname), ' ', LOWER(lname)) AS formatted_name FROM students;

-- AVG and ROUND example
SELECT ROUND(AVG(rent),2) AS avg_rent FROM room_types;

-- ============================
-- TASK 3: REPORTING & VIEWS
-- ============================

-- 1. CREATE VIEW
CREATE OR REPLACE VIEW v_room_status AS
SELECT 
    r.room_no,
    t.type_name,
    t.rent,
    r.floor_no,
    t.capacity,

    -- Count ACTIVE students per room
    (
        SELECT COUNT(*) 
        FROM students s 
        WHERE s.room_id = r.room_id 
        AND s.status = 'ACTIVE'
    ) AS n_occupants,

    -- Count OPEN maintenance issues per room
    (
        SELECT COUNT(*)
        FROM maintenance m
        WHERE m.room_id = r.room_id 
        AND m.status = 'OPEN'
    ) AS pending_issues,

    -- Room vacancy status based on active occupants
    CASE 
        WHEN (
            SELECT COUNT(*) 
            FROM students s2 
            WHERE s2.room_id = r.room_id 
            AND s2.status = 'ACTIVE'
        ) = 0 
        THEN TRUE 
        ELSE FALSE 
    END AS is_vacant

FROM rooms r
JOIN room_types t ON r.type_id = t.type_id;

-- 2. SUMMARY QUERIES
-- a) Total number of students per room type
SELECT t.type_name, COUNT(s.student_id) AS total_students
FROM room_types t
JOIN rooms r ON t.type_id = r.type_id
JOIN students s ON r.room_id = s.room_id
GROUP BY t.type_name;

-- b) Average rent and total deposit per room type
SELECT type_name, 
       ROUND(AVG(rent),2) AS avg_rent, 
       ROUND(SUM(deposit),2) AS total_deposit
FROM room_types
GROUP BY type_name;

-- c) Monthly payment totals grouped by year & month
SELECT YEAR(paid_on) AS yr, MONTH(paid_on) AS mn, SUM(amount) AS total
FROM payments
GROUP BY yr, mn;

-- d) Count of OPEN maintenance issues per floor with HAVING
SELECT r.floor_no, COUNT(m.maint_id) AS open_issues
FROM maintenance m
JOIN rooms r ON m.room_id = r.room_id
WHERE m.status='OPEN'
GROUP BY r.floor_no
HAVING COUNT(m.maint_id) > 2;

-- 3. CASE FUNCTION TO CATEGORIZE RENT LEVELS
SELECT type_name, rent,
CASE
    WHEN rent < 600 THEN 'LOW'
    WHEN rent BETWEEN 600 AND 900 THEN 'MEDIUM'
    ELSE 'HIGH'
END AS rent_category
FROM room_types;

-- ===========================
-- END OF ASSIGNMENT SCRIPT
-- ===========================
