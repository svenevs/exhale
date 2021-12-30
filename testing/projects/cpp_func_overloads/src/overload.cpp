#include <overload/overload.hpp>

namespace overload {
    int blargh(int x, int y, int z, int w) {
        return x + y + z + w;
    }

    float blargh(float x, float y, float z, float w) {
        return -1.0f * (x + y + z + w);
    }

    std::string blargh(const std::string& x,
                       const std::string& y,
                       const std::string& z,
                       const std::string& w) {
        return x + y + z + w;
    }
}
