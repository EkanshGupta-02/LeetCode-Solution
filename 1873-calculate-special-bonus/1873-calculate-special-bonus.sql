# Write your MySQL query statement below
Select e.employee_id, 
case 
    when mod(e.employee_id,2)!=0 and left(e.name,1)!='M' then salary
    else 0
end as bonus
from Employees as e