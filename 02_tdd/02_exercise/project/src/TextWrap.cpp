#include "TextWrap.h"

TextWrap::TextWrap(int) {

}
std::string TextWrap::wrap(const std::string& line) const
{
    if(line.size()>1)
    {
        return line.substr(0,1)+'\n'+line.substr(1);
    }
    return line;
}