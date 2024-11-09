SELECT AVG(energy)
FROM songs
JOIN artists ON songs.artist_id = artist_id
WHERE artists.name = 'Drake';
