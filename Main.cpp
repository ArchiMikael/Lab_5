#include "Shapes.h"
#include "Container.h"

int main()
{
  TVector<int> BVect = TVector<int>(3);
  BVect[0] = 2; BVect[1] = -2; BVect[2] = 4;
  TPoint<int> A = TPoint<int>(3);
  TPoint<int> B = TPoint<int>(BVect);
  TPoint<int> C = TPoint<int>(3);
  TPoint<int> D = TPoint<int>(3);
  A[0] = -1; A[1] = -2; A[2] = 3;
  A.Show();
  B.Show();
  C[0] = 3; C[1] = 4; C[2] = -1;
  C.Show();
  D[0] = -6; D[1] = 5; D[2] = 2;
  D.Show();
  TPoint<int>* points = new TPoint<int>[4];
  points[0] = A; points[1] = B; points[2] = C; points[3] = D;
  TMultiPoint<int> ABCD = TMultiPoint<int>(points, 4);
  ABCD.Show();
  TLine<int> AB = TLine<int>(A, B);
  AB.Show();
  TLine<int> CD = TLine<int>(C, D);
  CD.Show();
  TTriangle<int> ABC = TTriangle<int>(A, B, C);
  ABC.Show();
  TQuadangle<int> ABCDq = TQuadangle<int>(A, B, C, D);
  ABCDq.Show();
  TCircle<int> ACrc = TCircle<int>(A, 4);
  ACrc.Show();
  TEllipse<int> BEll = TEllipse<int>(BVect, 4, 2);
  BEll.Show();
  TCylinder<int> ACrcC = TCylinder<int>(A, 4, 8);
  ACrcC.Show();
  TEllCylinder<int> BEllC = TEllCylinder<int>(BVect, 4, 2, 12);
  BEllC.Show();
  std::cout << "--------------------------------------\n";
  TContainer<int> Cont = TContainer<int>();
  Cont.AddObject(A);
  Cont.AddObject(ABCD);
  Cont.AddObject(CD);
  Cont.AddObject(ABC);
  Cont.AddObject(ABCDq);
  Cont.AddObject(ACrc);
  Cont.AddObject(BEll);
  Cont.AddObject(ACrcC);
  Cont.AddObject(BEllC);
  Cont.ShowAll();
  return 0;
}