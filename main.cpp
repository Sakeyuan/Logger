#include <iostream>
#include "logger.h"
using namespace std;
using namespace utility;

int main(){
    Logger::instance()->open("log.txt");
    Logger::instance()->max(200);
    debug("name is %s , age is %d","yuanjiafei",21);
    debug("name is %s , age is %d","yuanjiafei",21);
    info("name is %s , age is %d","yuanjiafei",21);
    warn("name is %s , age is %d","yuanjiafei",21);
    fatal("name is %s , age is %d","yuanjiafei",21);    
    return 0;
}

