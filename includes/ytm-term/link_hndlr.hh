
#include <string>
class link_handler {

    std::string url;
    std::string format;
    //for future 
    int bitrate;

public:
 explicit link_handler(const std::string& url) : url(url) {}
    virtual ~link_handler() = default;
    virtual std::string getAudioURL() = 0;
};
