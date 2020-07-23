CREATE TABLE IF NOT EXISTS MusicLibrary (
	MUSIC_ID	INT	AUTO_INCREMENT PRIMARY KEY,		--	an ID
	TITLE		VARCHAR(50) NOT NULL,				--	the title of the music
	INTERPRETER	VARCHAR(50) NOT NULL,				--	the interpreter of this music
	ALBUM		VARCHAR(50) NULL,					--	the album, if exists → optional
	PUBLISHED	CHAR(4) NOT NULL,					--	the publishing year in words
	SONG_LENGTH	INT	NULL							--	the length of the current song in seconds → optional
);
