#include <iostream>
#include "TextWrap.h"

TextWrap::TextWrap(int columns) : columns(columns) {

}
std::string TextWrap::wrap(const std::string& line) const {
    std::string hLine=line;
    if(line.size()>columns)
    {
        int readChars=0;
        while(readChars<line.size())
        {
            std::string hhLine=line.substr(readChars,columns);
            readChars+=hhLine.size();
            if( hhLine.size()==columns )
            {
                if(line[readChars]==' ')
                {
                    hLine[readChars]='\n';
                    readChars++;
                }
                else if(line[readChars]!='\0')
                {
                    int lastSpacePos=hhLine.find_last_of(' ');
                    if(lastSpacePos!=-1)
                    {
                        hLine[readChars-hhLine.size()+lastSpacePos]='\n';
                        readChars-=(hhLine.size()-lastSpacePos-1);
                    }else{
                       hLine.insert(readChars,1,'\n');

                    }
                }
            }
        }
        return hLine;
    }
    return line;
}
/*
 *
 *
 *            if (line.size() > 1) {
                for (int i = 0; i < line.size(); i += columns)
                {
                    std::string hhLine = line.substr(i, columns);
                    hLine += (hhLine + "\n");
                }
            hLine.pop_back();
            return hLine;
 *
 */