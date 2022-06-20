#include <overload/operators.hpp>

namespace overload {
    template <>
    std::ostream &operator<< <std::ostream, CustomType>(std::ostream &out, const CustomType& ct) {
        return out << ct.value();
    }

    bool operator==(const CustomType &lhs, const CustomType &rhs) {
        return lhs.value() == rhs.value();
    }

    bool operator!=(const CustomType &lhs, const CustomType &rhs) {
        return !(lhs == rhs);
    }

    bool operator<(const CustomType &lhs, const CustomType &rhs) {
        return lhs.value() < rhs.value();
    }

    bool operator>(const CustomType &lhs, const CustomType &rhs) {
        return lhs.value() > rhs.value();
    }

    bool operator<=(const CustomType &lhs, const CustomType &rhs) {
        return lhs.value() <= rhs.value();
    }

    bool operator>=(const CustomType &lhs, const CustomType &rhs) {
        return lhs.value() >= rhs.value();
    }
}
