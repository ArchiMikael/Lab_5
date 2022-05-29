#pragma once
#include "TVector.h"
#include <iostream>

using namespace std;

class TShape
{
  protected:
    bool vis = true;
  public:
    virtual void Show() = 0;
};

template <class T>
class TPoint : public TShape
{
  protected:
    TVector<T> pos;
  public:
    TPoint() { pos = TVector<T>(1); };
    TPoint(int dim) { if (dim > 0) { pos = TVector<T>(dim); } else throw "TPoint init exception"; };
    TPoint(const TVector<T>& p) { pos = TVector<T>(p); };
    TPoint(const TPoint<T>& p) { this->vis = p.vis; pos = TVector<T>(p.pos); };
    ~TPoint() { pos.~TVector(); };
    virtual void Show() { 
      cout << ((this -> vis) ? "Visible" : "Invisible");
      cout << " point at (";
      for (int i = 0; i < pos.Getlen(); i++) {
        cout << pos[i] << (i == pos.Getlen() - 1 ? ")": "; ");
      }
      cout << "\n";
    };
    TPoint<T>& operator=(const TPoint<T>& p)
    {
      if (this == &p)
      {
        return *this;
      }
      this->vis = p.vis;
      pos = TVector<T>(p.pos);
      return *this;
    };
    TPoint<T>& operator=(const TVector<T>& p)
    {
      pos = TVector<T>(p);
      return *this;
    };
    T& operator[](int i) { if (i < pos.Getlen()) { return pos[i]; } else throw "Index out of range"; };
    void SetVisible(bool _vis) { vis = _vis; };
    bool GetVisible() { return vis; };
    int GetDim() { return pos.Getlen(); };
};

template <class T>
class TMultiPoint : public TShape
{
  protected:
    TPoint<T>* points;
    int ptscnt;
  public:
    TMultiPoint() { points = 0; ptscnt = 0; };
    TMultiPoint(const TVector<T>* p, int ptscnt) {
      points = new TPoint<T>[ptscnt];
      for (int i = 0; i < ptscnt; i++) {
        points[i] = p[i];
      };
    };
    TMultiPoint(const TPoint<T>* p, int _ptscnt) {
      points = new TPoint<T>[_ptscnt];
      for (int i = 0; i < _ptscnt; i++) {
        points[i] = p[i];
      };
      ptscnt = _ptscnt;
    };
    TMultiPoint(const TMultiPoint<T>& p) {
      ptscnt = p.ptscnt;
      delete[] points;
      points = new TPoint<T>[ptscnt];
      for (int i = 0; i < ptscnt; i++)
      {
        points[i] = p.points[i];
      };
    };
    ~TMultiPoint() {
      if (this->points != 0) {
        delete[] this->points;
        this->points = 0;
        this->ptscnt = 0;
      };
    };
    virtual void Show()
    {
      cout << ((this->vis) ? "Visible" : "Invisible");
      cout << " multipoint (" << ptscnt << "), points: (";
      for (int i = 0; i < ptscnt; i++)
      {
        for (int j = 0; j < points[i].GetDim(); j++) {
          cout << points[i][j] << (j == points[0].GetDim() - 1 ? ")" : "; ");
        };
        cout << (i == ptscnt - 1 ? "\n" : " (");
      };
    };
    T& operator[](int i) { if (i < ptscnt) { return points[i]; } else throw "Index out of range"; };
    void SetVisible(bool _vis) { this->vis = _vis; };
    bool GetVisible() { return (this->vis); };
    int GetPointsCount() { return ptscnt; };
};

