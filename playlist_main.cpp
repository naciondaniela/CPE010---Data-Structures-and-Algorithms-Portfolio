#include <iostream>
#include "playlist.h"

int main() {

    SongNode* playlist = NULL;
    SongNode* nowPlaying = NULL;

    // create the playlist
    std::cout << "Creating playlist..." << std::endl;
    addSong("Bohemian Rhapsody", &playlist);
    addSong("Hotel California", &playlist);
    addSong("Stairway to Heaven", &playlist);
    addSong("Imagine", &playlist);

    nowPlaying = playlist; // start at the first song

    // play all songs
    std::cout << "\nPlaylist (play all):" << std::endl;
    playAll(playlist);

    // add a song
    std::cout << "\nAdding \"Yesterday\" to the playlist..." << std::endl;
    addSong("Yesterday", &playlist);
    std::cout << "Playlist now:" << std::endl;
    playAll(playlist);

    // remove a song
    std::cout << "\nRemoving \"Hotel California\"..." << std::endl;
    removeSong("Hotel California", &playlist);
    std::cout << "Playlist now:" << std::endl;
    playAll(playlist);

    // demonstrate next / previous (circular navigation)
    std::cout << "\nNavigating with next()/previous() from the first track:" << std::endl;
    nowPlaying = playlist;
    std::cout << "  Now playing: " << nowPlaying->title << std::endl;

    nowPlaying = nextSong(nowPlaying);
    std::cout << "  next() -> " << nowPlaying->title << std::endl;

    nowPlaying = nextSong(nowPlaying);
    std::cout << "  next() -> " << nowPlaying->title << std::endl;

    nowPlaying = prevSong(nowPlaying);
    std::cout << "  previous() -> " << nowPlaying->title << std::endl;

    // wrap-around check: go back past the head
    nowPlaying = playlist;
    nowPlaying = prevSong(nowPlaying);
    std::cout << "  previous() from first track (wraps to last) -> "
              << nowPlaying->title << std::endl;

    return 0;
}



