#include <string>
#include <vector>

class ProcessRunner {
public:
    virtual ~ProcessRunner() = default;

    virtual int run(const std::string& cmd,
                    const std::vector<std::string>& args) = 0;

    virtual std::string readStdout() = 0;

    virtual std::istream& readPipe() = 0;
};
