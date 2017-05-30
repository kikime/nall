#include <cstring>
#include <iostream>

namespace nall
{
  const unsigned int version = 0;

  /**
   * Checks a parameter against a long and a short form
   *
   * @param param the parameter to check
   * @param l     the long form  (without --)
   * @param s     the short form (without -)
   */
  bool paramcheck(const char *param, const char *l, char s)
  {
    if (*param != '-')
      return false;

    ++param;

    if (*param == s)
      return param[1] == '\0';

    if (*param != '-')
      return false;

    ++param;

    return !strcmp(param, l);
  }
}

int main(int argc, char *argv[])
{
  if (argc == 1) {
    std::cout << "nall v" << nall::version << " by Niclas Meyer (@_njdm).\n\n"
      "Try `" << argv[0] << " -h` for help.\n";
    return 0;
  }

  bool sourceSpecified = false;
  // Go over argv
  for (int i = 1; i < argc; ++i) {
    if (nall::paramcheck(argv[i], "help", 'h')) {
      std::cout << "nall v" << nall::version << "\n"
        "\t-h --help       print this dialog\n"
        "\t-v --version    print a short about dialog\n";

      return 0;
    }

    if (nall::paramcheck(argv[i], "version", 'v')) {
      std::cout << "nall v" << nall::version << " by Niclas Meyer (@_njdm)\n\n"
        "nall is a small preprocessor to handle preprocessing.\n"
        "For more info read the README or LICENSE.\n";

      return 0;
    }

    if (!sourceSpecified) {
      sourceSpecified = true;
      // TODO: Remember source
    } else {
      std::cout << "Multiple sources specified. Watch out.\n";
      return -1;
    }
  }

  return 0;
}
