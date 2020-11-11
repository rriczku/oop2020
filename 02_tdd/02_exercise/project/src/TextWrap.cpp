#include <iostream>
#include "TextWrap.h"

TextWrap::TextWrap(int columns) : columns(columns) {

}
std::string TextWrap::wrap(const std::string& line) const {
    std::string hLine;
    if(line.size()>1)
    {
        for(int i=0;i<line.size();i+=columns)
        {
            std::string hhLine=line.substr(i,columns);

            if(hhLine.size()==columns)
            {
                if(line[i+columns]!=' '&&line[i+columns]!='\0')
                {
                    int spacePos=hhLine.find_last_of(' ');
                    if(spacePos!=-1)
                        hhLine.replace(spacePos,1,"\n");
                    else hhLine = (hhLine.substr(i,columns)+"\n");
                }
            }
            hLine+=hhLine;
        }
        //hLine.pop_back();
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