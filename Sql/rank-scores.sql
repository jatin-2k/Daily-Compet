select s1.score, count(s2.score) AS "rank"
from scores s1, (SELECT DISTINCT score from scores) s2
where s1.score <= s2.score
group by s1.id
order by score desc;