template <class T>
class TLine : public TMultiPoint<T>
{
  public:
    TLine() { this->points = 0; this->ptscnt = 0; };
    TLine(int dim) {
      this->ptscnt = 2;
      this->points = new TPoint<T>[this->ptscnt];
      this->points[0] = TPoint<T>(dim);
      this->points[1] = TPoint<T>(dim);
    };
    TLine(const TVector<T>& p1, const TVector<T>* p2) {
      this->ptscnt = 2;
      this->points = new TPoint<T>[this->ptscnt];
      this->points[0] = p1;
      this->points[1] = p2;
    };
    TLine(const TPoint<T>& p1, const TPoint<T>& p2) {
      this->ptscnt = 2;
      this->points = new TPoint<T>[this->ptscnt];
      this->points[0] = p1;
      this->points[1] = p2;
    };
    TLine(const TLine<T>& p) {
      this->ptscnt = 2;
      this->points = new TPoint<T>[this->ptscnt];
      this->points[0] = p.points[0];
      this->points[1] = p.points[1];
    };
    virtual void Show()
    {
      cout << ((this->vis) ? "Visible" : "Invisible");
      cout << " line, points: (";
      for (int i = 0; i < this->points[0].GetDim(); i++) {
        cout << this->points[0][i] << (i == this->points[0].GetDim() - 1 ? ")" : "; ");
      };
      cout << " (";
      for (int i = 0; i < this->points[1].GetDim(); i++) {
        cout << this->points[1][i] << (i == this->points[1].GetDim() - 1 ? ")" : "; ");
      };
      cout << "\n";
    };
    T& operator[](int i) { if (i < this->ptscnt) { return this->points[i]; } else throw "Index out of range"; };
    void SetVisible(bool _vis) { this->vis = _vis; };
    bool GetVisible() { return (this->vis); };
    int GetPointsCount() { return this->ptscnt; };
};

template <class T>
class TTriangle : public TMultiPoint<T>
{
  public:
    TTriangle() { this->points = 0; this->ptscnt = 0; };
    TTriangle(int dim) {
      this->ptscnt = 3;
      this->points = new TPoint<T>[this->ptscnt];
      this->points[0] = TPoint<T>(dim);
      this->points[1] = TPoint<T>(dim);
      this->points[2] = TPoint<T>(dim);
    };
    TTriangle(const TVector<T>& p1, const TVector<T>* p2, const TVector<T>* p3) {
      this->ptscnt = 3;
      this->points = new TPoint<T>[this->ptscnt];
      this->points[0] = p1;
      this->points[1] = p2;
      this->points[2] = p3;
    };
    TTriangle(const TPoint<T>& p1, const TPoint<T>& p2, const TPoint<T>& p3) {
      this->ptscnt = 3;
      this->points = new TPoint<T>[this->ptscnt];
      this->points[0] = p1;
      this->points[1] = p2;
      this->points[2] = p3;
    };
    TTriangle(const TTriangle<T>& p) {
      this->ptscnt = 3;
      this->points = new TPoint<T>[this->ptscnt];
      this->points[0] = p.points[0];
      this->points[1] = p.points[1];
      this->points[2] = p.points[2];
    };
    virtual void Show()
    {
      cout << ((this->vis) ? "Visible" : "Invisible");
      cout << " triangle, points: (";
      for (int i = 0; i < this->points[0].GetDim(); i++) {
        cout << this->points[0][i] << (i == this->points[0].GetDim() - 1 ? ")" : "; ");
      };
      cout << " (";
      for (int i = 0; i < this->points[1].GetDim(); i++) {
        cout << this->points[1][i] << (i == this->points[1].GetDim() - 1 ? ")" : "; ");
      };
      cout << " (";
      for (int i = 0; i < this->points[2].GetDim(); i++) {
        cout << this->points[2][i] << (i == this->points[2].GetDim() - 1 ? ")" : "; ");
      };
      cout << "\n";
    };
    T& operator[](int i) { if (i < this->ptscnt) { return this->points[i]; } else throw "Index out of range"; };
    void SetVisible(bool _vis) { this->vis = _vis; };
    bool GetVisible() { return (this->vis); };
    int GetPointsCount() { return this->ptscnt; };
};

