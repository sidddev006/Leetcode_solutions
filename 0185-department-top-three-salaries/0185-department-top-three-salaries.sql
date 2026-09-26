# Write your MySQL query statement below
SELECT Department.name as Department, e1.name as Employee, Salary FROM 
Employee e1
JOIN  Department ON e1.departmentId = Department.id WHERE (SELECT COUNT(DISTINCT e2.salary) FROM EMPLOYEE E2 WHERE E2.SALARY > E1.SALARY AND E2.departmentId = e1.departmentId) < 3;