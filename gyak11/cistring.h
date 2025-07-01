#ifndef CISTRING_H
#define CISTRING_H

#include <string>
#include <vector>
#include <cctype>
#include <type_traits>

// Templált osztály, amely case-insensitive módon működik karakterekkel és stringekkel.
// T lehet char vagy wchar_t is.
template <class T>
class case_insensitive_basic_string
{
    // Belső tároló: a karaktereket itt tároljuk
    std::vector<T> invec;

public:
    // Általánosan használt "nem található" konstans
    static const int npos = -1;

    // Elem hozzáadása: a karaktert kisbetűsítve tároljuk, hogy az összehasonlítás könnyű legyen
    void push_back(const T &c)
    {
        invec.push_back(to_lower(c));
    }

    // A karakter kisbetűs változatát adja vissza.
    // char és wchar_t esetén más függvényt használ.
    static T to_lower(T c)
    {
        if constexpr (std::is_same<T, char>::value)
            return std::tolower(static_cast<unsigned char>(c));
        else if constexpr (std::is_same<T, wchar_t>::value)
            return std::towlower(c);
        else
            return c;
    }

    // Egy karakter keresése az első előfordulás pozíciója alapján, kis/nagybetűt nem megkülönböztetve
    int find(const T &c) const
    {
        T target = to_lower(c);
        for (int i = 0; i < static_cast<int>(invec.size()); ++i)
        {
            if (to_lower(invec[i]) == target)
                return i; // első előfordulás indexe
        }
        return npos;
    }

    // Egy string keresése: megkeressük, hol illeszkedik a string a szekvenciában (case-insensitive módon)
    int find(const std::basic_string<T> &s) const
    {
        int n = static_cast<int>(s.size());
        if (n == 0 || n > static_cast<int>(invec.size()))
            return npos;

        for (int i = 0; i <= static_cast<int>(invec.size()) - n; ++i)
        {
            bool match = true;
            for (int j = 0; j < n; ++j)
            {
                if (to_lower(invec[i + j]) != to_lower(s[j]))
                {
                    match = false;
                    break;
                }
            }
            if (match)
                return i; // megtaláltuk
        }
        return npos;
    }

    // Méret lekérdezése
    int size() const
    {
        return static_cast<int>(invec.size());
    }

    // Indexelő operátor olvasásra és írásra
    T &operator[](int i)
    {
        return invec[i];
    }

    const T &operator[](int i) const
    {
        return invec[i];
    }
};

// Egyszerű alias: csak char típusra specializált változat
using case_insensitive_string = case_insensitive_basic_string<char>;

#endif
