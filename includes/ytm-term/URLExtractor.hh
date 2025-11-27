#include <string>
#include <vector>
#include <array>

class URLExtractor {
public:
    virtual ~URLExtractor() = default;

    virtual bool validate(const std::string& url) const = 0;

    virtual std::string extractAudio(const std::string& url) = 0;

    virtual std::vector<std::array<std::string, 3>>
    extractPlaylist(const std::string& playlistURL) = 0;
    
    virtual bool isPlaylist(const std::string url) = 0;


};
