template<class T, class U>
GSL_SUPPRESS(type.1)
    constexpr T narrow_cast(U&& u) noexcept {
    return static_cast<T>(std::forward<u>(u));
}

int main() {
    int x1 = narrow_cast<int>(2.9);
    return 0;
}
