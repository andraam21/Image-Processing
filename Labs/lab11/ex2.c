#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct song
{
    int id;
    char nume[30];
} Song;

typedef struct album
{
    char nume_album[30];
    int nr_songs;
    int max_nr_songs;
    struct song *songs;
} Album;

struct album *AllocAlbum(char nume[], int cantece, int nr_max_songs) // sau direct Album
{
    Album *album = malloc(sizeof(Album));
    album->songs = malloc(nr_max_songs * sizeof(Song));
    album->nr_songs = cantece;
    return album;
}

void Addsongs(struct album *album, struct song song)
{
    scanf("%s", song.nume);
    scanf("%d", &song.id);
    album->songs[1] = song;
}

int main()
{

    Album *Albumul1 = AllocAlbum("hi", 2, 4);
    Song Song1, Song2;
    Addsongs(Albumul1, Song1);
    Addsongs(Albumul1, Song2);
}