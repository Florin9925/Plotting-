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


//DEFAULT STEP1

const std::string Data::Defaults::Step1::Xn = "SQRT(n)/(1+SQRT(n))";
const std::string Data::Defaults::Step1::Yn = "SIN(n)/SQRT(1+n)";
const std::string Data::Defaults::Step1::FnX = "(((XN)-(XN-1))*X+b*(XN-1)-a*(XN))/(b-a)";
const std::string Data::Defaults::Step1::FnY = "((YN)-(YN-1)-(DN)*((M)-m))*X/(b-a)+(DN)*Y+(b*(YN-1)-a*(YN)-(DN)*(b*m-a*(M)))/(b-a)";
const std::string Data::Defaults::Step1::a = "0";
const std::string Data::Defaults::Step1::b = "1";
const std::string Data::Defaults::Step1::m = "0";
const std::string Data::Defaults::Step1::M = "0";
const std::string Data::Defaults::Step1::dn = "0.4";

//DEFAULT STEP1 END


//DEFAULT STEP2

const std::string Data::Defaults::Step2::Xn = "(3*n+1)/(n+1)";
const std::string Data::Defaults::Step2::Yn = "SIN(n)/(SQRT(n)+1)+2";
const std::string Data::Defaults::Step2::FnX = "(((XN)-(XN-1))*X+b*(XN-1)-a*(XN))/(b-a)";
const std::string Data::Defaults::Step2::FnY = "(((YN)-(YN-1))/(b-a) -(1/(b-a))*((M)/(1+n*(M))-(m)/(1+n*m)))*X+(Y)/(1+n*Y)+(YN-1)-a*((YN)-(YN-1))/(b-a)+(a*(M))/((b-a)*(1+n*(M)))-b*m/((b-a)*1+n*m)";
const std::string Data::Defaults::Step2::a = "1";
const std::string Data::Defaults::Step2::b = "3";
const std::string Data::Defaults::Step2::m = "2";
const std::string Data::Defaults::Step2::M = "2";
const std::string Data::Defaults::Step2::dn = "";

//DEFAULT STEP2 END
