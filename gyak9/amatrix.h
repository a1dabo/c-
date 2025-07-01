#ifndef AMATRIX_H
#define AMATRIX_H

#include <map>
#include <algorithm>

template <class Row, class Col, class Mark>
class AssocMatrix
{
    typedef std::map<Row, std::map<Col, Mark>> mmap;
    mmap dmap;

public:
    void insert(const Row &row, const Col &col, const Mark &mark)
    {
        dmap[row][col] = mark;
    }

    int rows() const
    {
        return dmap.size();
    }

    const Mark &at(const Row &row, const Col &col) const
    {
        return dmap.at(row).at(col);
    }
    Mark &at(const Row &row, const Col &col)
    {
        return dmap.at(row).at(col);
    }
    Mark &operator()(const Row &row, const Col &col)
    {
        return dmap.at(row).at(col);
    }

    const Mark &operator()(const Row &row, const Col &col) const
    {
        return dmap.at(row).at(col);
    }

    int cols() const
    {
        int sum = 0;
        for (const auto &row : dmap)
        {
            sum += row.second.size();
        }
        return sum;
    }

    typename mmap::const_iterator begin() const { return dmap.begin(); }
    typename mmap::const_iterator end() const { return dmap.end(); }
};

#endif