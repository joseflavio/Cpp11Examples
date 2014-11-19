#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#include <DebugUtil.hpp>

class MyString {

private:
    std::string _str;

public:
    MyString(const MyString&) = delete;

    MyString& operator=(const MyString&) = delete;

    // MyString(MyString&& iStr) = default;
    MyString(MyString&& iStr) : _str(std::move(iStr._str)) {
        std::cout << "moving: " << _str << std::endl;
    }

    MyString(const std::string& iStr) : _str(iStr) {}

    static const std::string& DbgStr(const MyString& iMyString) {
        return iMyString._str;
    }

    static MyString Create(const std::string& iStr) {
        return { iStr };
    }

};

int main() {

    MyString s1 { "blah" };

    std::vector<MyString> v;
    v.reserve(100);
    v.push_back(std::move(s1));
    v.push_back(std::move(s1));
    v.push_back(MyString::Create("toto"));
    v.emplace_back(MyString("blahblah"));

    std::cout << "\nVector v.capacity()=" << v.capacity() << ", contents:" << std::endl;
    std::cout << DebugUtil::DbgStr(v) << std::endl;

    return 0;

}

