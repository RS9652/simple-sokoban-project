#include "level.h"


level::level(size_t rows, size_t columns, const char *data): rows{rows}, columns{columns}, data{*data}
{
    entry_column = 13;
    entry_row = 9;
}

level::~level() = default;