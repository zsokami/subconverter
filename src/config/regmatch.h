#ifndef REGMATCH_H_INCLUDED
#define REGMATCH_H_INCLUDED

#include "def.h"
#include <jpcre2.hpp>
using jp = jpcre2::select<char>;

class RegexWrapper {
private:
    std::optional<jp::Regex> _reg;
    std::optional<jp::Regex> _reg_non_multiline;
    std::optional<jp::Regex> _reg_full_match;
public:
    const std::string pattern;
    RegexWrapper(const std::string &pattern) : pattern(pattern) {}
    const jp::Regex &reg() {
        if (!_reg) {
            _reg = jp::Regex();
            _reg->setPattern(pattern).addModifier("m").addPcre2Option(PCRE2_UTF|PCRE2_ALT_BSUX).compile();
        }
        return *_reg;
    };
    const jp::Regex &reg_non_multiline() {
        if (!_reg_non_multiline) {
            _reg_non_multiline = jp::Regex();
            _reg_non_multiline->setPattern(pattern).addPcre2Option(PCRE2_UTF|PCRE2_ALT_BSUX).compile();
        }
        return *_reg_non_multiline;
    };
    const jp::Regex &reg_full_match() {
        if (!_reg_full_match) {
            _reg_full_match = jp::Regex();
            _reg_full_match->setPattern(pattern).addModifier("m").addPcre2Option(PCRE2_ANCHORED|PCRE2_ENDANCHORED|PCRE2_UTF).compile();
        }
        return *_reg_full_match;
    };
    bool empty() const {
        return pattern.empty();
    }
};

struct RegexMatchConfig
{
    String Match;
    String Replace;
    String Script;

    std::optional<RegexWrapper> target;
    std::optional<RegexWrapper> real_rule;
    RegexWrapper &reg_wrapper() {
        if (!real_rule) {
            real_rule = RegexWrapper(Match);
        }
        return *real_rule;
    }
    bool empty() {
        return reg_wrapper().empty();
    }
};

using RegexMatchConfigs = std::vector<RegexMatchConfig>;

#endif // REGMATCH_H_INCLUDED
