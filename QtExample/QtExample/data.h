#pragma once

#include <string>

class Data
{
public:
     class Info
        {
        public:
            static const std::string VERSION;
            static const std::string GENERAL_HELP;
        };

     class Errors
        {
        public:
            static const std::string NO_FUNCTION;
            static const std::string INVALID_FUNCTION;
            static const std::string ANOTHER_ERROR;
        };

     class Defaults
        {
        public:
            static const std::string PATH_STEP1;
            static const std::string PATH_STEP2;
            static const std::string PATH_DEFAULT;
        };

};

