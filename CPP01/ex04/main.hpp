#ifndef MAIN_HPP
#define MAIN_HPP

#include <fstream>
#include <string>
#include <sstream>
#include <iostream>

std::string readFile(const std::string &filename);
std::string replaceString(const std::string &str, const std::string &s1, const std::string &s2);
bool writeFile(const std::string &modifiedContent, const std::string &filename);
void printUsage();


#endif