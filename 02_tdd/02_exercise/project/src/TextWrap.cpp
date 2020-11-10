#include "TextWrap.h"

TextWrap::TextWrap(int columns) : columns(columns) {

}
std::string TextWrap::wrap(const std::string& line) const
{
    std::string hLine;
    if(line.size()>1)
    {
        for(int i=0;i<line.size();i+=columns)
        {
           hLine+=(line.substr(i,columns)+"\n");
        }
            hLine.pop_back();
        return hLine;
    }
    return line;
}