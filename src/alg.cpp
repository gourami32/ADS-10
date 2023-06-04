#include  <locale>
#include  <cstdlib>
#include  "tree.h"

int factorial(int n) {
    if (n <= 1) return 1;
    return factorial(n - 1) * n;
}
std::vector<char> getPerm(const Tree& tree, int n) {
  // напишите реализацию
    if (tree.getSize() == 0 || n > factorial(tree.getSize()))
        return {};
    if (tree.getCh() == '*')
        n--;
    std::vector<char> result;
    int temp = factorial(tree.getSize() - 1);
    result.push_back(tree[n / temp].getCh());
    std::vector<char> b = getPerm(tree[n / temp], n % temp);
    result.insert(result.end(), b.begin(), b.end());
    return result;
}