template <class T>
class TQuadangle : public TMultiPoint<T>
{
  public:
    TQuadangle() { this->points = 0; this->ptscnt = 0; };
    TQuadangle(int dim) {
      this->ptscnt = 4;
      this->points = new TPoint<T>[this->ptscnt];
      this->points[0] = TPoint<T>(dim);
      this->points[1] = TPoint<T>(dim);
      this->points[2] = TPoint<T>(dim);
      this->points[3] = TPoint<T>(dim);
    };
    TQuadangle(const TVector<T>& p1, const TVector<T>* p2, const TVector<T>* p3, const TVector<T>* p4) {
      this->ptscnt = 4;
      this->points = new TPoint<T>[this->ptscnt];
      this->points[0] = p1;
      this->points[1] = p2;
      this->points[2] = p3;
      this->points[3] = p4;
    };
    TQuadangle(const TPoint<T>& p1, const TPoint<T>& p2, const TPoint<T>& p3, const TPoint<T>& p4) {
      this->ptscnt = 4;
      this->points = new TPoint<T>[this->ptscnt];
      this->points[0] = p1;
      this->points[1] = p2;
      this->points[2] = p3;
      this->points[3] = p4;
    };
    TQuadangle(const TQuadangle<T>& p) {
      this->ptscnt = 4;
      this->points = new TPoint<T>[this->ptscnt];
      this->points[0] = p.points[0];
      this->points[1] = p.points[1];
      this->points[2] = p.points[2];
      this->points[3] = p.points[2];
    };
    virtual void Show()
    {
      cout << ((this->vis) ? "Visible" : "Invisible");
      cout << " quadangle, points: (";
      for (int i = 0; i < this->points[0].GetDim(); i++) {
        cout << this->points[0][i] << (i == this->points[0].GetDim() - 1 ? ")" : "; ");
      };
      cout << " (";
      for (int i = 0; i < this->points[1].GetDim(); i++) {
        cout << this->points[1][i] << (i == this->points[1].GetDim() - 1 ? ")" : "; ");
      };
      cout << " (";
      for (int i = 0; i < this->points[2].GetDim(); i++) {
        cout << this->points[2][i] << (i == this->points[2].GetDim() - 1 ? ")" : "; ");
      };
      cout << " (";
      for (int i = 0; i < this->points[3].GetDim(); i++) {
        cout << this->points[3][i] << (i == this->points[3].GetDim() - 1 ? ")" : "; ");
      };
      cout << "\n";
    };
    T& operator[](int i) { if (i < this->ptscnt) { return this->points[i]; } else throw "Index out of range"; };
    void SetVisible(bool _vis) { this->vis = _vis; };
    bool GetVisible() { return (this->vis); };
    int GetPointsCount() { return this->ptscnt; };
};

template <class T>
class TCircle : public TShape
{
  protected:
    TPoint<T> cen;
    T radmax;
  public:
    TCircle() { cen = TPoint<T>(2); radmax = 0; };
    TCircle(int dim, T _rad) { cen = TPoint<T>(dim); radmax = _rad; };
    TCircle(const TVector<T>& p, T _rad) { cen = p; radmax = _rad; };
    TCircle(const TPoint<T>& p, T _rad) { cen = p; radmax = _rad; };
    TCircle(const TCircle<T>& p) { cen = p.cen; radmax = p.radmax; };
    ~TCircle() { cen.~TPoint(); radmax = 0; };
    virtual void Show() {
      cout << ((this->vis) ? "Visible" : "Invisible");
      cout << " circle, radius = " << radmax << ", center: (";
      for (int i = 0; i < cen.GetDim(); i++) {
        cout << cen[i] << (i == cen.GetDim() - 1 ? ")" : "; ");
      }
      cout << "\n";
    };
    T& operator[](int i) { if (i < cen.GetDim()) { return cen[i]; } else throw "Index out of range"; };
    void SetVisible(bool _vis) { this->vis = _vis; };
    bool GetVisible() { return (this->vis); };
};

