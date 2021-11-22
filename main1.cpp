/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby,
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

#include <iostream>

#include <vector>

using namespace std;

vector < vector < int >> SearchInMatrix(int ** * mtrx, int l, int m, int n, int z) {
  vector < vector < int >> v;
  vector < int > v1;
  for (int i = 0; i < l; ++i) {
    for (int j = 0; j < m; ++j) {
      for (int k = 0; k < n; ++k) {
        if (mtrx[i][j][k] == z) {
          v1.clear();
          v1.push_back(i);
          v1.push_back(j);
          v1.push_back(k);
          v.push_back(v1);
        }
      }
    }
  }
  return v;
}

int main() {
  int l, m, n;
  int z;
  int ** * mtrx;
  vector < vector < int >> v;

  cout << "l=";
  cin >> l;
  cout << "m=";
  cin >> m;
  cout << "n=";
  cin >> n;
  cout << "z=";
  cin >> z;
  mtrx = new int ** [l];

  for (int i = 0; i < l; i++) {
    mtrx[i] = new int * [m];
    for (int j = 0; j < m; j++) {
      mtrx[i][j] = new int[n];
    }
  }

  srand(time(0));
  for (int i = 0; i < l; ++i) {
    cout << "Matrix " << i + 1 << '\n';
    for (int j = 0; j < m; ++j) {
      for (int k = 0; k < n; ++k) {
        mtrx[i][j][k] = rand() % 10;
        cout << mtrx[i][j][k] << ' ';
      }
      cout << '\n';
    }
    cout << "\n";
  }

  v = SearchInMatrix(mtrx, l, m, n, z);
  for (auto & i: v) {
    for (auto & j: i)
      cout << j << " ";
    cout << endl;
  }

  for (int i = 0; i < l; ++i) {
    for (int j = 0; j < m; ++j) {
      delete[] mtrx[i][j];
    }
    delete[] mtrx[i];
  }
  delete[] mtrx;

  return 0;
}
