#ifndef REGEXP_H_INCLUDED
#define REGEXP_H_INCLUDED

#include <string>

#include "config/regmatch.h"

bool regValid(const std::string &reg);
bool regFind(const std::string &src, const std::string &match);
std::string regReplace(const std::string &src, const std::string &match, const std::string &rep, bool global = true, bool multiline = true);
bool regMatch(const std::string &src, const std::string &match);
int regGetMatch(const std::string &src, const std::string &match, size_t group_count, ...);
std::vector<std::string> regGetAllMatch(const std::string &src, const std::string &match, bool group_only = false);
std::string regTrim(const std::string &src);

bool regFind(const std::string &src, jp::Regex &reg);
std::string regReplace(const std::string &src, jp::Regex &reg, const std::string &rep, bool global = true);
bool regMatch(const std::string &src, jp::Regex &reg);
int regGetMatch(const std::string &src, jp::Regex &reg, size_t group_count, ...);
std::vector<std::string> regGetAllMatch(const std::string &src, jp::Regex &reg, bool group_only = false);

bool regFind(const std::string &src, RegexWrapper &reg_wrapper);
std::string regReplace(const std::string &src, RegexWrapper &reg_wrapper, const std::string &rep, bool global = true, bool multiline = true);
bool regMatch(const std::string &src, RegexWrapper &reg_wrapper);
int regGetMatch(const std::string &src, RegexWrapper &reg_wrapper, size_t group_count, ...);
std::vector<std::string> regGetAllMatch(const std::string &src, RegexWrapper &reg_wrapper, bool group_only = false);

bool regFind(const std::string &src, RegexMatchConfig &config);
std::string regReplace(const std::string &src, RegexMatchConfig &config, bool global = true, bool multiline = true);
bool regMatch(const std::string &src, RegexMatchConfig &config);
int regGetMatch(const std::string &src, RegexMatchConfig &config, size_t group_count, ...);
std::vector<std::string> regGetAllMatch(const std::string &src, RegexMatchConfig &config, bool group_only = false);

#endif // REGEXP_H_INCLUDED
