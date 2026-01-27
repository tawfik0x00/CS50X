SELECT title FROM movies WHERE id IN
(
    SELECT movie_id FROM stars WHERE person_id =
    (
        -- HERE GET THE ID OF THE Bradely Cooper
        SELECT id FROM people WHERE name =  'Bradley Cooper'
    )
)
AND id IN
(
    SELECT movie_id FROM stars WHERE person_id =
    (
        -- ID OF THE Jennifer Lawrence
        SELECT id FROM people WHERE name = 'Jennifer Lawrence'
    )
);
