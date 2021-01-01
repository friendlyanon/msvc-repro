template<typename T>
struct test {
  template<auto T::*Member>
  constexpr int member() {
    return 0;
  }
};

struct A {
  int x;
};

constexpr auto get_value() {
  test<A> t;
  t.member<&A::x>();
  return t;
}

int main() {
  auto result = get_value();
  return 0;
}
