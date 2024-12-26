#ifndef QUERIES_H
#define QUERIES_H
#include <QString>

namespace SqlQueries {

    const QString databaseName = "music.db";

    const QString CreateMusicLibraryTable = R"(
        CREATE TABLE IF NOT EXISTS MusicLibrary (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            filePath TEXT UNIQUE NOT NULL,
            fileName TEXT NOT NULL,
            artist TEXT,
            album TEXT,
            genre TEXT,
            duration INTEGER,
            fileSize INTEGER,
            bitrate INTEGER,
            lyrics TEXT
        );
    )";

    const QString CheckMusicExists = R"(
        SELECT id FROM MusicLibrary WHERE filePath = :filePath
    )";

    const QString InsertMusic = R"(
        INSERT INTO MusicLibrary (filePath, fileName) VALUES (:filePath, :fileName)
    )";

    const QString SelectAllMusic = R"(
        SELECT filePath, fileName FROM MusicLibrary;
    )";
}
#endif // QUERIES_H
