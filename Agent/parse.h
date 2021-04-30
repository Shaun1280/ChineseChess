#include <shlwapi.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>

#include <algorithm>

inline char *strcasestr(const char *sz1, const char *sz2) {
    return StrStrIA(sz1, sz2);
}

inline bool streqv(const char *sz1, const char *sz2) {
    return strncasecmp(sz1, sz2, strlen(sz2)) == 0;
}

inline bool streqvskip(const char *&sz1, const char *sz2) {
    if (strncasecmp(sz1, sz2, strlen(sz2)) == 0) {
        sz1 += strlen(sz2);
        return true;
    } else {
        return false;
    }
}

inline bool streqvskip(char *&sz1, const char *sz2) {
    if (strncasecmp(sz1, sz2, strlen(sz2)) == 0) {
        sz1 += strlen(sz2);
        return true;
    } else {
        return false;
    }
}

inline bool strscanskip(const char *&sz1, const char *sz2) {
    const char *lpsz;
    lpsz = strcasestr(sz1, sz2);
    if (lpsz == NULL) {
        return false;
    } else {
        sz1 = lpsz + strlen(sz2);
        return true;
    }
}

inline bool strscanskip(char *&sz1, const char *sz2) {
    char *lpsz;
    lpsz = strcasestr(sz1, sz2);
    if (lpsz == NULL) {
        return false;
    } else {
        sz1 = lpsz + strlen(sz2);
        return true;
    }
}

inline int str2digit(const char *sz, int nMin, int nMax) {
    int nRet;
    if (sscanf(sz, "%d", &nRet) > 0) {
        return std::min(std::max(nRet, nMin), nMax);
    } else {
        return nMin;
    }
}
