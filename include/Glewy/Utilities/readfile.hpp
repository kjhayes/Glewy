#ifndef GLEWY_READFILE_HPP
#define GLEWY_READFILE_HPP

#include<string>
#include<vector>

namespace gly
{
	
int ReadFile(const char* file_name, std::string& out);
int ReadFile(const char* file_name, std::vector<unsigned char>& out);

}

#endif // READFILE_HPP
