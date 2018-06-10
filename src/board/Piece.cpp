#include "../common/Common.hpp"

#include "Piece.hpp"

Common::Color Piece::GetColor() {
    if (c == '.') return Common::Color::empty;
    if (c >= 'a' && c <= 'z') return Common::Color::black;
    if (c >= 'A' && c <= 'Z') return Common::Color::white;
    return Common::Color::empty;
}
