#ifndef PRINTUTIL_HPP_
#define PRINTUTIL_HPP_

#include <stdafx.h>

#define INVOKE_METHOD(VAR) {\
    std::cout << "EXECUTING " << #VAR << std::endl;\
    Timer t0;\
    VAR;\
    Timer t1;\
    std::cout<<std::endl<<"FINISHED EXECUTING - elapsed = "<<Timer::Elapsed(t0,t1)<<std::endl<<std::endl; }

#endif /* PRINTUTIL_HPP_ */
