#pragma once
#include "Shapes.h"

template <class T>
class TContainer
{
  protected:
    TShape** objects;
    int objcnt;
  public:
    TContainer() { objcnt = 0; objects = new TShape*[objcnt]; };
    void AddObject(const TPoint<T>& newpoint) {
      TShape* newobj = 0;
      newobj = new TPoint<T>(newpoint);
      TShape** newobjects = new TShape * [objcnt + 1];
      for (int i = 0; i < objcnt; i++) {
        newobjects[i] = objects[i];
      }
      newobjects[objcnt] = newobj;
      objcnt = objcnt + 1;
      delete[] objects;
      objects = new TShape * [objcnt];
      for (int i = 0; i < objcnt; i++) {
        objects[i] = newobjects[i];
      };
      delete[] newobjects;
    }
    void AddObject(const TMultiPoint<T>& newmulpnt) {
      TShape* newobj = 0;
      newobj = new TMultiPoint<T>(newmulpnt);
      TShape** newobjects = new TShape * [objcnt + 1];
      for (int i = 0; i < objcnt; i++) {
        newobjects[i] = objects[i];
      }
      newobjects[objcnt] = newobj;
      objcnt = objcnt + 1;
      delete[] objects;
      objects = new TShape * [objcnt];
      for (int i = 0; i < objcnt; i++) {
        objects[i] = newobjects[i];
      };
      delete[] newobjects;
    };
    void AddObject(const TLine<T>& newline) {
      TShape* newobj = 0;
      newobj = new TLine<T>(newline);
      TShape** newobjects = new TShape * [objcnt + 1];
      for (int i = 0; i < objcnt; i++) {
        newobjects[i] = objects[i];
      }
      newobjects[objcnt] = newobj;
      objcnt = objcnt + 1;
      delete[] objects;
      objects = new TShape * [objcnt];
      for (int i = 0; i < objcnt; i++) {
        objects[i] = newobjects[i];
      };
      delete[] newobjects;
    };
    void AddObject(const TTriangle<T>& newtri) {
      TShape* newobj = 0;
      newobj = new TTriangle<T>(newtri);
      TShape** newobjects = new TShape * [objcnt + 1];
      for (int i = 0; i < objcnt; i++) {
        newobjects[i] = objects[i];
      }
      newobjects[objcnt] = newobj;
      objcnt = objcnt + 1;
      delete[] objects;
      objects = new TShape * [objcnt];
      for (int i = 0; i < objcnt; i++) {
        objects[i] = newobjects[i];
      };
      delete[] newobjects;
    };
    void AddObject(const TQuadangle<T>& newquad) {
      TShape* newobj = 0;
      newobj = new TQuadangle<T>(newquad);
      TShape** newobjects = new TShape * [objcnt + 1];
      for (int i = 0; i < objcnt; i++) {
        newobjects[i] = objects[i];
      }
      newobjects[objcnt] = newobj;
      objcnt = objcnt + 1;
      delete[] objects;
      objects = new TShape * [objcnt];
      for (int i = 0; i < objcnt; i++) {
        objects[i] = newobjects[i];
      };
      delete[] newobjects;
    };
    void AddObject(const TCircle<T>& newcrc) {
      TShape* newobj = 0;
      newobj = new TCircle<T>(newcrc);
      TShape** newobjects = new TShape * [objcnt + 1];
      for (int i = 0; i < objcnt; i++) {
        newobjects[i] = objects[i];
      }
      newobjects[objcnt] = newobj;
      objcnt = objcnt + 1;
      delete[] objects;
      objects = new TShape * [objcnt];
      for (int i = 0; i < objcnt; i++) {
        objects[i] = newobjects[i];
      };
      delete[] newobjects;
    };
    void AddObject(const TCylinder<T>& newcyl) {
      TShape* newobj = 0;
      newobj = new TCylinder<T>(newcyl);
      TShape** newobjects = new TShape * [objcnt + 1];
      for (int i = 0; i < objcnt; i++) {
        newobjects[i] = objects[i];
      }
      newobjects[objcnt] = newobj;
      objcnt = objcnt + 1;
      delete[] objects;
      objects = new TShape * [objcnt];
      for (int i = 0; i < objcnt; i++) {
        objects[i] = newobjects[i];
      };
      delete[] newobjects;
    };
    void AddObject(const TEllipse<T>& newell) {
      TShape* newobj = 0;
      newobj = new TEllipse<T>(newell);
      TShape** newobjects = new TShape * [objcnt + 1];
      for (int i = 0; i < objcnt; i++) {
        newobjects[i] = objects[i];
      }
      newobjects[objcnt] = newobj;
      objcnt = objcnt + 1;
      delete[] objects;
      objects = new TShape * [objcnt];
      for (int i = 0; i < objcnt; i++) {
        objects[i] = newobjects[i];
      };
      delete[] newobjects;
    };
    void AddObject(const TEllCylinder<T>& newelcyl) {
      TShape* newobj = 0;
      newobj = new TEllCylinder<T>(newelcyl);
      TShape** newobjects = new TShape * [objcnt + 1];
      for (int i = 0; i < objcnt; i++) {
        newobjects[i] = objects[i];
      }
      newobjects[objcnt] = newobj;
      objcnt = objcnt + 1;
      delete[] objects;
      objects = new TShape * [objcnt];
      for (int i = 0; i < objcnt; i++) {
        objects[i] = newobjects[i];
      };
      delete[] newobjects;
    };
    void DeleteObject(int index) {
      if ((index < 0) || (index > objcnt))
      {
        throw "Index out of range";
      }
      TShape** newobjects = new TShape * [objcnt - 1];
      for (int i = 0; i < objcnt; i++) {
        newobjects[i] = objects[i];
      }
      objcnt = objcnt - 1;
      delete[] objects;
      objects = new TShape * [objcnt];
      bool indexmet = false;
      for (int i = 0; i < objcnt; i++)
      {
        if (i == index) { indexmet = true; }
        if (indexmet) { objects[i] = newobjects[i + 1]; }
        else { objects[i] = newobjects[i]; }
      }
      delete[] newobjects;
    };
    void ShowAll() {
      if (objcnt == 0) {
        throw "No objects to show";
      }
      for (int i = 0; i < objcnt; i++) {
        objects[i]->Show();
      }
    };
    void ShowIndex(int index) {
      if ((index < 0) || (index > objcnt)) {
        throw "Index out of range"
      }
      objects[index]->Show();
    }
};