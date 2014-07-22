// Copyright 2014 heniek
// zadanie16 rozdzial04 tic++
// struktura Stash z danymi vector<char>
// Zmodyfikuj strukturę Stash w taki sposób by jako
// podstawowej struktury danych używała ona typu vector<char>.


#include <iostream>
#include "/home/heniek/moje/ticpp/rozdzial04/stash16.h"
// nie dziala!
int main() {
  Stash newIntStash;
  newIntStash.initialize(sizeof(int));
  for (int i = 0; i < 3; i++) {
    newIntStash.add(&i);
  }
  const int N = newIntStash.count();
  for (int i = 0; i < N; i++) {
    std::cout << *reinterpret_cast<int*>(newIntStash.fetch(i))
              << std::endl;
  }

  return 0;
}
