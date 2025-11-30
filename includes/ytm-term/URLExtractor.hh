#include <string>
#include <vector>


class URLExtractor {
public:
    virtual ~URLExtractor() = default;
    
    virtual std::string extractAudioURL(const std::string& url) = 0;

    virtual std::vector<std::pair<std::string, std::string>> extractPlaylist(const std::string& url) = 0;
};
