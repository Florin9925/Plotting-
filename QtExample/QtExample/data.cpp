#include "data.h"


//INFOS:
const std::string Data::Info::VERSION = "0.0.1a";

const std::string Data::Info::GENERAL_HELP =

"Plotting"
" [Version " + Data::Info::VERSION + "]\n\n"

"You can contact us here:\n"
"Calavie Adrian		-->		adrian.calavie06@gmail.com\n"
"Arhip Florin		-->		florin9925@gmail.com\n"
"Dinu Alin		-->		dinui.alin@gmail.com\n";

//INFO ENDS



//ERRORS
const std::string Data::Errors::NO_FUNCTION = "Insert function!";
const std::string Data::Errors::INVALID_FUNCTION = "Invalid function format!";
const std::string Data::Errors::ANOTHER_ERROR = "Unknown error! Please contact the administrator.";
//ERRORS END



//DEFAULTS
#ifdef _DEBUG
const std::string Data::Defaults::PATH_DEFAULT = "..//.//QtExample\\Default\\";
const std::string Data::Defaults::PATH_STEP1 = "..//.//QtExample\\Step1\\";
const std::string Data::Defaults::PATH_STEP2 = "..//.//QtExample\\Step2\\";
#else
const std::string Data::Defaults::PATH_DEFAULT = "Resources\\Default\\";
const std::string Data::Defaults::PATH_STEP1 = "Resources\\Step1\\";
const std::string Data::Defaults::PATH_STEP2 = "Resources\\Step2\\";
#endif
//DEFAULTS END
