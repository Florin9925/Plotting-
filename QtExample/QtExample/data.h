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

       class Step1
            {
       public:
                static const std::string Xn;
                static const std::string Yn;
                static const std::string FnX;
                static const std::string FnY;
                static const std::string a;
                static const std::string b;
                static const std::string m;
                static const std::string M;
                static const std::string dn;
            };

     class Step2
          {
         public:
              static const std::string Xn;
              static const std::string Yn;
              static const std::string FnX;
              static const std::string FnY;
              static const std::string a;
              static const std::string b;
              static const std::string m;
              static const std::string M;
              static const std::string dn;
          };
      };
};