template <class T>
class TCylinder : public TCircle<T>
{
  protected:
    T height;
  public:
    TCylinder() { this->cen = 0; this->radmax = 0; height = 0; };
    TCylinder(int dim, T _rad, T _h) { this->cen = TPoint<T>(dim); this->radmax = _rad; height = _h; };
    TCylinder(const TVector<T>& p, T _rad, T _h) { this->cen = p; this->radmax = _rad; height = _h; };
    TCylinder(const TPoint<T>& p, T _rad, T _h) { this->cen = p; this->radmax = _rad; height = _h; };
    TCylinder(const TCylinder<T>& p) { this->cen = p.cen; this->radmax = p.radmax; height = p.height; };
    ~TCylinder() { this->cen.~TPoint(); this->radmax = 0; height = 0; };
    virtual void Show() {
      cout << ((this->vis) ? "Visible" : "Invisible");
      cout << " cylinder, radius = " << this->radmax << ", height = " << height << ", center: (";
      for (int i = 0; i < this->cen.GetDim(); i++) {
        cout << this->cen[i] << (i == this->cen.GetDim() - 1 ? ")" : "; ");
      }
      cout << "\n";
    };
    T& operator[](int i) { if (i < this->cen.GetDim()) { return this->cen[i]; } else throw "Index out of range"; };
    void SetVisible(bool _vis) { this->vis = _vis; };
    bool GetVisible() { return (this->vis); };
};

template <class T>
class TEllipse : public TCircle<T>
{
  protected:
    T radmin;
  public:
    TEllipse() { this->cen = TPoint<T>(2); this->radmax = 0; radmin = 0; };
    TEllipse(int dim, T _radmax, T _radmin) { this->cen = TPoint<int>; this->radmax = _radmax; radmin = _radmin; };
    TEllipse(const TVector<T>& p, T _radmax, T _radmin) { this->cen = p; this->radmax = _radmax; radmin = _radmin; };
    TEllipse(const TPoint<T>& p, T _radmax, T _radmin) { this->cen = p; this->radmax = _radmax; radmin = _radmin; };
    TEllipse(const TEllipse<T>& p) { this->cen = p.cen; this->radmax = p.radmax; radmin = p.radmin; };
    ~TEllipse() { this->cen.~TPoint(); this->radmax = 0; radmin = 0; };
    virtual void Show() {
      cout << ((this->vis) ? "Visible" : "Invisible");
      cout << " ellipse, semi-major = " << this->radmax << ", semi-minor = " << radmin << ", center: (";
      for (int i = 0; i < this->cen.GetDim(); i++) {
        cout << this->cen[i] << (i == this->cen.GetDim() - 1 ? ")" : "; ");
      }
      cout << "\n";
    };
    T& operator[](int i) { if (i < this->cen.GetDim()) { return this->cen[i]; } else throw "Index out of range"; };
    void SetVisible(bool _vis) { this->vis = _vis; };
    bool GetVisible() { return (this->vis); };
};

template <class T>
class TEllCylinder : public TEllipse<T>
{
  protected:
    T height;
  public:
    TEllCylinder() { this->cen = 0; this->radmax = 0; this->radmin = 0; height = 0; };
    TEllCylinder(int dim, T _radmax, T _radmin, T _h) { this->cen = TPoint<T>(dim); this->radmax = _radmax; this->radmin = _radmin; height = _h; };
    TEllCylinder(const TVector<T>& p, T _radmax, T _radmin, T _h) { this->cen = p; this->radmax = _radmax; this->radmin = _radmin; height = _h; };
    TEllCylinder(const TPoint<T>& p, T _radmax, T _radmin, T _h) { this->cen = p; this->radmax = _radmax; this->radmin = _radmin; height = _h; };
    TEllCylinder(const TEllCylinder<T>& p) { this->cen = p.cen; this->radmax = p.radmax; this->radmin = p.radmin; height = p.height; };
    ~TEllCylinder() { this->cen.~TPoint(); this->radmax = 0; this->radmin = 0; height = 0; };
    virtual void Show() {
      cout << ((this->vis) ? "Visible" : "Invisible");
      cout << " cylinder on ellipse, semi-major = " << this->radmax << ", semi-minor = " << this->radmin << ", height = " << height << ", center: (";
      for (int i = 0; i < this->cen.GetDim(); i++) {
        cout << this->cen[i] << (i == this->cen.GetDim() - 1 ? ")" : "; ");
      }
      cout << "\n";
    };
    T& operator[](int i) { if (i < this->cen.GetDim()) { return this->cen[i]; } else throw "Index out of range"; };
    void SetVisible(bool _vis) { this->vis = _vis; };
    bool GetVisible() { return (this->vis); };
};