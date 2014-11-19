#ifndef _DEBUGUTILS_HPP
#define _DEBUGUTILS_HPP

class DebugUtil {

    DebugUtil() = delete;

public:

    template<typename T>
    static std::string DbgStr(const T& t) {
        std::stringstream ss;
        ss << T::DbgStr(t);
        return ss.str();
    }

    template<typename T>
    static std::string DbgStr(const std::vector<T>& v) {
        std::stringstream ss;
        bool first = true;
        for (const T& t : v) {
            if (first) {
                first = false;
            }
            else {
                ss << ", ";
            }
            ss << DebugUtil::DbgStr(t);
        }
        return ss.str();
    }

};


#endif // _DEBUGUTILS_HPP

