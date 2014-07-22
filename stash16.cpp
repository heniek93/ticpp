// Copyright 2014 heniek
// zadanie16 rozdzial04 tic++
// struktura Stash z danymi vector<char>

#include <iostream>
#include <cassert>
#include "/home/heniek/moje/ticpp/rozdzial04/stash16.h"
using namespace std;

const int increment = 100;

void Stash::initialize(int sz) {
  size = sz;
  quantity = 0;
  //  storage = 0;
  next = 0;
}

int Stash::add(const void* element) {
  //  if (next >= quantity)
  //    inflate(increment);  // Niepotrzebne bo jest na wektorze
  // Kopiowanie elementu paieci,
  // poczawszy od nastepnego wolnego miesjca:
  int startBytes = next * size;
  void* elmt = const_cast<void*>(element);  // rzutowanie nie pomaga
  char* e = reinterpret_cast<char*>(elmt);
  for (int i = 0; i < size; i++) {
    storage[startBytes + i] = e[i];
  }
  next++;
  return (next - 1);  // Numer indeksu
}

void* Stash::fetch(int index) {
  // Sprawdza czy indeks jest prawidlowy
  assert(0 <= index);
  if (index >= next)
    return 0;  // Oznaczenie konca
  // Tworzenie wskaznida do zadanego elementu:
  return &(storage[index * size]);
}

int Stash::count() {
  return next;  // Liczba elementow w Stash
}

void Stash::inflate(int increase) {
  /*
  assert(increase > 0);
  int newQuantity = quantity + increase;
  int newBytes = newQuantity * size;
  int oldBytes = quantity * size;
  char* b = new char[newBytes];
  for (int i = 0; i < oldBytes; i++) {
    b[i] = storage[i];  // Kopiowanie starego obszaru do nowego
  }
  delete []storage;  // Stary obszar pamieci
  storage = b;  // Wskaznik do nowego obszaru
  quantity = newQuantity;
  */
}

void Stash::cleanup() {
  /*
  if (storage != 0) {
    cout << "zwalnianie pamieci" << endl;
    delete []storage;
  }
  */
}
