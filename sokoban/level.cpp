#include <stdexcept>
#include "level.h"


level::level(size_t rows, size_t columns, const char *data)
        : rows(rows), columns(columns), data(rows * columns) {
    if (!data) {
        throw std::invalid_argument("Data pointer is null");
    }

    for (size_t i = 0; i < rows * columns; ++i) {
        this->data[i] = data[i];
        if (data[i] == PLAYER || data[i] == PLAYER_ON_GOAL) {
            entry_row = i / columns;
            entry_column = i % columns;
        }
    }

    if (entry_row == static_cast<size_t>(-1) || entry_column == static_cast<size_t>(-1)) {
        throw std::runtime_error("No player entry point found in the level data");
    }
}
