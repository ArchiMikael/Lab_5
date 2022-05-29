#pragma once

template <class T>
T min(T a, T b)
{
  if (a <= b) { return a; }
  else return b;
}

template <class T>
class TVector
{
protected:
  T* data;
  int len;
public:
  TVector();
  TVector(int n);
  TVector(const TVector<T>& p);
  ~TVector();
  TVector<T> operator+(const TVector<T>& p);
  TVector<T> operator-(const TVector<T>& p);
  TVector<T> operator*(const TVector<T>& p);
  TVector<T>& operator=(const TVector<T>& p);
  TVector<T>& operator+=(const TVector<T>& p);
  TVector<T>& operator-=(const TVector<T>& p);
  TVector<T>& operator*=(const TVector<T>& p);
  bool operator==(const TVector<T>& p);
  T& operator[](int i);
  int Getlen();
  void Resize(int _len);
  int Count(T elem);
};

template<class T>
inline TVector<T>::TVector()
{
  data = 0;
  len = 0;
}

template<class T>
inline TVector<T>::TVector(int n)
{
  if (n > 0)
  {
    len = n;
    data = new T[len];
    for (int i = 0; i < len; i++) { data[i] = 0; }
  }
  else throw "Vector init error";
}

template<class T>
inline TVector<T>::TVector(const TVector<T>& p)
{
  len = p.len;
  if (len == 0) { data = 0; }
  else
  {
    data = new T[len];
    for (int i = 0; i < len; i++) data[i] = p.data[i];
  }
}

template<class T>
inline TVector<T>::~TVector()
{
  if (data != 0)
  {
    delete[] data;
    data = 0;
  }
  len = 0;
}

template<class T>
inline TVector<T> TVector<T>::operator+(const TVector<T>& p)
{
  if (len == p.len)
  {
    TVector<T> res = TVector<T>(len);
    for (int i = 0; i < len; i++) res.data[i] = data[i] + p.data[i];
    return res;
  }
  else throw "Vector operation error";
}

template<class T>
inline TVector<T> TVector<T>::operator-(const TVector<T>& p)
{
  if (len == p.len)
  {
    TVector<T> res = TVector<T>(len);
    for (int i = 0; i < len; i++) res.data[i] = data[i] - p.data[i];
    return res;
  }
  else throw "Vector operation error";
}

template<class T>
inline TVector<T> TVector<T>::operator*(const TVector<T>& p)
{
  if (len == p.len)
  {
    TVector<T> res = TVector<T>(len);
    for (int i = 0; i < len; i++) res.data[i] = data[i] * p.data[i];
    return res;
  }
  else throw "Vector operation error";
}

template<class T>
inline TVector<T>& TVector<T>::operator=(const TVector<T>& p)
{
  if (this == &p)
  {
    return *this;
  }
  len = p.len;
  delete[] data;
  if (len == 0) { data = 0; }
  else {
    data = new T[len];
    for (int i = 0; i < len; i++) data[i] = p.data[i];
  }
  return *this;
}

template<class T>
inline TVector<T>& TVector<T>::operator+=(const TVector<T>& p)
{
  if (len == p.len)
  {
    for (int i = 0; i < len; i++) data[i] += p.data[i];
    return *this;
  }
  else throw "Vector operation error";
}

template<class T>
inline TVector<T>& TVector<T>::operator-=(const TVector<T>& p)
{
  if (len == p.len)
  {
    for (int i = 0; i < len; i++) data[i] -= p.data[i];
    return *this;
  }
  else throw "Vector operation error";
}

template<class T>
inline TVector<T>& TVector<T>::operator*=(const TVector<T>& p)
{
  if (len == p.len)
  {
    for (int i = 0; i < len; i++) data[i] *= p.data[i];
    return *this;
  }
  else throw "Vector operation error";
}

template<class T>
inline bool TVector<T>::operator==(const TVector<T>& p)
{
  bool flag = true;
  if (len != p.len) { flag = false; }
  else for (int i = 0; i < len; i++) if (data[i] != p.data[i]) {
    flag = false;
    break;
  }
  return flag;
}

template<class T>
inline T& TVector<T>::operator[](int i)
{
  return data[i];
}

template<class T>
inline int TVector<T>::Getlen()
{
  return len;
}

template<class T>
inline void TVector<T>::Resize(int _len)
{
  if (_len != len && _len > 0)
  {
    T* _data = new T[_len];
    for (int i = 0; i < min(_len, len); i++) _data[i] = data[i];
    delete[] data;
    data = new T[_len];
    for (int i = 0; i < min(_len, len); i++) data[i] = _data[i];
    len = _len;
  }
  else throw "Vector resize error";
}

template<class T>
inline int TVector<T>::Count(T elem)
{
  int count = 0;
  for (int i = 0; i < len; i++) if (data[i] == elem) count++;
  return count;
}