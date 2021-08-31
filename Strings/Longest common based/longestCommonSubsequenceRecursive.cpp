using namespace std;

#include <iostream>
#include <string>

class LCS {
public:
  int findLCSLength(const string &s1, const string &s2) {
    return findLCSLengthRecursive(s1, s2, 0, 0);
  }

private:
  int findLCSLengthRecursive(const string &s1, const string &s2, int i1, int i2) {
    if (i1 == s1.length() || i2 == s2.length()) {
      return 0;
    }

    if (s1[i1] == s2[i2]) {
      return 1 + findLCSLengthRecursive(s1, s2, i1 + 1, i2 + 1);
    }
    int c1 = findLCSLengthRecursive(s1, s2, i1, i2 + 1);
    int c2 = findLCSLengthRecursive(s1, s2, i1 + 1, i2);
    return max(c1, c2);
  }
};

int main(int argc, char *argv[]) {
  LCS *lcs = new LCS();
  cout << lcs->findLCSLength("abdca", "cbda") << endl;
  cout << lcs->findLCSLength("passport", "ppsspt") << endl;

  delete lcs;
}