CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  DECLARE result INT;

  SET N = N - 1; -- adjust for zero-based LIMIT offset

  SELECT DISTINCT salary
  INTO result
  FROM Employee
  ORDER BY salary DESC
  LIMIT N, 1;

  RETURN result;
END;