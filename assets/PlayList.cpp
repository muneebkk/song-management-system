// author : Muhammad Muneeb Kamran
// date: 20th september 2024
#include "PlayList.h"

// PlayList method implementations go here

#include "PlayList.h"
#include "Song.h"
#include "iostream"

// default
PlayList::PlayList() {
    head = nullptr; // initializing an empty playlist
    songCount = 0 ;
}

// copy
PlayList::PlayList(const PlayList &pl) {
    head = nullptr;
    songCount = 0;
    PlayListNode *current = pl.head;
    while(current != nullptr) {
        Song newSong = current->song;
        PlayListNode* newNode = new PlayListNode(newSong);
        insert(newNode->song, songCount);
        current = current->next;
    }
}

// destructor
PlayList::~PlayList() {
    PlayListNode* current = head;
    while(current != nullptr) {
        PlayListNode* next = current->next;
        delete current;
        current = next;
    }
}

// overloaded operator
PlayList& PlayList::operator=(const PlayList &pl) {
    if (this == &pl) return *this; // Check for self-assignment

    // Deallocate existing nodes
    if (head != nullptr) {
        PlayListNode* current = head;
        while (current != nullptr) {
            PlayListNode* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = nullptr;
    }

    // Deep copy
    head = nullptr;
    songCount = 0;

    PlayListNode* current = pl.head;
    while (current != nullptr) {
        Song newSong = current->song;
        PlayListNode* newNode = new PlayListNode(newSong);
        insert(newNode->song, songCount);
        current = current->next;
    }

    return *this; // Return reference to the calling object
}


// insert
void PlayList::insert(Song sng, unsigned int pos){
    if (pos > songCount) {
        throw std::out_of_range("Position is out of range");
    }

    PlayListNode * newNode = new PlayListNode(sng);

    if ( pos == 0 ){
        newNode -> next = head; // makes pointer point to head
        head = newNode; // updating head
    }
    else{
        PlayListNode * current = head;
        for(unsigned int i= 0 ; i < pos - 1; i++){
            current = current -> next;
        }
        newNode -> next = current -> next ;
        current -> next = newNode;
    }
    songCount++ ;
}

// remove;
Song PlayList::remove(unsigned int pos) {
    if (pos >= songCount) {
        throw std::out_of_range("Position is out of range");
    }

    if (pos == 0) {
        Song removedSong = head->song;
        PlayListNode* temp = head;
        head = head->next;
        delete temp;
        songCount--;
        return removedSong;
    }

    PlayListNode* current = head;
    for (unsigned int i = 0; i < pos - 1; i++) {
        current = current->next;
    }

    PlayListNode* temp = current->next;
    Song removedSong = temp->song;
    current->next = temp->next;
    delete temp;
    songCount--;

    return removedSong;
}

// swap
void PlayList::swap(unsigned int pos1, unsigned int pos2) {
    if (pos1 == pos2) return;

    PlayListNode* prev1 = nullptr;
    PlayListNode* node1 = head;
    for (unsigned int i = 0; i < pos1; i++) {
        prev1 = node1;
        node1 = node1->next;
    }

    PlayListNode* prev2 = nullptr;
    PlayListNode* node2 = head;
    for (unsigned int i = 0; i < pos2; i++) {
        prev2 = node2;
        node2 = node2->next;
    }

    if (prev1) {
        prev1->next = node2;
    } else {
        head = node2;
    }

    if (prev2) {
        prev2->next = node1;
    } else {
        head = node1;
    }

    PlayListNode* temp = node1->next;
    node1->next = node2->next;
    node2->next = temp;
}

// get
Song PlayList::get(unsigned int pos) const {
    if (pos >= songCount) {
        throw std::out_of_range("Position is out of range");
    }

    PlayListNode* current = head;
    for (unsigned int i = 0; i < pos; i++) {
        current = current->next;
    }
    return current->song;
}


// size
unsigned int PlayList::size() const {
    return songCount;
}





