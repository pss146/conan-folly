#include <cstdlib>
#include <iostream>
// #ifdef _WIN32
// #ifndef __MINGW32__
// #define GOOGLE_GLOG_DLL_DECL 
// #endif
// #endif

#include <folly/Format.h>
#include <folly/futures/Future.h>

folly::SemiFuture<int> asyncGet() {
    auto promise = std::make_shared<folly::Promise<int>>();

    promise->setException(std::runtime_error("test excheption"));

    return promise->getSemiFuture();
}

int main()
{
    auto str = folly::format("The answers are {} and {}", 23, 42);
    std::cout << str << std::endl;

    auto s1 = asyncGet();
    try {
        auto res = std::move(s1).get();
        std::cout << "result" << std::endl;
    } catch (...) {
        std::cerr << "exception" << std::endl;
    }

    return EXIT_SUCCESS;
}
