SELECT name FROM people where id in (select person_id from stars where movie_id in ( select id from movies where year = 2004)) order by birth;