#ifndef DYNAMIC_ARRAY
#define DYNAMIC_ARRAY

#include "Song.h"

class DynamicArray
{
  // Descripció: taula de Song en memòria dinàmica ampliable

private:
  static const int RATI; // Rati d'ampliació

  int m_max;   // Capacitat màxima (memòria reservada)
  int m;       // Mida ocupada
  Song *taula; // Taula en memòria dinàmica

  void free();
  // Pre: cert
  // Post: taula=NULL i memòria de taula alliberada

  void copi(const DynamicArray &t);
  // Pre: taula=NULL i memòria de taula alliberada
  // Post: *this és una còpia de t

  void reserve();
  // Pre: cert
  // Post: memòria de taula reservada per a m_max elements a taula

  void expand();
  // Pre: m_max = M_MAX
  // Post: si M_MAX=0, m_max=1 i s'ha reservat la memòria de taula
  //       altrament, m_max = RATI*M_MAX i la memòria de taula s'ha augmentat i reubicat

public:
  // Constructors
  DynamicArray();
  // Pre: cert
  // Post: *this és una taula buida i sense memoria reservada (mida()=capacitat()=0)

  DynamicArray(int n_punts);
  // Pre: cert
  // Post: *this és una amb mida n_punts i amb memòria reservada per n_punts
  //       cadascun dels elements s'ha inicialitzat amb el constructor per defecte de Song

  DynamicArray(const DynamicArray &t);
  // Pre: cert
  // Post: *this és còpia de la taula t

  // Destructor
  ~DynamicArray();
  // Pre: cert
  // Post: memòria de *this alliberada

  // Mètodes consultors
  int size() const;
  // Pre: cert
  // Post: resultat = mida ocupada de *this

  int capacity() const;
  // Pre: cert
  // Post: resultat = espai de memoria reservat de *this

  bool empty() const;
  // Pre: cert
  // Post: resultat = mida()==0

  // Mètodes modificadors
  void add(const Song &p);
  // Pre: mida() = MIDA i capacitat() = CAPACITAT
  // Post: p afegit a la posició mida() de la taula i mida()=MIDA+1
  //       si CAPACITAT=0, capacitat() = 1
  //       altrament, si MIDA=CAPACITAT, capacitat() = 2*CAPACITAT,
  //         i s'ha reubicat la memòria

  // Operadors
  DynamicArray &operator=(const DynamicArray &t);
  // Pre: cert
  // Post: *this és còpia de t i resultat = referència a *this

  Song &operator[](int idx);
  // Pre: idx < mida()
  // Post: resultat = referència l'i-èssim Song

  const Song &operator[](int idx) const;
  // Pre: idx < mida()
  // Post: resultat = referència constant a l'i-èssim Song
};

#endif // TAULA_AMPLIABLE_Song_H
