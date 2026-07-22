# Write your MySQL query statement below
select max(num) as num from (select num, count(*) as cnt from  MyNumbers group by num) as t where cnt<=1;  