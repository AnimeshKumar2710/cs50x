SELECT DISTINCT(name) FROM people 
JOIN stars ON people.id = stars.person_id
WHERE stars.movie_id IN (SELECT movie_id FROM stars 
JOIN people ON people.id = stars.person_id
WHERE people.name = "Kevin Bacon") AND people.name != "Kevin Bacon";
