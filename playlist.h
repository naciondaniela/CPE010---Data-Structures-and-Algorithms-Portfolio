#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <iostream>
#include <string>

class SongNode {
public:
    std::string title;
    SongNode* next = NULL;
    SongNode* prev = NULL;
};

SongNode* new_SongNode(std::string title) {
    SongNode* newNode = new SongNode;
    newNode->title = title;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void addSong(std::string title, SongNode** head) {

    SongNode* newNode = new_SongNode(title);

    if (*head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        *head = newNode;
        return;
    }

    SongNode* last = (*head)->prev; 
    
    last->next = newNode;
    newNode->prev = last;
    newNode->next = *head;
    (*head)->prev = newNode;
}

void removeSong(std::string title, SongNode** head) {

    if (*head == NULL) {
        std::cout << "Playlist is empty!" << std::endl;
        return;
    }

    SongNode* current = *head;

    do {
        if (current->title == title) {

            if (current->next == current) {
                *head = NULL;
            } else {
                current->prev->next = current->next;
                current->next->prev = current->prev;

                if (current == *head) {
                    *head = current->next;
                }
            }

            delete current;
            std::cout << "Removed \"" << title << "\" from playlist." << std::endl;
            return;
        }

        current = current->next;

    } while (current != *head);

    std::cout << "\"" << title << "\" not found in playlist." << std::endl;
}

void playAll(SongNode* head) {

    if (head == NULL) {
        std::cout << "Playlist is empty!" << std::endl;
        return;
    }

    SongNode* current = head;
    int trackNum = 1;

    do {
        std::cout << "  " << trackNum << ". " << current->title << std::endl;
        current = current->next;
        trackNum++;
    } while (current != head);
}

SongNode* nextSong(SongNode* current) {
    if (current == NULL) return NULL;
    return current->next;
}

SongNode* prevSong(SongNode* current) {
    if (current == NULL) return NULL;
    return current->prev;
}

#endif
