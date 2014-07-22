// Copyright 2014 heniek
// zadanie16 rozdzial04 tic++
// struktura Stash z danymi vector<char>

#ifndef _HOME_HENIEK_MOJE_TICPP_ROZDZIAL04_STASH16_H_
#define _HOME_HENIEK_MOJE_TICPP_ROZDZIAL04_STASH16_H_
#include <vector>
struct Stash {
  int size;
  int quantity;
  int next;
  std::vector<char> storage;
// Funkcje
  void initialize(int size);
  void cleanup();
  int add(const void* element);
  void* fetch(int index);
  int count();
  void inflate(int increase);
};
#endif  // _HOME_HENIEK_MOJE_TICPP_ROZDZIAL04_STASH16_H_
