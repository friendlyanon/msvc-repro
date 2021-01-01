#include <type_traits>
#include <utility>

template<typename SFINAE, typename Data, typename... PointersToMember>
struct pmd_chain : std::false_type {};

template<typename Data, typename... PointersToMember>
struct pmd_chain<
  std::void_t<decltype(
    (std::declval<Data>().* ... .* std::declval<PointersToMember>())
  )>,
  Data,
  PointersToMember...
> : std::true_type {};

struct B {
  int x;
};

struct A {
  B b;
};

int main() {
  static_assert(pmd_chain<
    void,
    A, // Data
    // PointersToMember...
    decltype(&A::b),
    decltype(&B::x)
  >::value, "Must be a valid pointer to member chain");
  return 0;
}
